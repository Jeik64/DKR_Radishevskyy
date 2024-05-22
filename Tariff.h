#ifndef TARIFF_H
#define TARIFF_H

#include <string>

class Tariff {
public:
    std::string name;
    double subscriptionFee;
    int clientsCount;

    Tariff(std::string name, double fee, int count);
    void display() const;
};

#endif // TARIFF_H#pragma once
