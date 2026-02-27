// ============================================================================
//                          Person.cpp
// ============================================================================
/*
Implementation file (.cpp):
- Định nghĩa chi tiết các phương thức đã khai báo trong .h
- Include file .h tương ứng
*/

#include "Person.h"  // Include header file
// Trong artifact này, ta giả lập bằng comment

namespace MyProject {

// Constructor mặc định - khởi tạo giá trị mặc định
Person::Person() : name("Unknown"), age(0), address("") {
    std::cout << "[Person] Constructor mặc định được gọi\n";
}

// Constructor có tham số - sử dụng member initializer list
Person::Person(const std::string& name, int age) 
    : name(name), age(age), address("") {
    std::cout << "[Person] Constructor có tham số: " << name << "\n";
}

// Constructor đầy đủ
Person::Person(const std::string& name, int age, const std::string& address)
    : name(name), age(age), address(address) {
    std::cout << "[Person] Constructor đầy đủ: " << name << "\n";
}

// Copy Constructor - sao chép đối tượng
Person::Person(const Person& other) 
    : name(other.name), age(other.age), address(other.address) {
    std::cout << "[Person] Copy constructor: " << name << "\n";
}

// Destructor - được gọi khi đối tượng bị hủy
Person::~Person() {
    std::cout << "[Person] Destructor: " << name << "\n";
}

// Getter methods - trả về giá trị thuộc tính
std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

std::string Person::getAddress() const {
    return address;
}

// Setter methods - thiết lập giá trị
void Person::setName(const std::string& name) {
    this->name = name;  // this-> để phân biệt với tham số
}

void Person::setAge(int age) {
    if (age >= 0 && age <= 150) {  // Validate
        this->age = age;
    } else {
        std::cout << "Tuổi không hợp lệ!\n";
    }
}

void Person::setAddress(const std::string& address) {
    this->address = address;
}

// Display method - hiển thị thông tin
void Person::display() const {
    std::cout << "=== THÔNG TIN PERSON ===\n";
    std::cout << "Tên: " << name << "\n";
    std::cout << "Tuổi: " << age << "\n";
    std::cout << "Địa chỉ: " << address << "\n";
}

// Virtual method
std::string Person::getRole() const {
    return "Person";
}

// Assignment operator - toán tử gán
Person& Person::operator=(const Person& other) {
    if (this != &other) {  // Kiểm tra tự gán
        name = other.name;
        age = other.age;
        address = other.address;
    }
    return *this;
}

// Equality operator - toán tử so sánh
bool Person::operator==(const Person& other) const {
    return (name == other.name && age == other.age);
}

// Friend function - operator << để in object
std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name << " (" << person.age << " tuổi)";
    return os;
}

} // namespace MyProject