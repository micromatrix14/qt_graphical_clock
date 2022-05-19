/********************************************************************************
** Form generated from reading UI file 'graphical_clock.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICAL_CLOCK_H
#define UI_GRAPHICAL_CLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphical_clockClass
{
public:

    void setupUi(QWidget *graphical_clockClass)
    {
        if (graphical_clockClass->objectName().isEmpty())
            graphical_clockClass->setObjectName(QString::fromUtf8("graphical_clockClass"));
        graphical_clockClass->resize(600, 400);

        retranslateUi(graphical_clockClass);

        QMetaObject::connectSlotsByName(graphical_clockClass);
    } // setupUi

    void retranslateUi(QWidget *graphical_clockClass)
    {
        graphical_clockClass->setWindowTitle(QApplication::translate("graphical_clockClass", "graphical_clock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphical_clockClass: public Ui_graphical_clockClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICAL_CLOCK_H
