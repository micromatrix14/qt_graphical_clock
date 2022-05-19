#include <QtWidgets/QApplication>
#include "main_shape.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    
    main_shape* mainshow = new main_shape;
    mainshow->show();
    
    return a.exec();
}
