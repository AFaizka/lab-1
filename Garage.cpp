#include "Garage.h"

Garage::Garage():keeper() {
}

Garage::~Garage() {
}


void Garage::addCar(std::string brand, std::string model, double engineVolume, std::string color, TransmissionType transmissionType) {
    keeper.addElement(new Car(brand, model, engineVolume, color, transmissionType));
}

void Garage::addMotorcycle(std::string brand, std::string model, double engineVolume, double enginePower, std::string terrainType) {
    keeper.addElement(new Motorcycle(brand, model, engineVolume, enginePower, terrainType));
}

void Garage::addBus(std::string brand, std::string model, int passengerCapacity, int seatCount, std::string endPoint) {
    keeper.addElement(new Bus(brand, model, passengerCapacity, seatCount, endPoint));
}

void Garage::printAll() {
    std::cout << "Garage:" << "total vehicles " << keeper.getSize() << std::endl;
    std::cout<<"=========================="<<std::endl;
    for(int i = 0; i < keeper.getSize(); i++) {
        std::cout << "Vehicle " << i + 1 << std::endl;
        keeper.getElement(i)->print();
        std::cout<<"=========================="<<std::endl;
    }
}

void Garage::saveToFile() {
    keeper.saveToFile();
    std::cout << "Garage saved" << std::endl;

}

void Garage::loadFromFile() {
    keeper.loadFromFile();
    std::cout << "Garage loaded" << std::endl;
}

void Garage::deleteElement(int id) {
    if(id < 1 || id >keeper.getSize()) {
        throw std::out_of_range("Index out of range");
    }
    keeper.removeElement(id+1);
}