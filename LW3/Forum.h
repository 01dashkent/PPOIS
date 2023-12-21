#pragma once
#include <iostream>
#include <vector>
#include "User.h"

class Forum {
private:
    User* author = nullptr;
    std::string theme = "";
    std::vector<std::string> messages;
public:
    void sendMessage(std::string message);

    void showMessages();

    double calculateDiscussionActivity(int numberOfMessages, int numberOfRatings) const;

    User* getAuthor() const;

    void setAuthor(User* value);

    std::string getTheme() const;

    void setTheme(std::string value);
};
