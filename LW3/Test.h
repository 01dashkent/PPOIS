#pragma once
#include "Course.h"

class Test : public Course {
private:
    std::vector<std::string> questions;
    std::vector<std::string> answers;
public:
    void checkResults();

    void addQuestionAnswer(std::string question,std::string answer);

    double calculateTestDifficulty() const;

    double calculateTestTime(double averageAnswerTime) const;

    const std::vector<std::string>& getQuestions() const;

    const std::vector<std::string>& getAnswers() const;
};