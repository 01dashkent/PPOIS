#include "Administrator.h"

void Administrator::display() const {
    std::cout << "Administrator: " << name << " (Level: " << accessLevel << ") on the online learning platform.\n";
}

double Administrator::calculateAdminRating(int numberOfTasks) const {
    return numberOfTasks * 0.5;
}

bool Administrator::isTaskCompleted(std::string task) const {
    return (tasks.find(task) != std::string::npos);
}