#include "trapezium.h"

#include "../json.hpp"

#include <QApplication>
#include <QDebug>

using json = nlohmann::json;

void Trapezium::draw(QPainter &painter, QPoint localMousePos) const
{
    QPen pen(this->currentPenColor);
    pen.setWidth(this->currentLineWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush(this->currentBrushColor));

    QVector<QPoint> points = this->points;

    if (!finishedDrawing)
    {
        points.append(localMousePos);
    }

    QPolygon poly(points);
    painter.drawPolygon(poly);
}

std::string Trapezium::getName() const
{
    return "trapezium";
}

std::string Trapezium::dumps() const
{
    json j;
    j["type"] = getName();
    return j.dump(2);
}

void Trapezium::startDrawing(const QPoint startPoint)
{
    this->points.append(startPoint);
}

void Trapezium::setNextPoint(const QPoint nextPoint)
{
    this->points.append(nextPoint);

    if (this->points.size() > 3)
    {
        finishedDrawing = true;
    }
}

// for exporting
extern "C" Shape *createShape()
{
    return new Trapezium();
}
