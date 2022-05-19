#pragma once

#include <QObject>
#include<qgraphicsitem.h>
#include <qtimer.h>
#include <qdatetime.h>
#include <qgraphicsscene.h>
#include <qmath.h>
#include <qpoint.h>
#include <qmediaplayer.h>
#include <qurl.h>

class clock_hands : public QObject
{
	Q_OBJECT

public:
	clock_hands(QObject* parent = nullptr);
	~clock_hands();
	void drawing_hands();

private slots:
	void update_clock();

private:
	int hours, minutes, seconds;
	QTimer* timer;
	QTime currenttime;

	QPointF center;
	QGraphicsPolygonItem* hour_polygon;
	QGraphicsPolygonItem* minute_polygon;
	QGraphicsPolygonItem* second_polygon;
	QGraphicsTextItem* time_text;
	QMediaPlayer* player;
	int previous_seconds;
};
