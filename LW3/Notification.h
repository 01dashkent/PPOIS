#pragma once
#include <iostream>

class Notification {
public:
    std::string text;
    std::string sendTime;
    std::string recipient;

    void sendNotification();

    int calculateMessageLength() const;

    std::string calculateUrgencyLevel() const;
};
