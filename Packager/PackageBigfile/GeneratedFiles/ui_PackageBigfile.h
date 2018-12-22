/********************************************************************************
** Form generated from reading UI file 'PackageBigfile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKAGEBIGFILE_H
#define UI_PACKAGEBIGFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PackageBigfileClass
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QWidget *widget_3;
    QGridLayout *gridLayout_7;
    QPushButton *StartPackage;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLineEdit *dir;
    QPushButton *ChooseBaseDir;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLineEdit *dst;
    QPushButton *pushButton_5;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PackageBigfileClass)
    {
        if (PackageBigfileClass->objectName().isEmpty())
            PackageBigfileClass->setObjectName(QString::fromUtf8("PackageBigfileClass"));
        PackageBigfileClass->resize(681, 384);
        gridLayout = new QGridLayout(PackageBigfileClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_2 = new QWidget(PackageBigfileClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_7 = new QGridLayout(widget_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        StartPackage = new QPushButton(widget_3);
        StartPackage->setObjectName(QString::fromUtf8("StartPackage"));

        gridLayout_7->addWidget(StartPackage, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_3, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 0, 1, 1);

        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        dir = new QLineEdit(groupBox);
        dir->setObjectName(QString::fromUtf8("dir"));

        gridLayout_4->addWidget(dir, 0, 0, 1, 1);

        ChooseBaseDir = new QPushButton(groupBox);
        ChooseBaseDir->setObjectName(QString::fromUtf8("ChooseBaseDir"));

        gridLayout_4->addWidget(ChooseBaseDir, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(widget_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        dst = new QLineEdit(groupBox_3);
        dst->setObjectName(QString::fromUtf8("dst"));

        gridLayout_5->addWidget(dst, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout_5->addWidget(pushButton_5, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 1, 0, 1, 1);


        gridLayout->addWidget(widget_2, 0, 1, 1, 1);

        widget = new QWidget(PackageBigfileClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(50, 0));
        widget->setMaximumSize(QSize(150, 16777215));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 2, 1);


        retranslateUi(PackageBigfileClass);
        QObject::connect(ChooseBaseDir, SIGNAL(clicked()), PackageBigfileClass, SLOT(OnChooseBaseDirClick()));
        QObject::connect(StartPackage, SIGNAL(clicked()), PackageBigfileClass, SLOT(OnStartPackage()));

        QMetaObject::connectSlotsByName(PackageBigfileClass);
    } // setupUi

    void retranslateUi(QWidget *PackageBigfileClass)
    {
        PackageBigfileClass->setWindowTitle(QApplication::translate("PackageBigfileClass", "PackageBigfile", nullptr));
        StartPackage->setText(QApplication::translate("PackageBigfileClass", "\345\274\200\345\247\213\346\211\223\345\214\205", nullptr));
        groupBox->setTitle(QApplication::translate("PackageBigfileClass", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        ChooseBaseDir->setText(QApplication::translate("PackageBigfileClass", "...", nullptr));
        groupBox_3->setTitle(QApplication::translate("PackageBigfileClass", "\347\233\256\346\240\207\344\275\215\347\275\256", nullptr));
        pushButton_5->setText(QApplication::translate("PackageBigfileClass", "...", nullptr));
        pushButton_2->setText(QApplication::translate("PackageBigfileClass", "\346\237\245\347\234\213\345\214\205", nullptr));
        pushButton->setText(QApplication::translate("PackageBigfileClass", "\345\216\213\347\274\251\345\214\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PackageBigfileClass: public Ui_PackageBigfileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKAGEBIGFILE_H
