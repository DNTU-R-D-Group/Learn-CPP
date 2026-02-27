// ============================================================================
//                          Shape.cpp
// ============================================================================

#include "Shape.h"
#include <iostream>

namespace MyProject {

Shape::Shape(const std::string& color) : color(color) {
    std::cout << "[Shape] Constructor\n";
}

Shape::~Shape() {
    std::cout << "[Shape] Destructor\n";
}

std::string Shape::getType() const {
    return "Generic Shape";
}

std::string Shape::getColor() const {
    return color;
}

void Shape::setColor(const std::string& color) {
    this->color = color;
}

} // namespace MyProject