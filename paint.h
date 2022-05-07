#ifndef PAINT_H
#define PAINT_H

#include "drawingarea.h"

#include <QWidget>
#include <QTimer>

class QSlider;

class Paint : public QWidget
{
    Q_OBJECT

public:
    Paint(QWidget *parent = nullptr);
    ~Paint();

private slots:
    void selectPenColor() { this->drawingArea->setCurrentPenColor(this->getColorFromUser()); }
    void selectBrushColor() { this->drawingArea->setCurrentBrushColor(this->getColorFromUser()); }

    void updateLineWidth(int lineWidth);

private:
    QColor getColorFromUser() const;

    DrawingArea *drawingArea;
};
#endif // PAINT_H
