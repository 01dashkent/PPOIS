#include "Test.h"

void Test::generateTest() {
    std::cout << "Generating test for course: " << title;
}

void Test::checkResults() {
    std::cout << "Checking results for test in course: " << title;
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