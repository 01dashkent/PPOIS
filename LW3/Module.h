#pragma once
#include "Course.h"

class Module : public Course {
private:
    std::string content;
    int startTime;

public:
    void checkCompletion();

    void display() const override;

    double calculateModuleDifficulty() const;

    double calculateStudyTime(double averageStudySpeed) const;

    std::string getContent() const;

    void setContent(std::string value);

    int getStartTime() const;

    void setStartTime(int value);
};