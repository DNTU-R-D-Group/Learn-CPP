// ============================================================================
//                          Teacher.h
// ============================================================================

#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include <vector>

namespace MyProject {

class Teacher : public Person {
private:
    std::string teacherId;
    std::string subject;           // Môn dạy
    std::vector<std::string> classes;  // Danh sách lớp
    double salary;
    
public:
    // Constructors
    Teacher();
    Teacher(const std::string& name, int age, const std::string& teacherId,
            const std::string& subject);
    
    // Destructor
    ~Teacher();
    
    // Getters
    std::string getTeacherId() const;
    std::string getSubject() const;
    double getSalary() const;
    
    // Setters
    void setTeacherId(const std::string& id);
    void setSubject(const std::string& subject);
    void setSalary(double salary);
    
    // Methods
    void addClass(const std::string& className);
    void displayClasses() const;
    
    // Override methods
    void display() const override;
    std::string getRole() const override;
};

} // namespace MyProject

#endif // TEACHER_H