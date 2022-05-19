#include "main_shape.h"

QGraphicsScene* clock_scene;
bool ticksound_enable = true;

main_shape::main_shape(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WidgetAttribute::WA_TranslucentBackground);
    setWindowIcon(QIcon(":/images/icons8_clock.ico"));

    //creating graphics
    clock_scene = new QGraphicsScene;

    //initializing sizes
    clock_scene->setSceneRect(0, 0, 500, 500);

    //initializing viewing scheme
    ui.graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui.graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui.graphicsView->setRenderHint(QPainter::Antialiasing, true);

    //putting background
    ui.graphicsView->setBackgroundBrush(QBrush(QImage(":/images/cloud1.jpg")));

    //creating clock shape
    clock = new clock_shape;
    clock->add_clock();

    //updating clock_heads
    cl_hands = new clock_hands;
    cl_hands->drawing_hands();

    //viewing the scene
    ui.graphicsView->setScene(clock_scene);

    //connecting the checkbox signal
    connect(ui.checkBox, &QCheckBox::stateChanged, this, &main_shape::ticksound_stateChanged);


}

main_shape::~main_shape()
{
    clock->deleteLater();
    delete clock;
    clock = nullptr;
    
    cl_hands->deleteLater();
    delete cl_hands;
    cl_hands = nullptr;

    this->deleteLater();
}


void main_shape::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        mouseispressed = true;
        QPoint pressedglobalpoint = event->globalPos();
        QPoint windowgloballocation = this->mapToGlobal(QPoint(0, 0));
        mouserelativepointonform = pressedglobalpoint - windowgloballocation;
    }
}
// to release the flag of pressed mouse button
void main_shape::mouseReleaseEvent(QMouseEvent* event) {
    mouseispressed = false;
}
// to move the form on the screen
void main_shape::mouseMoveEvent(QMouseEvent* event) {
    if (mouseispressed == true) {
        QPoint newformlocation = event->globalPos();
        newformlocation -= mouserelativepointonform;
        this->move(newformlocation);
    }
}

//to define if the tick sound is enabled or not
void main_shape::ticksound_stateChanged(int state) {
    if (state == Qt::Checked)
        ticksound_enable = true;
    else
        ticksound_enable = false;
}