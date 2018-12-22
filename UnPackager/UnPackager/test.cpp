
#include "../../Bigfile.h"
#include <fstream>
using namespace LLD::Bigfile;
int main() {
	auto database = Database::DatabaseSetup("C:\\Users\\lld\\Desktop\\Tmp\\bigfile");

	std::ofstream file;
	file.open("C:\\Users\\lld\\Desktop\\tmp.html", std::ios::out);

	auto str = database->GetFile("blender_python_reference_2_78a_release/idprop.types.html");

	file << str;
	file.close();
	return 0;
}