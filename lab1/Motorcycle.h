#pragma once
#include "Base.h"

class Motorcycle : public Base{
private:
    double engineVolume;
    double enginePower;
    std::string terrainType;
public:
    Motorcycle();
    Motorcycle(std::string brand, std::string model, double engineVolume, double enginePower, std::string terrainType);
    Motorcycle(const Motorcycle& other);
    ~Motorcycle() override;
    double getEngineVolume();
    double getEnginePower();
    std::string getTerrainType();
    void setEngineVolume(double engineVolume);
    void setEnginePower(double enginePower);
    void setTerrainType(std::string terrainType);
    void print() override;
    std::string  serialize() override;
};