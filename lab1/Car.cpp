#include "Car.h"

Car::Car():Base("","","Car"), engineVolume(0), color(""), transmissionType(MANUAL) {std::cout << "Car default constructor" << std::endl;};


Car::Car(std::string brand, std::string model, double engineVolume, std::string color, TransmissionType transmissionType)
    :Base(brand, model,"Car"), engineVolume(engineVolume), color(color), transmissionType(transmissionType) { std::cout << "Car constructor" << std::endl; };

Car::Car(const Car& other) : Base(other), engineVolume(other.engineVolume), color(other.color), transmissionType(other.transmissionType) {
    std::cout << "Car copy constructor" << std::endl;
}
Car::~Car() {
    std::cout << "Car destructor" << std::endl;
}

double Car::getEngineVolume() {
    return engineVolume;
}    

std::string Car::getColor() {
    return color;
}

TransmissionType Car::getTransmissionType() {
    return transmissionType;
}

void Car::setEngineVolume(double engineVolume) {
    this->engineVolume = engineVolume;
}

void Car::setColor(std::string color) { 
    this->color = color;
}

void Car::setTransmissionType(TransmissionType transmissionType) {
    this->transmissionType = transmissionType;
}

void Car::print() {
    std::cout << "Car:" << std::endl;
    std::cout<<"\t" << "Brand: " << getBrand() << std::endl;
    std::cout<<"\t" << "Model: " << getModel() << std::endl;
    std::cout<<"\t" << "Engine volume: " << getEngineVolume() << std::endl;
    std::cout<<"\t" << "Color: " << getColor() << std::endl;
    std::cout<<"\t" << "Transmission type: " << (getTransmissionType()? "automatic" : "manual") << std::endl;
}

std::string Car::serialize() {
    return ("Car," + brand + "," + model + "," + std::to_string(engineVolume) + "," + color + "," + std::to_string(transmissionType));
}