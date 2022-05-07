#include "drawingarea.h"

#include <QPainter>
#include <QTimer>
#include <QDebug>

DrawingArea::DrawingArea(QWidget *parent, ShapesCreator *shapesCreator) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    this->redrawTimer = new QTimer(this);
    this->redrawTimer->setInterval(10);
    connect(this->redrawTimer, &QTimer::timeout, this, &DrawingArea::updateArea);
    this->redrawTimer->start();

    this->shapesCreator = shapesCreator;

    this->setMouseTracking(true);
}

DrawingArea::~DrawingArea()
{
    for (auto shape : shapes)
    {
        delete shape;
    }
}

void DrawingArea::updateArea()
{
    this->repaint();
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse was pressed. coordinates: " << event->x() << ", " << event->y() << "\n";
    qDebug() << "next shape: " << this->currentShapeName.c_str();
    Shape *newShape = this->shapesCreator->createShape(this->currentShapeName);
    newShape->setCurrentBrushColor(this->currentBrushColor);
    newShape->setCurrentPenColor(this->currentPenColor);
    newShape->setCurrentLineWidth(this->currentLineWidth);
    this->addShape(newShape);
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    for (auto s : shapes)
    {
        s->draw(painter);
    }

    /*QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(currentPenColor);
    pen.setWidth(currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(currentBrushColor));

    painter.drawEllipse(QPoint(this->width() / 2, this->height() / 2), 50, 40);*/
}
