#pragma once
#include "Keeper.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
class Garage {
private:
    Keeper keeper;
public:
    Garage();
    ~Garage();
    void addCar(std::string brand="", std::string model="", double engineVolume=0, std::string color="", TransmissionType transmissionType=MANUAL);
    void addMotorcycle(std::string brand="", std::string model="", double engineVolume=0, double enginePower=0, std::string terrainType="");
    void addBus(std::string brand="", std::string model="", int passengerCapacity=0, int seatCount=0, std::string endPoint="");
    void deleteElement(int id);
    void printAll();
    void saveToFile();
    void loadFromFile();
};