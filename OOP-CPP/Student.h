// ============================================================================
//                          Student.h
// ============================================================================
/*
KẾ THỪA (INHERITANCE):
- Student kế thừa từ Person
- Có thêm các thuộc tính và phương thức riêng
- Override các phương thức của class cha
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>

namespace MyProject {

class Student : public Person {  // public inheritance
private:
    std::string studentId;
    std::vector<double> scores;  // Danh sách điểm
    std::string major;           // Chuyên ngành
    
public:
    // Constructors
    Student();
    Student(const std::string& name, int age, const std::string& studentId);
    Student(const std::string& name, int age, const std::string& studentId, 
            const std::string& major);
    
    // Destructor
    ~Student();
    
    // Getters
    std::string getStudentId() const;
    std::string getMajor() const;
    double getAverageScore() const;
    
    // Setters
    void setStudentId(const std::string& id);
    void setMajor(const std::string& major);
    
    // Methods
    void addScore(double score);
    void displayScores() const;
    std::string getGrade() const;
    
    // Override methods từ Person
    void display() const override;
    std::string getRole() const override;
    
    // Static member - dùng chung cho tất cả objects
    static int totalStudents;
    static int getTotalStudents();
};

} // namespace MyProject

#endif // STUDENT_H