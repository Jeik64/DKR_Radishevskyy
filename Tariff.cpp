#include "Tariff.h"
#include <iostream>

Tariff::Tariff(std::string name, double fee, int count)
    : name(name), subscriptionFee(fee), clientsCount(count) {}

void Tariff::display() const {
    std::cout << "Tariff: " << name << ", Subscription Fee: " << subscriptionFee
        << ", Clients Count: " << clientsCount << std::endl;
}