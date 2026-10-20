#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string personName, int personAge)
        : name(personName), age(personAge) {}

    void displayPersonInfo() const {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
    }
};

// Student inherits from Person
class Student : public Person {
protected:
    string studentId;
    string course;

public:
    Student(string personName, int personAge,
            string id, string studentCourse)
        : Person(personName, personAge),
          studentId(id), course(studentCourse) {}

    void displayStudentInfo() const {
        displayPersonInfo(); // Inherited member from Person
        cout << "Student ID: " << studentId << '\n';
        cout << "Course: " << course << '\n';
    }
};

// UniversityStudent inherits from Student
class UniversityStudent : public Student {
private:
    string university;
    int yearOfStudy;

public:
    UniversityStudent(string personName, int personAge,
                     string id, string studentCourse,
                     string universityName, int year)
        : Student(personName, personAge, id, studentCourse),
          university(universityName), yearOfStudy(year) {}

    void displayUniversityInfo() const {
        displayStudentInfo(); // Inherited through Student
        cout << "University: " << university << '\n';
        cout << "Year of study: " << yearOfStudy << '\n';
    }

    void promote() {
        if (yearOfStudy < 5) {
            ++yearOfStudy;
            cout << "Student promoted to year " << yearOfStudy << ".\n";
        } else {
            cout << "Year of study cannot be increased beyond 5.\n";
        }
    }
};

int main() {
    UniversityStudent student(
        "Amina", 20, "2026/CSC/014", "Computer Science",
        "Makerere University", 2
    );

    cout << "=== University Student Details ===\n";
    student.displayUniversityInfo();

    cout << "\n=== Demonstrating a locally defined member ===\n";
    student.promote();

    cout << "\n=== Details after promotion ===\n";
    student.displayUniversityInfo();

    return 0;
}
