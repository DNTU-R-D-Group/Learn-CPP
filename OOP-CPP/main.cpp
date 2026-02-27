/*
================================================================================
        HƯỚNG DẪN LẬP TRÌNH HƯỚNG ĐỐI TƯỢNG (OOP) TRONG C++
              Đầy đủ với file .h (header) và .cpp
================================================================================

CẤU TRÚC DỰ ÁN:
- Person.h           (Header file - khai báo class Person)
- Person.cpp         (Implementation file - định nghĩa phương thức)
- Student.h          (Header file - class Student kế thừa Person)
- Student.cpp        (Implementation file)
- Teacher.h          (Header file - class Teacher kế thừa Person)
- Teacher.cpp        (Implementation file)
- BankAccount.h      (Ví dụ về Encapsulation)
- BankAccount.cpp
- Shape.h            (Ví dụ về Polymorphism - abstract class)
- Circle.h, Rectangle.h
- main.cpp           (File chính)

================================================================================
*/
// ============================================================================
//                          main.cpp
//                      FILE CHÍNH - DEMO TẤT CẢ
// ============================================================================

#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "BankAccount.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace MyProject;

// Hàm demo Polymorphism
void demo_polymorphism(Shape* shape) {
    std::cout << "\n--- DEMO POLYMORPHISM ---\n";
    std::cout << "Loại: " << shape->getType() << "\n";
    std::cout << "Màu: " << shape->getColor() << "\n";
    std::cout << "Diện tích: " << shape->getArea() << "\n";
    std::cout << "Chu vi: " << shape->getPerimeter() << "\n";
    shape->draw();
}

int main() {
    std::cout << "===============================================\n";
    std::cout << "  DEMO LẬP TRÌNH HƯỚNG ĐỐI TƯỢNG TRONG C++\n";
    std::cout << "===============================================\n";
    
    // ========== 1. CLASS CƠ BẢN - PERSON ==========
    std::cout << "\n========== 1. CLASS CƠ BẢN ==========\n";
    
    Person p1;  // Constructor mặc định
    p1.setName("Nguyễn Văn A");
    p1.setAge(25);
    p1.setAddress("Hà Nội");
    p1.display();
    
    std::cout << "\n";
    Person p2("Trần Thị B", 30, "TP.HCM");  // Constructor có tham số
    p2.display();
    
    // Copy constructor
    std::cout << "\n--- Copy Constructor ---\n";
    Person p3 = p2;
    p3.display();
    
    // Operator overloading
    std::cout << "\n--- Operator Overloading ---\n";
    std::cout << "p2: " << p2 << "\n";
    std::cout << "p2 == p3? " << (p2 == p3 ? "Có" : "Không") << "\n";
    
    // ========== 2. KẾ THỪA - INHERITANCE ==========
    std::cout << "\n========== 2. KẾ THỪA ==========\n";
    
    Student s1("Lê Văn C", 20, "SV001", "Công nghệ thông tin");
    s1.setAddress("Đà Nẵng");
    s1.addScore(8.5);
    s1.addScore(9.0);
    s1.addScore(7.5);
    s1.display();
    s1.displayScores();
    
    std::cout << "\n";
    Teacher t1("Phạm Thị D", 35, "GV001", "Toán học");
    t1.setSalary(15000000);
    t1.addClass("10A1");
    t1.addClass("10A2");
    t1.addClass("11B1");
    t1.display();
    t1.displayClasses();
    
    // Static member
    std::cout << "\n--- Static Member ---\n";
    std::cout << "Tổng số sinh viên: " << Student::getTotalStudents() << "\n";
    
    // ========== 3. ENCAPSULATION - ĐÓNG GÓI ==========
    std::cout << "\n========== 3. ENCAPSULATION ==========\n";
    
        BankAccount acc1("123456789", "Nguyễn Văn E", "1234");
    BankAccount acc2("987654321", "Trần Thị F", "5678");

    acc1.displayInfo();
    acc2.displayInfo();

    std::cout << "\n--- Gửi tiền ---\n";
    acc1.deposit(5'000'000, "1234");
    acc1.deposit(2'000'000, "1234");

    std::cout << "\n--- Rút tiền ---\n";
    acc1.withdraw(1'500'000, "1234");

    std::cout << "\n--- Chuyển khoản ---\n";
    acc1.transfer(acc2, 2'000'000, "1234");

    std::cout << "\n--- Kiểm tra số dư ---\n";
    std::cout << "Số dư acc1: " << acc1.getBalance("1234") << " VNĐ\n";
    std::cout << "Số dư acc2: " << acc2.getBalance("5678") << " VNĐ\n";

    std::cout << "\n--- Đổi PIN ---\n";
    acc1.changePin("1234", "9999");

    // ========== 4. ABSTRACTION & POLYMORPHISM ==========
    std::cout << "\n========== 4. ABSTRACTION & POLYMORPHISM ==========\n";

    // Không thể tạo object Shape vì là abstract class
    // Shape shape; // ❌ ERROR

    Shape* shape1 = new Circle(5.0, "Đỏ");
    Shape* shape2 = new Rectangle(4.0, 6.0, "Xanh");

    demo_polymorphism(shape1);
    demo_polymorphism(shape2);

    // Giải phóng bộ nhớ
    delete shape1;
    delete shape2;

    std::cout << "\n===============================================\n";
    std::cout << "  KẾT THÚC CHƯƠNG TRÌNH DEMO OOP C++\n";
    std::cout << "===============================================\n";

    return 0;
}
