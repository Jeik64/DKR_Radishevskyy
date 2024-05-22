#include "MobileCompany.h"
#include <algorithm>
#include <iostream>

void MobileCompany::addTariff(const Tariff& tariff) {
    tariffs.push_back(tariff);
}

int MobileCompany::getTotalClients() const {
    int totalClients = 0;
    for (const auto& tariff : tariffs) {
        totalClients += tariff.clientsCount;
    }
    return totalClients;
}

void MobileCompany::sortTariffsByFee() {
    std::sort(tariffs.begin(), tariffs.end(), [](const Tariff& a, const Tariff& b) {
        return a.subscriptionFee < b.subscriptionFee;
    });
}

Tariff* MobileCompany::findTariff(double minFee, double maxFee) {
    for (auto& tariff : tariffs) {
        if (tariff.subscriptionFee >= minFee && tariff.subscriptionFee <= maxFee) {
            return &tariff;
        }
    }
    return nullptr;
}

void MobileCompany::displayTariffs() const {
    for (const auto& tariff : tariffs) {
        tariff.display();
    }
}