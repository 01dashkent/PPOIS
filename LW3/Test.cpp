#include "Test.h"

void Test::checkResults() {
    std::cout << "Checking results for test in course: " << getTitle();
}

double Test::calculateTestDifficulty() const {
    return questions.size() * 1.2;
}

double Test::calculateTestTime(double averageAnswerTime) const {
    if (averageAnswerTime <= 0) {
        throw std::invalid_argument("Average answer time must be greater than zero.");
    }
    return averageAnswerTime * questions.size();
}

const std::vector<std::string>& Test::getQuestions() const {
    return questions;
}

const std::vector<std::string>& Test::getAnswers() const {
    return answers;
}

void Test::addQuestionAnswer(std::string question, std::string answer) {
    questions.push_back(question);
    answers.push_back(answer);
}