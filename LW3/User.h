#pragma once
#include <iostream>
class User {
public:
    std::string name;
    std::string email;
    std::string password;
    std::string personLogin;

    void registration();

    void login();

    virtual void display() const;

    double calculateActivityTime(double startTime, double endTime) const;

    double calculateProgressPercentage(int completedModules, int totalModules) const;
};