#pragma once
#include "Course.h"

class Module : public Course {
public:
    std::string moduleName;
    std::string content;
    std::string startTime;
    std::string requirements;

    void loadMaterials();

    void checkCompletion();

    void display() const override;

    double calculateModuleDifficulty() const;

    double calculateStudyTime(double averageStudySpeed) const;
};