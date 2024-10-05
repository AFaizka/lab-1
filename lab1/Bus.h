#pragma once
#include "Base.h"

class Bus: public Base{
private:
    int passengerCapacity;
    int seatCount;
    std::string endPoint;
public:
    Bus();
    Bus(std::string brand, std::string model, int passengerCapacity, int seatCount, std::string endPoint);
    Bus(const Bus& other);
    ~Bus();
    int getPassengerCapacity();
    int getSeatCount();
    std::string getEndPoint();  
    void setPassengerCapacity(int passengerCapacity);
    void setSeatCount(int seatCount);
    void setEndPoint(std::string endPoint);
    void print() override;
    std::string  serialize() override;
};