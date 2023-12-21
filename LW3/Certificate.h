#pragma once
#include <iostream>

class Certificate {
private:
    std::string issueDate;
    std::string level;
public:
    std::string calculateCertificateLevel(double userGrade) const;

    std::string calculateCertificateStatus(bool isCompleted) const;

    std::string getIssueDate() const;

    void setIssuedate(std::string value);

    std::string getLevel() const;

    void setLevel(std::string value);
};