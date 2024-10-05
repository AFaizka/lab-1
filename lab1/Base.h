#pragma once
#include <string>
#include <iostream>
class Base{
public:
    std::string brand;
    std::string model;
    std::string type;
public:
    Base();
    Base(std::string brand, std::string model,std::string type);
    Base(const Base& other);
    virtual ~Base();
    std::string getBrand();
    std::string getModel();
    void setBrand(std::string brand);
    void setModel(std::string model);
    std::string getType();
    void setType(std::string type);
    virtual void print()=0;
    virtual std::string serialize()=0;
};