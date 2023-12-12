#pragma once
#include "User.h"

class Administrator : public User {
public:
    int accessLevel;
    std::string tasks;

    void display() const override;

    double calculateAdminRating(int numberOfTasks) const;

    bool isTaskCompleted(std::string task) const;
};