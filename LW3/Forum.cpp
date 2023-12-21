#include "Forum.h"

void Forum::sendMessage(std::string message) {
    messages.push_back(message);
}

void Forum::showMessages() {
    std::cout << theme << std::endl << author->getName() << std::endl;
    for (auto message : messages) {
        std::cout << message << std::endl;
    }
}

double Forum::calculateDiscussionActivity(int numberOfMessages, int numberOfRatings) const {
    return numberOfMessages * 0.7 + numberOfRatings * 0.3;
}

User* Forum::getAuthor() const {
    return author;
}

void Forum::setAuthor(User* value) {
    author = value;
}

std::string Forum::getTheme() const {
    return theme;
}

void Forum::setTheme(std::string value) {
    theme = value;
}