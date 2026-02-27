// ============================================================================
//                          Person.h
// ============================================================================
/*
Header file (.h hoặc .hpp):
- Khai báo class, các thuộc tính và phương thức
- Sử dụng header guard để tránh include trùng lặp
- Chỉ khai báo, không định nghĩa chi tiết (trừ inline functions)
*/

#ifndef PERSON_H    // Header guard - kiểm tra chưa được define
#define PERSON_H    // Define để lần sau không include lại

#include <string>
#include <iostream>

// Namespace để tránh xung đột tên
namespace MyProject {

// Class cơ bản - Người
class Person {
protected:  // Protected: truy cập được từ class con
    std::string name;
    int age;
    std::string address;

public:
    // Constructor mặc định
    Person();
    
    // Constructor có tham số
    Person(const std::string& name, int age);
    
    // Constructor đầy đủ
    Person(const std::string& name, int age, const std::string& address);
    
    // Copy Constructor - sao chép đối tượng
    Person(const Person& other);
    
    // Destructor - hàm hủy
    virtual ~Person();
    
    // Getter methods (const để không thay đổi object)
    std::string getName() const;
    int getAge() const;
    std::string getAddress() const;
    
    // Setter methods
    void setName(const std::string& name);
    void setAge(int age);
    void setAddress(const std::string& address);
    
    // Virtual function - cho phép override trong class con
    virtual void display() const;
    
    // Virtual function cho polymorphism
    virtual std::string getRole() const;
    
    // Operator overloading - nạp chồng toán tử
    Person& operator=(const Person& other);  // Assignment operator
    bool operator==(const Person& other) const;  // So sánh
    
    // Friend function - có thể truy cập private members
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

} // namespace MyProject

#endif // PERSON_H