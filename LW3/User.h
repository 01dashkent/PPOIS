#pragma once
#include <iostream>
class User {
private:
    std::string name;
    std::string email;
    std::string password;
    std::string personLogin;
public:

    void registration();

    void login();

    virtual void display() const;

    double calculateActivityTime(double startTime, double endTime) const;

    double calculateProgressPercentage(int completedModules, int totalModules) const;

    std::string getName() const;

    void setname(std::string value);

    std::string getEmail() const;

    void setEmail(std::string value);

    std::string getPassword() const;

    void setPassword(std::string value);

    std::string getPersonLogin() const;

    void setPersonLogin(std::string value);
};