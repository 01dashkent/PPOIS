#include "Course.h"

void Course::viewMaterials() {
    std::cout << "Viewing materials for course: " << title;
}

void Course::evaluate() {
    std::cout << "Evaluating performance in course: " << title;
}

void Course::display() const {
    std::cout << "Course: " << title << " (" << duration << ")";
}

double Course::calculateAverageRating(std::vector<double> ratings) const {
    if (ratings.empty())
        throw std::invalid_argument("Average rating calculation requires non-empty vector");
    double sum = 0;
    for (double rating : ratings) {
        sum += rating;
    }
    return sum / ratings.size();
}

double Course::calculateTimeSpent(double averageTimePerModule, int numberOfModules) const {
    if (numberOfModules == 0)
        throw std::invalid_argument("Number of modules cannot be zero");
    return averageTimePerModule * numberOfModules;
}

std::string Course::getTitle() const {
    return title;
}

void Course::setTitle(std::string value) {
    title = value;
}

void Course::addStudent(Student* student) {
    students.insert(student);
}

void Course::removeStudent(Student* student) {
    students.erase(student);
}

Teacher* Course::getOwner() const {
    return owner;
}

void Course::setOwner(Teacher* value) {
    owner = value;
}

std::string Course::getDescription() const {
    return description;
}

void Course::setDescription(std::string value) {
    description = value;
}

int Course::getDuration() const {
    return duration;
}

void Course::setDuration(int value) {
    duration = value;
}

const std::set<Student*>& Course::getStudents() const {
    return students;
}