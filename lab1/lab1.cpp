
#include <iostream>
#include "Keeper.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
#include "Garage.h"
void createElement(Garage& garage) {
    int choice;
    std::cout << "1. Car" << std::endl;
    std::cout << "2. Motorcycle" << std::endl;
    std::cout << "3. Bus" << std::endl;
    std::cin >> choice;
    int emptyChoice;
    std::cout <<"Create empty?"<< std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    std::cin >> emptyChoice;
    if(emptyChoice == 1){
        switch (choice) {
        case 1:
            garage.addCar();
            break;
        case 2:
            garage.addMotorcycle();
            break;
        case 3:
            garage.addBus();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }else if(emptyChoice == 2){
        switch (choice) {
        case 1:{
            std::cout << "Enter brand: ";
            std::string brand;
            std::cin >> brand;
            std::cout << "Enter model: ";
            std::string model;
            std::cin >> model;
            std::cout << "Enter engine volume: ";
            double engineVolume;
            std::cin >> engineVolume;
            std::cout << "Enter color: ";
            std::string color;
            std::cin >> color;
            std::cout << "Enter transmission type(0 - manual, 1 - automatic): ";
            bool transmissionType;
            std::cin >> transmissionType;
            garage.addCar(brand, model, engineVolume, color, TransmissionType(transmissionType));
            }
            break;
        case 2:{
            std::cout << "Enter brand: ";
            std::string brand;
            std::cin >> brand;
            std::cout << "Enter model: ";
            std::string model;
            std::cin >> model;
            std::cout << "Enter engine volume: ";
            double engineVolume;
            std::cin >> engineVolume;
            std::cout << "Enter engine power: ";
            double enginePower;
            std::cin >> enginePower;
            std::cout << "Enter terrain type: ";
            std::string terrainType;
            std::cin >> terrainType;
            garage.addMotorcycle(brand, model, engineVolume, enginePower, terrainType);
            }
            break;
        case 3:{
            std::cout << "Enter brand: ";
            std::string brand;
            std::cin >> brand;
            std::cout << "Enter model: ";
            std::string model;
            std::cin >> model;
            std::cout << "Enter passenger capacity: ";
            int passengerCapacity;
            std::cin >> passengerCapacity;
            std::cout << "Enter seat count: ";
            int seatCount;
            std::cin >> seatCount;
            std::cout << "Enter end point: ";
            std::string endPoint;
            std::cin >> endPoint;
            garage.addBus(brand, model, passengerCapacity, seatCount, endPoint);
            }
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    }
   
}

void deleteElement(Garage& garage) {
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;
    garage.deleteElement(index);
}



int main()
{
    Garage garage;
    int choice;
    while(true){
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Save" << std::endl;
        std::cout << "2. Load" << std::endl;
        std::cout << "3. Create" << std::endl;
        std::cout << "4. Delete" << std::endl;
        std::cout << "5. Print all" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            garage.saveToFile();
            break;
        case 2:
            garage.loadFromFile();
            break;
        case 3:
            createElement(garage);
            break;
        case 4:
            deleteElement(garage);
            break;
        case 5:
            garage.printAll();
            break;
        case 6:
            return 0;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    }

}


