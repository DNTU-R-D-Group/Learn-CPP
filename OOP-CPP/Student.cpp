// ============================================================================
//                          Student.cpp
// ============================================================================

#include "Student.h"
#include <iostream>
#include <iomanip>

namespace MyProject {

// Khởi tạo static member
int Student::totalStudents = 0;

// Constructor mặc định
Student::Student() : Person(), studentId(""), major("") {
    totalStudents++;
    std::cout << "[Student] Constructor mặc định\n";
}

// Constructor có tham số - gọi constructor của Person
Student::Student(const std::string& name, int age, const std::string& studentId)
    : Person(name, age), studentId(studentId), major("") {
    totalStudents++;
    std::cout << "[Student] Constructor: " << studentId << "\n";
}

// Constructor đầy đủ
Student::Student(const std::string& name, int age, const std::string& studentId,
                 const std::string& major)
    : Person(name, age), studentId(studentId), major(major) {
    totalStudents++;
    std::cout << "[Student] Constructor đầy đủ: " << studentId << "\n";
}

// Destructor
Student::~Student() {
    totalStudents--;
    std::cout << "[Student] Destructor: " << studentId << "\n";
}

// Getters
std::string Student::getStudentId() const {
    return studentId;
}

std::string Student::getMajor() const {
    return major;
}

double Student::getAverageScore() const {
    if (scores.empty()) return 0.0;
    
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

// Setters
void Student::setStudentId(const std::string& id) {
    studentId = id;
}

void Student::setMajor(const std::string& major) {
    this->major = major;
}

// Thêm điểm
void Student::addScore(double score) {
    if (score >= 0.0 && score <= 10.0) {
        scores.push_back(score);
    } else {
        std::cout << "Điểm không hợp lệ!\n";
    }
}

// Hiển thị danh sách điểm
void Student::displayScores() const {
    std::cout << "Điểm: ";
    for (double score : scores) {
        std::cout << score << " ";
    }
    std::cout << "\nĐiểm trung bình: " << getAverageScore() << "\n";
}

// Xếp loại
std::string Student::getGrade() const {
    double avg = getAverageScore();
    if (avg >= 9.0) return "Xuất sắc";
    if (avg >= 8.0) return "Giỏi";
    if (avg >= 7.0) return "Khá";
    if (avg >= 5.0) return "Trung bình";
    return "Yếu";
}

// Override display method
void Student::display() const {
    std::cout << "=== THÔNG TIN SINH VIÊN ===\n";
    std::cout << "Mã SV: " << studentId << "\n";
    std::cout << "Tên: " << name << "\n";  // Truy cập protected member của Person
    std::cout << "Tuổi: " << age << "\n";
    std::cout << "Chuyên ngành: " << major << "\n";
    std::cout << "Điểm TB: " << getAverageScore() << "\n";
    std::cout << "Xếp loại: " << getGrade() << "\n";
}

// Override getRole
std::string Student::getRole() const {
    return "Student";
}

// Static method
int Student::getTotalStudents() {
    return totalStudents;
}

} // namespace MyProject