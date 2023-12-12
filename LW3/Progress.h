#pragma once
#include <iostream>
#include <vector>

class Progress {
public:
    std::vector<std::string> completedCourses;
    std::vector<std::string> currentTasks;
    std::vector<int> grades;

    double calculateAverageGrade(std::vector<int> grades) const;

    double calculateTaskProgress(int completedTasks, int totalTasks) const;
};