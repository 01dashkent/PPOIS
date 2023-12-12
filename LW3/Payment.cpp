#include "Payment.h"


void Payment::payCourse() {
    std::cout << "Paying for course. Amount: " << amount;
}

double Payment::calculateDiscountedAmount(double discountPercentage) const {
    if (discountPercentage < 0 || discountPercentage > 100) {
        throw std::invalid_argument("Discount percentage must be between 0 and 100");
    }
    return amount - (amount * discountPercentage / 100.0);
}

double Payment::calculateAmountWithTax(double taxRate) const {
    if (taxRate < 0) {
        throw std::invalid_argument("Tax rate cannot be negative.");
    }
    return amount + (amount * taxRate / 100.0);
}