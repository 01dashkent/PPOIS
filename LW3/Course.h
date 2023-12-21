#pragma once
#include <iostream>
#include <vector>
#include <set>


class Teacher;
class Student;

class Course {
private:
    std::set<Student*> students;
    std::string title;
    std::string description;
    int duration = 0;
    Teacher* owner = nullptr;

public:

    void viewMaterials();

    void evaluate();

    virtual void display() const;

    double calculateAverageRating(std::vector<double> ratings) const;

    double calculateTimeSpent(double averageTimePerModule, int numberOfModules) const;

    void addStudent(Student* student);

    void removeStudent(Student* student);

    std::string getTitle() const;

    void setTitle(std::string title);

    std::string getDescription() const;

    void setDescription(std::string description);

    int getDuration() const;

    void setDuration(int duration);

    Teacher* getOwner() const;

    void setOwner(Teacher* value);

    const std::set<Student*>& getStudents() const;
};