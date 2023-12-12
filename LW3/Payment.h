#pragma once
#include <iostream>

class Payment {
public:
    double amount;
    std::string date;
    std::string status;

    void payCourse();

    double calculateDiscountedAmount(double discountPercentage) const;

    double calculateAmountWithTax(double taxRate) const;
};