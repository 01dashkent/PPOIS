#include "Progress.h"

double Progress::calculateAverageGrade(std::vector<int> grades) const {
    if (grades.empty()) {
        throw std::invalid_argument("Average grade calculation requires non-empty vector");
    }
    double sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

double Progress::calculateTaskProgress(int completedTasks, int totalTasks) const {
    if (totalTasks <= 0) {
        throw std::invalid_argument("Total tasks must be greater than zero.");
    }
    return (static_cast<double>(completedTasks) / totalTasks) * 100.0;
}

const std::vector<std::string>& Progress::getCompletedCourses() const {
    return completedCourses;
}

const std::vector<std::string>& Progress::getCurrentTasks() const {
    return currentTasks;
}

const std::vector<int>& Progress::getGrades() const {
    return grades;
}