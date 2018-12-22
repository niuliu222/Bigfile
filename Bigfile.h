#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
namespace LLD {
	namespace Bigfile {

		const char * HANDLE_SPLITTER = "*";

		std::string GetFileAllData(const std::string & file);//read to EOF
		
		class BFHandle {
		public:
			std::string FileName;
			std::string BFName;
			unsigned int StartPos;
			unsigned int Lenth;

			static std::shared_ptr<BFHandle> ParseHandle(const std::string & line, const std::string & bfName);//line(in .idx file) to handle

		};

		class Bigfile {
		private:
			std::vector<std::shared_ptr<BFHandle>> Handles;
			std::string BFName;
			std::ifstream _DataFile;
			bool _vaild;
		public:
			~Bigfile();//for close stream

			static std::shared_ptr<Bigfile> Parse(const std::string & file, const std::string baseUrl);//read file data, parse .idx file, fopen .dat file 

			bool Contains(const std::string & file) {
				auto it = Handles.cbegin();
				for (; it != Handles.cend(); ++it) {
					if ((*it)->FileName == file) {
						return true;
					}
				}
				return false;
			}
			std::string GetDataByFileName(const std::string & filename) {
				auto it = Handles.begin();
				for (; it != Handles.end(); ++it) {
					if ((*it)->FileName == filename) {
						return ReadFile((*it)->StartPos, (*it)->Lenth);
					}
				}
			}
		private:
			void ParseHandle(const std::string & all_data);//parse .idx file
			void ParseLine(const std::string & line);//parse each line in .idx file

			std::string ReadFile(unsigned int Pos, int Lenth) {
				_DataFile.seekg(Pos, std::ios::beg);

				char * ptr = new char[Lenth + 1];
				_DataFile.read(ptr, Lenth);
				ptr[Lenth] = '\0';
				std::string str = ptr;
				delete ptr;

				return str;
			}
		};

		class Database {
		public:
			std::string DatabaseUrl;
			std::string DatabaseFileName = "Database";
			std::vector<std::shared_ptr<Bigfile>> Bigfiles;

		public:
			static std::shared_ptr<Database> DatabaseSetup(const std::string & url);
			void ParseDatabase();

			std::string GetFile(const std::string & fileName) {
				auto it = Bigfiles.begin();
				for (; it != Bigfiles.end(); ++it) {
					if ((*it)->Contains(fileName)) {
						return (*it)->GetDataByFileName(fileName);
					}
				}
			}
		};

		std::shared_ptr<Database> Database::DatabaseSetup(const std::string & url) {
			std::shared_ptr<Database> database = std::make_shared<Database>();
			database->DatabaseUrl = url;

			database->ParseDatabase();

			return database;
		}
		void Database::ParseDatabase() {
			std::string database = DatabaseUrl + "/" + DatabaseFileName;
			std::string all_data = GetFileAllData(database);

			int index = all_data.find('\n');
			int curr_index = 0;
			while (index > -1) {
				auto str = all_data.substr(curr_index, index - curr_index);
				auto bigfile = Bigfile::Parse(str, DatabaseUrl);
				Bigfiles.push_back(bigfile);

				curr_index = index + 1;
				index = all_data.find('\n', curr_index);
			}

			if (curr_index < all_data.length()) {
				auto str = all_data.substr(curr_index);
				auto bigfile = Bigfile::Parse(str, DatabaseUrl);
				Bigfiles.push_back(bigfile);
			}
		}
		std::shared_ptr<BFHandle> BFHandle::ParseHandle(const std::string & line, const std::string & bfName) {
			std::shared_ptr<BFHandle> handle = std::make_shared<BFHandle>();

			int index = line.find(HANDLE_SPLITTER);
			int curr_index = 0;
			handle->FileName = line.substr(curr_index, index);

			//curr_index = index + 1;
			//index = line.find('/', curr_index);
			//handle->BFName = line.substr(curr_index, index);
			handle->BFName = bfName;

			curr_index = index + 1;
			index = line.find(HANDLE_SPLITTER, curr_index);
			handle->StartPos = atoi(line.substr(curr_index, index).c_str());

			curr_index = index + 1;
			handle->Lenth = atoi(line.substr(curr_index).c_str());

			return handle;
		}
		Bigfile::~Bigfile() {
			if (_vaild) {
				_DataFile.close();
			}
		}
		std::shared_ptr<Bigfile> Bigfile::Parse(const std::string & file, const std::string baseUrl) {
			std::shared_ptr<Bigfile> bigfile = std::make_shared<Bigfile>();

			bigfile->BFName = file;
			std::string handle_data = GetFileAllData(baseUrl + "/" + bigfile->BFName + ".idx");
			bigfile->ParseHandle(handle_data);

			std::string datFile = baseUrl + "/" + bigfile->BFName + ".dat";
			bigfile->_DataFile.open(datFile.c_str(), std::ios::in);
			bigfile->_vaild = true;

			return bigfile;
		}
		std::string GetFileAllData(const std::string & file) {
			std::ifstream ifile(file);
			std::stringstream buf;
			buf << ifile.rdbuf();
			return buf.str();
		}

		void Bigfile::ParseHandle(const std::string & data) {
			int index = data.find('\n');
			int curr_index = 0;
			while (index > -1) {
				auto str = data.substr(curr_index, index - curr_index);
				ParseLine(str);

				curr_index = index + 1;
				index = data.find('\n', curr_index);
			}

			if (curr_index < data.length()) {
				auto str = data.substr(curr_index);
				ParseLine(str);
			}
		}
		void Bigfile::ParseLine(const std::string & line) {
			auto handle = BFHandle::ParseHandle(line, this->BFName);
			this->Handles.push_back(handle);
		}
	}
}