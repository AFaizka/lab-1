#include "Bus.h"

Bus::Bus(){
    std::cout << "Bus default constructor" << std::endl;
    model = "";
    brand = "";
    type = "Bus";
    passengerCapacity = 0;
    seatCount = 0;
    endPoint = "";
}


Bus::Bus(std::string brand, std::string model, int passengerCapacity, int seatCount, std::string endPoint){
    std::cout << "Bus constructor" << std::endl;
    this->brand = brand;
    this->model = model;
    this->type = "Bus";
    this->passengerCapacity = passengerCapacity;
    this->seatCount = seatCount;
    this->endPoint = endPoint;
}

Bus::Bus(const Bus& other){
    std::cout << "Bus copy constructor" << std::endl;
    brand = other.brand;
    model = other.model;
    passengerCapacity = other.passengerCapacity;
    seatCount = other.seatCount;
    endPoint = other.endPoint;    
}

Bus::~Bus(){
    std::cout << "Bus destructor" << std::endl;
}

int Bus::getPassengerCapacity(){    
    return passengerCapacity;
}

int Bus::getSeatCount(){
    return seatCount;
}

std::string Bus::getEndPoint(){
    return endPoint;
}

void Bus::setPassengerCapacity(int passengerCapacity){
    this->passengerCapacity = passengerCapacity;
}

void Bus::setSeatCount(int seatCount){    
    this->seatCount = seatCount;
}

void Bus::setEndPoint(std::string endPoint){
    this->endPoint = endPoint;
}

void Bus::print(){
    std::cout << "Bus:" << std::endl;
    std::cout<<"\t" << "Brand: " << getBrand() << std::endl;
    std::cout<<"\t" << "Model: " << getModel() << std::endl;
    std::cout<<"\t" << "Passenger capacity: " << getPassengerCapacity() << std::endl;
    std::cout<<"\t" << "Seat count: " << getSeatCount() << std::endl;
    std::cout<<"\t" << "End point: " << getEndPoint() << std::endl;
}
std::string Bus::serialize(){
    return ("Bus," + brand + "," + model + "," + std::to_string(passengerCapacity) + "," + std::to_string(seatCount) + "," + endPoint);
}