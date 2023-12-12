#pragma once
#include <iostream>
#include <vector>

class Course {
public:
    std::string title;
    std::string description;
    int duration;
    std::string instructor;

    void viewMaterials();

    void evaluate();

    virtual void display() const;

    double calculateAverageRating(std::vector<double> ratings) const;

    double calculateTimeSpent(double averageTimePerModule, int numberOfModules) const;
};