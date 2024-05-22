#include <iostream>
#include "MobileCompany.h"
#include "Tariff.h"

void addTariffFromConsole(MobileCompany& company) {
    std::string name;
    double fee;
    int count;

    std::cout << "Enter tariff name: ";
    std::cin >> name;
    std::cout << "Enter subscription fee: ";
    std::cin >> fee;
    std::cout << "Enter clients count: ";
    std::cin >> count;

    company.addTariff(Tariff(name, fee, count));
}

void filterTariffsByFee(MobileCompany& company) {
    double minFee, maxFee;
    std::cout << "Enter minimum subscription fee: ";
    std::cin >> minFee;
    std::cout << "Enter maximum subscription fee: ";
    std::cin >> maxFee;

    Tariff* foundTariff = company.findTariff(minFee, maxFee);
    if (foundTariff) {
        std::cout << "Tariff found in the range [" << minFee << ", " << maxFee << "]:" << std::endl;
        foundTariff->display();
    }
    else {
        std::cout << "No tariff found in the range [" << minFee << ", " << maxFee << "]" << std::endl;
    }
}

int main() {
    MobileCompany company;
    int choice;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add new tariff\n";
        std::cout << "2. Display all tariffs\n";
        std::cout << "3. Sort tariffs by subscription fee\n";
        std::cout << "4. Filter tariffs by subscription fee\n";
        std::cout << "5. Display total clients\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addTariffFromConsole(company);
            break;
        case 2:
            company.displayTariffs();
            break;
        case 3:
            company.sortTariffsByFee();
            std::cout << "Tariffs sorted by subscription fee.\n";
            break;
        case 4:
            filterTariffsByFee(company);
            break;
        case 5:
            std::cout << "Total clients: " << company.getTotalClients() << std::endl;
            break;
        case 0:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}