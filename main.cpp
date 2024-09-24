#include <iostream>
#include <string>
#include <vector>

class Appliance {
protected:
    std::string brand;
    double powerUsage;

public:
    Appliance(const std::string& brand, double powerUsage)
        : brand(brand), powerUsage(powerUsage) {}

    virtual void displayInfo() = 0;

    virtual ~Appliance() {
        std::cout << "Appliance destroyed: " << brand << std::endl;
    }
};

class WashingMachine : public Appliance {
private:
    double loadCapacity;

public:
    WashingMachine(const std::string& brand, double powerUsage, double loadCapacity)
        : Appliance(brand, powerUsage), loadCapacity(loadCapacity) {}

    void displayInfo() override {
        std::cout << "Washing Machine Brand: " << brand 
                  << ", Power Usage: " << powerUsage 
                  << "W, Load Capacity: " << loadCapacity << "kg" << std::endl;
    }

    ~WashingMachine() {
        std::cout << "WashingMachine destroyed: " << brand << std::endl;
    }
};

class Refrigerator : public Appliance {
private:
    double volume;

public:
    Refrigerator(const std::string& brand, double powerUsage, double volume)
        : Appliance(brand, powerUsage), volume(volume) {}

    void displayInfo() override {
        std::cout << "Refrigerator Brand: " << brand 
                  << ", Power Usage: " << powerUsage 
                  << "W, Volume: " << volume << " liters" << std::endl;
    }

    ~Refrigerator() {
        std::cout << "Refrigerator destroyed: " << brand << std::endl;
    }
};

void menu(std::vector<Appliance*>& appliances) {
    int choice;
    std::string brand;
    double powerUsage;

    do {
        std::cout << "\nMenu:\n"
                  << "1. Add Washing Machine\n"
                  << "2. Add Refrigerator\n"
                  << "0. Exit\n"
                  << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double loadCapacity;
                std::cout << "Enter brand, power usage, load capacity (kg): ";
                std::cin >> brand >> powerUsage >> loadCapacity;
                appliances.push_back(new WashingMachine(brand, powerUsage, loadCapacity));
                break;
            }
            case 2: {
                double volume;
                std::cout << "Enter brand, power usage, volume (liters): ";
                std::cin >> brand >> powerUsage >> volume;
                appliances.push_back(new Refrigerator(brand, powerUsage, volume));
                break;
            }
            case 0:
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);
}

int main() {
    std::vector<Appliance*> appliances;

    menu(appliances);

    std::cout << "\nAppliances List:\n";
    for (Appliance* appliance : appliances) {
        appliance->displayInfo();
    }

    for (Appliance* appliance : appliances) {
        delete appliance;
    }

    return 0;
}
