#pragma once
#include <iostream>

class Forum {
public:
    std::string topic;
    std::string author;
    std::string creationTime;
    std::string message;

    void createTopic();

    void sendMessage();

    void rateAnswers();

    double calculateDiscussionActivity(int numberOfMessages, int numberOfRatings) const;

    double calculateTopicPopularity(int numberOfViews, int numberOfReplies) const;
};
