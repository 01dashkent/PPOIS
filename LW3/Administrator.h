#pragma once
#include "User.h"

class Administrator : public User {
private:
    int accessLevel = 0;
    std::string tasks;
public:
   
    void display() const override;

    double calculateAdminRating(int numberOfTasks) const;

    bool isTaskCompleted(std::string task) const;

    int getAccessLevel() const;

    void setAccessLevel(int value);

    std::string getTasks() const;

    void setTasks(std::string value);
};