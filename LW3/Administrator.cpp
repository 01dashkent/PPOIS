#include "Administrator.h"

void Administrator::display() const {
    std::cout << "Administrator: " << getName() << " Level: " << accessLevel;
}

double Administrator::calculateAdminRating(int numberOfTasks) const {
    return numberOfTasks * 0.5;
}

bool Administrator::isTaskCompleted(std::string task) const {
    return (tasks.find(task) != std::string::npos);
}

int Administrator::getAccessLevel() const {
    return accessLevel;
}

void Administrator::setAccessLevel(int value) {
    accessLevel = value;
}

std::string Administrator::getTasks() const {
    return tasks;
}

void Administrator::setTasks(std::string value) {
    tasks = value;
}