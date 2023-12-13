#include "Certificate.h"

void Certificate::createCertificate() {
    std::cout << "Creating certificate with title: " << title;
}

std::string Certificate::calculateCertificateLevel(double userGrade) const {
    if (userGrade < 0 || userGrade > 100) {
        throw std::invalid_argument("User grade must be between 0 and 100.");
    }
    if (userGrade < 60)
        return "Basic";
    else if (userGrade < 75)
        return "Intermediate";
    else if (userGrade < 90)
        return "Advanced";
    else
        return "Expert";
}

std::string Certificate::calculateCertificateStatus(bool isCompleted) const {
    return (isCompleted) ? "Issued" : "Not Issued";
}
