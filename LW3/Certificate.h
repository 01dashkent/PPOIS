#pragma once
#include <iostream>

class Certificate {
public:
    std::string title;
    std::string issueDate;
    std::string level;

    void createCertificate();

    std::string calculateCertificateLevel(double userGrade) const;

    std::string calculateCertificateStatus(bool isCompleted) const;
};