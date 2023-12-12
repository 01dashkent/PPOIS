#include "User.h"

void User::registration() {
    std::cout << "User " << name << " registered with email: " << email;
}

void User::login() {
    std::cout << "User " << personLogin;
}

void User::display() const {
    std::cout << "User: " << name << personLogin << " (" << email << ") on the online learning platform.\n";
}

double User::calculateActivityTime(double startTime, double endTime) const{
    if (startTime > endTime)
        throw std::invalid_argument("Start time cannot be greater than end time");
    return endTime - startTime;
}

double User::calculateProgressPercentage(int completedModules, int totalModules) const {
    if (totalModules == 0)
        throw std::invalid_argument("Total modules cannot be zero");
    return (static_cast<double>(completedModules) / totalModules) * 100.0;
}