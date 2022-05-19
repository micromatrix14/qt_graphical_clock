#pragma once
#include <QObject>
#include <qgraphicsitem.h>
#include <qpen.h>
#include <qmath.h>
#include <qgraphicsscene.h>

class clock_shape : public QObject, public QGraphicsEllipseItem
{
	Q_OBJECT

public:
	clock_shape(QObject *parent = nullptr);
	~clock_shape();
	void add_clock();
private:
	QPointF center;

};
