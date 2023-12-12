#pragma once
#include "Course.h"

class Test : public Course {
public:
    std::vector<std::string> questions;
    int duration;
    std::vector<std::string> answers;

    void generateTest();

    void checkResults();

    double calculateTestDifficulty() const;

    double calculateTestTime(double averageAnswerTime) const;
};