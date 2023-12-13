#include "Course.h"

void Course::viewMaterials() {
    std::cout << "Viewing materials for course: " << title;
}

void Course::evaluate() {
    std::cout << "Evaluating performance in course: " << title;
}

void Course::display() const {
    std::cout << "Course: " << title << " (" << duration << ")";
}

double Course::calculateAverageRating(std::vector<double> ratings) const {
    if (ratings.empty())
        throw std::invalid_argument("Average rating calculation requires non-empty vector");
    double sum = 0;
    for (double rating : ratings) {
        sum += rating;
    }
    return sum / ratings.size();
}

double Course::calculateTimeSpent(double averageTimePerModule, int numberOfModules) const {
    if (numberOfModules == 0)
        throw std::invalid_argument("Number of modules cannot be zero");
    return averageTimePerModule * numberOfModules;
}
