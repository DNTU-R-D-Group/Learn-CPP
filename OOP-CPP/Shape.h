// ============================================================================
//                          Shape.h
//              (VÍ DỤ VỀ ABSTRACTION & POLYMORPHISM)
// ============================================================================
/*
ABSTRACTION (Trừu tượng hóa):
- Abstract class - class có ít nhất 1 pure virtual function
- Không thể tạo object từ abstract class
- Dùng làm base class cho các class khác

POLYMORPHISM (Đa hình):
- Một interface, nhiều implementations
- Override virtual methods trong class con
- Dynamic binding - gọi method dựa vào object thực tế
*/

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

namespace MyProject {

// Abstract class - có pure virtual function
class Shape {
protected:
    std::string color;
    
public:
    Shape(const std::string& color = "Black");
    virtual ~Shape();
    
    // Pure virtual functions - PHẢI override trong class con
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void draw() const = 0;
    
    // Virtual function - CÓ THỂ override
    virtual std::string getType() const;
    
    // Normal method
    std::string getColor() const;
    void setColor(const std::string& color);
};

} // namespace MyProject

#endif // SHAPE_H