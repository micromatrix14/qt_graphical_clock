#include "clock_hands.h"

extern QGraphicsScene* clock_scene;
extern bool ticksound_enable;

clock_hands::clock_hands(QObject* parent)
	: QObject(parent)
{
	//timer of updating
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &clock_hands::update_clock);
	timer->start(500);

	//media player for tick sound
	player = new QMediaPlayer;
	player->setMedia(QUrl("qrc:/sounds/tick.wav"));

	//center of the clock
	center = QPointF(250, 250);

	//allocating hands
	hour_polygon = new QGraphicsPolygonItem;
	minute_polygon = new QGraphicsPolygonItem;
	second_polygon = new QGraphicsPolygonItem;
	time_text = new QGraphicsTextItem;

	//intializing second polygons
	QPen seconds_pen;
	seconds_pen.setColor(Qt::red);
	seconds_pen.setWidth(2);
	second_polygon->setPen(seconds_pen);

	//intializing minutes polygons
	QPen minutes_pen;
	minutes_pen.setColor(Qt::darkBlue);
	minutes_pen.setWidth(3);
	minute_polygon->setPen(minutes_pen);

	//intializing hours polygons
	QPen hours_pen;
	hours_pen.setColor(Qt::black);
	hours_pen.setWidth(5);
	hour_polygon->setPen(hours_pen);

	//initialize time in text
	time_text->setDefaultTextColor(QColor(Qt::GlobalColor::darkRed));
	QFont digital_clock_font;
	digital_clock_font.setFamily(QString::fromUtf8("Arial"));
	digital_clock_font.setPixelSize(25);
	digital_clock_font.setWeight(100);
	digital_clock_font.setItalic(false);
	time_text->setFont(digital_clock_font);
	time_text->setPos(center.x() - 65, center.y() - 28);
	time_text->setPlainText(QTime::currentTime().toString());

	//initializing time
	currenttime = QTime::currentTime();
	hours = currenttime.hour() % 12;
	minutes = currenttime.minute();
	seconds = currenttime.second();

	//drawing graphical clock
	drawing_hands();
	clock_scene->addItem(hour_polygon);
	clock_scene->addItem(minute_polygon);
	clock_scene->addItem(second_polygon);

	//drawing time in text
	clock_scene->addItem(time_text);
}

clock_hands::~clock_hands()
{
}

void clock_hands::update_clock()
{
	currenttime = QTime::currentTime();
	hours = currenttime.hour() % 12;
	minutes = currenttime.minute();
	seconds = currenttime.second();

	drawing_hands();
}

void clock_hands::drawing_hands() {

	int degrees_seconds;
	int degrees_minutes;
	int degrees_hours;

	//making sound tick sound
	if (seconds - previous_seconds >= 1 || seconds - previous_seconds < 0) {
		previous_seconds = seconds;
		if (ticksound_enable == true)
			player->play();
		else
			player->stop();
	}

	//drawng seconds hand
	QVector<QPointF> seconds_points;
	degrees_seconds = seconds * 360.0 / 60.0;
	degrees_seconds -= 90;
	seconds_points << center << QPointF(180 * qCos(qDegreesToRadians((qreal)degrees_seconds)) + center.x(), 180 * qSin(qDegreesToRadians((qreal)degrees_seconds)) + center.y());
	second_polygon->setPolygon(seconds_points);

	//drawng minutes hand
	QVector<QPointF> minutes_points;
	degrees_minutes = (minutes + seconds / 60.0) * 360.0 / 60.0;
	degrees_minutes -= 90;
	minutes_points << center << QPointF(150 * qCos(qDegreesToRadians((qreal)degrees_minutes)) + center.x(), 150 * qSin(qDegreesToRadians((qreal)degrees_minutes)) + center.y());
	minute_polygon->setPolygon(minutes_points);

	//drawng hours hand
	QVector<QPointF> hours_points;
	degrees_hours = (hours + minutes / 60.0 + seconds / 3600.0) * 360.0 / 12.0;
	degrees_hours -= 90;
	hours_points << center << QPointF(120 * qCos(qDegreesToRadians((qreal)degrees_hours)) + center.x(), 120 * qSin(qDegreesToRadians((qreal)degrees_hours)) + center.y());
	hour_polygon->setPolygon(hours_points);

	//drawign text
	time_text->setPlainText(QTime::currentTime().toString());
	
}