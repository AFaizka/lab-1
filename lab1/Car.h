#pragma once
#include "Base.h"
enum TransmissionType
{
    MANUAL,
    AUTOMATIC
};
class Car: public Base{
private:   
    double engineVolume;
    std::string color;
    TransmissionType transmissionType;

public:
    Car();
    Car(std::string brand, std::string model, double engineVolume, std::string color, TransmissionType transmissionType);
    Car(const Car& other);
    ~Car();
    double getEngineVolume();
    std::string getColor();
    TransmissionType getTransmissionType();
    void setEngineVolume(double engineVolume);
    void setColor(std::string color);
    void setTransmissionType(TransmissionType transmissionType);
    void  print() override;
    std::string  serialize() override;
};