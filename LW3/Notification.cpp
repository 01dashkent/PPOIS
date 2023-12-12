#include "Notification.h"

void Notification::sendNotification() {
    std::cout << "Sending notification to " << recipient << ": " << text;
}

int Notification::calculateMessageLength() const {
    return text.length();
}

std::string Notification::calculateUrgencyLevel() const {
    return (text.length() > 50) ? "High" : "Low";
}