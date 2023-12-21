#pragma once
#include <iostream>
#include <vector>

class Progress {
private:
    std::vector<std::string> completedCourses;
    std::vector<std::string> currentTasks;
    std::vector<int> grades;
public: 
    double calculateAverageGrade(std::vector<int> grades) const;

    double calculateTaskProgress(int completedTasks, int totalTasks) const;

    const std::vector<std::string>& getCompletedCourses() const;

    const std::vector<std::string>& getCurrentTasks() const;

    const std::vector<int>& getGrades() const;
};