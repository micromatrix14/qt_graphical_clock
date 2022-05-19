/********************************************************************************
** Form generated from reading UI file 'main_shape.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_SHAPE_H
#define UI_MAIN_SHAPE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_shape
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;

    void setupUi(QWidget *main_shape)
    {
        if (main_shape->objectName().isEmpty())
            main_shape->setObjectName(QString::fromUtf8("main_shape"));
        main_shape->resize(560, 560);
        main_shape->setWindowOpacity(0.970000000000000);
        main_shape->setStyleSheet(QString::fromUtf8(""));
        graphicsView = new QGraphicsView(main_shape);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 30, 500, 500));
        graphicsView->setStyleSheet(QString::fromUtf8("#graphicsView{\n"
"border-radius:0px;\n"
"}"));
        label = new QLabel(main_shape);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 560, 560));
        label->setStyleSheet(QString::fromUtf8("#label{\n"
"border-image: url(:/images/cloud3.jpg);\n"
"border-radius:25px;\n"
"}\n"
""));
        pushButton = new QPushButton(main_shape);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 0, 30, 30));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton{\n"
"border-image: url(:/images/icons8_macos_minimize_64px.png);\n"
"background-color: rgb(85, 170, 255);\n"
"border-radius:15px;\n"
"}\n"
"\n"
"#pushButton:hover{\n"
"	background-color: rgb(255, 118, 26);\n"
"}"));
        pushButton_2 = new QPushButton(main_shape);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 0, 30, 30));
        pushButton_2->setStyleSheet(QString::fromUtf8("#pushButton_2{\n"
"	border-image: url(:/images/icons8_cancel_128px.png);\n"
"background-color: rgb(85, 170, 255);\n"
"border-radius:15px;\n"
"}\n"
"\n"
"#pushButton_2:hover{\n"
"	background-color: rgb(255, 0, 0);\n"
"}"));
        checkBox = new QCheckBox(main_shape);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 10, 121, 20));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        checkBox->setPalette(palette);
        checkBox->setLayoutDirection(Qt::RightToLeft);
        checkBox->setStyleSheet(QString::fromUtf8("#checkBox{\n"
"font: bold 13px \"Arial\";\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icons8_speaker_200px.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox->setIcon(icon);
        checkBox->setChecked(true);
        label->raise();
        graphicsView->raise();
        pushButton->raise();
        pushButton_2->raise();
        checkBox->raise();

        retranslateUi(main_shape);
        QObject::connect(pushButton_2, SIGNAL(clicked()), main_shape, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), main_shape, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(main_shape);
    } // setupUi

    void retranslateUi(QWidget *main_shape)
    {
        main_shape->setWindowTitle(QApplication::translate("main_shape", "Graphical Clock", nullptr));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        checkBox->setText(QApplication::translate("main_shape", "Tick Sound", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_shape: public Ui_main_shape {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_SHAPE_H
