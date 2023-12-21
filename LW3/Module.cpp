#include "Module.h"

void Module::checkCompletion() {
    std::cout << "Checking completion of module: " << getTitle();
}

void Module::display() const {
    std::cout << "Module: " << getTitle();
}

double Module::calculateModuleDifficulty() const {
    return getDescription().length() * 1.5;
}

double Module::calculateStudyTime(double averageStudySpeed) const {
    if (averageStudySpeed <= 0) {
        throw std::invalid_argument("Average study speed must be greater than zero.");
    }
    return content.length() / averageStudySpeed;
}