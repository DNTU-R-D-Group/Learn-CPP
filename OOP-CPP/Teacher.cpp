// ============================================================================
//                          Teacher.cpp
// ============================================================================

#include "Teacher.h"
#include <iostream>
#include <string>
#include <vector>

namespace MyProject {

Teacher::Teacher() : Person(), teacherId(""), subject(""), salary(0.0) {
    std::cout << "[Teacher] Constructor mặc định\n";
}

Teacher::Teacher(const std::string& name, int age, const std::string& teacherId,
                 const std::string& subject)
    : Person(name, age), teacherId(teacherId), subject(subject), salary(0.0) {
    std::cout << "[Teacher] Constructor: " << teacherId << "\n";
}

Teacher::~Teacher() {
    std::cout << "[Teacher] Destructor: " << teacherId << "\n";
}

std::string Teacher::getTeacherId() const {
    return teacherId;
}

std::string Teacher::getSubject() const {
    return subject;
}

double Teacher::getSalary() const {
    return salary;
}

void Teacher::setTeacherId(const std::string& id) {
    teacherId = id;
}

void Teacher::setSubject(const std::string& subject) {
    this->subject = subject;
}

void Teacher::setSalary(double salary) {
    if (salary >= 0) {
        this->salary = salary;
    }
}

void Teacher::addClass(const std::string& className) {
    classes.push_back(className);
}

void Teacher::displayClasses() const {
    std::cout << "Danh sách lớp dạy:\n";
    for (const auto& className : classes) {
        std::cout << "  - " << className << "\n";
    }
}

void Teacher::display() const {
    std::cout << "=== THÔNG TIN GIÁO VIÊN ===\n";
    std::cout << "Mã GV: " << teacherId << "\n";
    std::cout << "Tên: " << name << "\n";
    std::cout << "Tuổi: " << age << "\n";
    std::cout << "Môn dạy: " << subject << "\n";
    std::cout << "Lương: " << salary << " VNĐ\n";
}

std::string Teacher::getRole() const {
    return "Teacher";
}

} // namespace MyProject