// ============================================================================
//                          Rectangle.cpp
// ============================================================================

#include "Rectangle.h"
#include <iostream>
namespace MyProject {

Rectangle::Rectangle(double width, double height, const std::string& color)
    : Shape(color), width(width), height(height) {
    std::cout << "[Rectangle] Constructor: " << width << "x" << height << "\n";
}

Rectangle::~Rectangle() {
    std::cout << "[Rectangle] Destructor\n";
}

double Rectangle::getArea() const {
    return width * height;
}

double Rectangle::getPerimeter() const {
    return 2 * (width + height);
}

void Rectangle::draw() const {
    std::cout << "Vẽ hình chữ nhật màu " << color 
              << " kích thước " << width << "x" << height << "\n";
}

std::string Rectangle::getType() const {
    return "Rectangle";
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::setWidth(double width) {
    if (width > 0) {
        this->width = width;
    }
}

void Rectangle::setHeight(double height) {
    if (height > 0) {
        this->height = height;
    }
}

} // namespace MyProject