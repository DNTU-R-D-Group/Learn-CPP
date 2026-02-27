// ============================================================================
//                          Circle.cpp
// ============================================================================
#include "Circle.h"
#include <iostream>

namespace MyProject {

Circle::Circle(double radius, const std::string& color) 
    : Shape(color), radius(radius) {
    std::cout << "[Circle] Constructor: radius = " << radius << "\n";
}

Circle::~Circle() {
    std::cout << "[Circle] Destructor\n";
}

double Circle::getArea() const {
    return PI * radius * radius;
}

double Circle::getPerimeter() const {
    return 2 * PI * radius;
}

void Circle::draw() const {
    std::cout << "Vẽ hình tròn màu " << color 
              << " với bán kính " << radius << "\n";
}

std::string Circle::getType() const {
    return "Circle";
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double radius) {
    if (radius > 0) {
        this->radius = radius;
    }
}

} // namespace MyProject