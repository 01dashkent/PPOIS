#include "Forum.h"

void Forum::createTopic() {
    std::cout << "Creating forum topic: " << topic;
}

void Forum::sendMessage() {
    std::cout << "Sending message in forum topic: " << topic << message;
}

void Forum::rateAnswers() {
    std::cout << "Rating answers in forum topic: " << topic;
}

double Forum::calculateDiscussionActivity(int numberOfMessages, int numberOfRatings) const {
    return numberOfMessages * 0.7 + numberOfRatings * 0.3;
}

double Forum::calculateTopicPopularity(int numberOfViews, int numberOfReplies) const {
    return numberOfViews * 0.6 + numberOfReplies * 0.4;
}