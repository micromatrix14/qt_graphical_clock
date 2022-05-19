#include "clock_shape.h"

extern QGraphicsScene* clock_scene;

clock_shape::clock_shape(QObject* parent)
	: QObject(parent), QGraphicsEllipseItem() {
	center = QPointF(250, 250);
}

clock_shape::~clock_shape()
{
}

void clock_shape::add_clock()
{

	//drawing seconds/minutes points on the clock
	for (int i = 0; i < 60; i++) {
		QGraphicsEllipseItem* clock_item = new QGraphicsEllipseItem;
		QPen mypen;
		mypen.setColor(Qt::black);
		mypen.setWidth(2);
		clock_item->setRect(210 * qCos(qDegreesToRadians(i * 360.0 / 60.0 - 90)) + center.x(), 210 * qSin(qDegreesToRadians(i * 360.0 / 60.0 - 90)) + center.y(), 2, 2);
		clock_item->setPen(mypen);
		clock_scene->addItem(clock_item);
	}

	//drawing hours points on the clock
	for (int i = 0; i < 60; i+=5) {
		QGraphicsEllipseItem* clock_item = new QGraphicsEllipseItem;
		QPen mypen;
		mypen.setColor(Qt::red);
		mypen.setWidth(4);
		clock_item->setRect(210 * qCos(qDegreesToRadians(i * 360.0 / 60.0 - 90)) + center.x(), 210 * qSin(qDegreesToRadians(i * 360.0 / 60.0 - 90)) + center.y(), 4, 4);
		clock_item->setPen(mypen);
		clock_scene->addItem(clock_item);
	}

	//drawing text/numbers on the clock
	QFont clock_text_font;
	clock_text_font.setFamily(QString::fromUtf8("Arial"));
	clock_text_font.setPixelSize(16);
	clock_text_font.setWeight(100);
	clock_text_font.setItalic(false);
	for (int num = 1, i = 0; i < 60; i += 5) {
		QGraphicsTextItem* clock_item = new QGraphicsTextItem;
		clock_item->setDefaultTextColor(QColor(Qt::GlobalColor::darkBlue));
		clock_item->setFont(clock_text_font);
		clock_item->setPos(230 * qCos(qDegreesToRadians(i * 360.0 / 60.0 - 60)) + center.x() - 10, 230 * qSin(qDegreesToRadians(i * 360.0 / 60.0 - 60)) + center.y() - 10);
		clock_item->setPlainText(QString::number(num++));
		clock_scene->addItem(clock_item);
	}
	
}
