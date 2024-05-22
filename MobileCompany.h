#ifndef MOBILECOMPANY_H
#define MOBILECOMPANY_H

#include <vector>
#include "Tariff.h"

class MobileCompany {
private:
    std::vector<Tariff> tariffs;

public:
    void addTariff(const Tariff& tariff);
    int getTotalClients() const;
    void sortTariffsByFee();
    Tariff* findTariff(double minFee, double maxFee);
    void displayTariffs() const;
};

#endif // MOBILECOMPANY_H