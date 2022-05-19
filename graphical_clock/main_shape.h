#pragma once

#include <QWidget>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qbrush.h>
#include <qevent.h>
#include <qicon.h>
#include <qcheckbox.h>
#include "clock_shape.h"
#include "clock_hands.h"
#include "main_shape.h"
#include "ui_main_shape.h"

class main_shape : public QWidget
{
	Q_OBJECT

public:
	main_shape(QWidget *parent = Q_NULLPTR);
	~main_shape();
private slots:
    void mousePressEvent(QMouseEvent* event);
    // to release the flag of pressed mouse button
    void mouseReleaseEvent(QMouseEvent* event);
    // to move the form on the screen
    void mouseMoveEvent(QMouseEvent* event);
    void ticksound_stateChanged(int state);

private:
	Ui::main_shape ui;
    bool mouseispressed = false;
    QPoint mouserelativepointonform;
    clock_shape* clock;
    clock_hands* cl_hands;

};
