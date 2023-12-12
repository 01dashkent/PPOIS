#include "Module.h"

void Module::loadMaterials() {
    std::cout << "Loading materials for module: " << moduleName << " of Course: " << title;
}

void Module::checkCompletion() {
    std::cout << "Checking completion of module: " << moduleName << " of Course: " << title;
}

void Module::display() const {
    std::cout << "Module: " << moduleName << " of Course: " << title;
}

double Module::calculateModuleDifficulty() const {
    return requirements.length() * 1.5;
}

double Module::calculateStudyTime(double averageStudySpeed) const {
    if (averageStudySpeed <= 0) {
        throw std::invalid_argument("Average study speed must be greater than zero.");
    }
    return content.length() / averageStudySpeed;
}