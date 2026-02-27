// ============================================================================
//                          Rectangle.h
// ============================================================================

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

namespace MyProject {

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double width, double height, const std::string& color = "Blue");
    ~Rectangle();
    
    // Override pure virtual functions
    double getArea() const override;
    double getPerimeter() const override;
    void draw() const override;
    
    // Override virtual function
    std::string getType() const override;
    
    // Getters/Setters
    double getWidth() const;
    double getHeight() const;
    void setWidth(double width);
    void setHeight(double height);
};

} // namespace MyProject

#endif // RECTANGLE_H