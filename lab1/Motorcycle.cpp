#include "Motorcycle.h"

Motorcycle::Motorcycle() : Base("","","Motorcycle"), engineVolume(0.0), enginePower(0.0), terrainType("") {std::cout << "Motorcycle default constructor" << std::endl;}

Motorcycle::Motorcycle(std::string brand, std::string model, double engineVolume, double enginePower, std::string terrainType) : Base(brand, model,"Motorcycle") {
    this->engineVolume = engineVolume;
    this->enginePower = enginePower;
    this->terrainType = terrainType;
    std::cout << "Motorcycle constructor" << std::endl;
}

Motorcycle::Motorcycle(const Motorcycle& other) : Base(other.brand, other.model,other.type) {
    this->engineVolume = other.engineVolume;
    this->enginePower = other.enginePower;
    this->terrainType = other.terrainType;
    std::cout << "Motorcycle copy constructor" << std::endl;
}

Motorcycle::~Motorcycle() {
    std::cout << "Motorcycle destructor" << std::endl;
}

double Motorcycle::getEngineVolume() {
    return engineVolume;
}

double Motorcycle::getEnginePower() {
    return enginePower;
}

std::string Motorcycle::getTerrainType() {
    return terrainType;
}

void Motorcycle::setEngineVolume(double engineVolume) {
    this->engineVolume = engineVolume;
}

void Motorcycle::setEnginePower(double enginePower) {
    this->enginePower = enginePower;
}

void Motorcycle::setTerrainType(std::string terrainType) {  
    this->terrainType = terrainType;
}

void Motorcycle::print() {\
    std::cout << "Motorcycle:" << std::endl;
    std::cout<<"\t" << "Brand: " << getBrand() << std::endl;
    std::cout<<"\t" << "Model: " << getModel() << std::endl;      
    std::cout<<"\t" << "Engine volume: " << getEngineVolume() << std::endl;
    std::cout<<"\t" << "Engine power: " << getEnginePower() << std::endl;
    std::cout<<"\t" << "Terrain type: " << getTerrainType() << std::endl;
}   

std::string Motorcycle::serialize() {
    return ("Motorcycle," + brand + "," + model + "," + std::to_string(engineVolume) + "," + std::to_string(enginePower) + "," + terrainType);
}