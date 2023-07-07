#include <iostream>
#include <string>

class Person {
protected:
    std::string name;

public:
    Person(const std::string& name) : name(name) {}

    virtual void display() {
        std::cout << "Person - Name: " << name << std::endl;
    }
};

class Student : public Person {
private:
    std::string course;
    int marks;
    int year;

public:
    Student(const std::string& name, const std::string& course, int marks, int year)
        : Person(name), course(course), marks(marks), year(year) {}

    void display() override {
        std::cout << "Student - Name: " << name << ", Course: " << course
                  << ", Marks: " << marks << ", Year: " << year << std::endl;
    }
};

class Employee : public Person {
private:
    std::string department;
    double salary;

public:
    Employee(const std::string& name, const std::string& department, double salary)
        : Person(name), department(department), salary(salary) {}

    void display() override {
        std::cout << "Employee - Name: " << name << ", Department: " << department
                  << ", Salary: $" << salary << std::endl;
    }
};

int main() {
    Person* personPtr;

    Person person("John Doe");
    Student student("Jane Smith", "Computer Science", 95, 2022);
    Employee employee("Tom Johnson", "Human Resources", 5000.0);

    personPtr = &person;
    personPtr->display();

    personPtr = &student;
    personPtr->display();

    personPtr = &employee;
    personPtr->display();

    return 0;
}
