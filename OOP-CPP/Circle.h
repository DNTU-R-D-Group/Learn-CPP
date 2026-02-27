// ============================================================================
//                          Circle.h
// ============================================================================

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

namespace MyProject {

class Circle : public Shape {
private:
    double radius;
    static constexpr double PI = 3.14159265359;
    
public:
    Circle(double radius, const std::string& color = "Red");
    ~Circle();
    
    // Override pure virtual functions
    double getArea() const override;
    double getPerimeter() const override;
    void draw() const override;
    
    // Override virtual function
    std::string getType() const override;
    
    // Getter/Setter
    double getRadius() const;
    void setRadius(double radius);
};

} // namespace MyProject

#endif // CIRCLE_H