#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>

#include <string>

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}

    virtual void draw(QPainter &painter) const = 0;
    virtual std::string getName() const = 0;
    virtual std::string dumps() const = 0;

    void setCurrentPenColor(QColor currentPenColor) { this->currentPenColor = currentPenColor; }
    void setCurrentBrushColor(QColor currentBrushColor) { this->currentBrushColor = currentBrushColor; }
    void setCurrentLineWidth(int currentLineWidth) { this->currentLineWidth = currentLineWidth; }

protected:
    QColor currentPenColor;
    QColor currentBrushColor;
    int currentLineWidth = 1;
};

typedef Shape *(* ShapeCreator)();

#endif // SHAPE_H
