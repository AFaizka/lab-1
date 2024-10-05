#pragma once
#include "Base.h"
#include <fstream>

class Keeper{
private:
    Base** array;
    int size;
    int capacity;
    std::string getSubstr(std::string&, char);
    void resize(bool);
    void resize(int);
public:
    Keeper();
    Keeper(Base** array, int size);
    Keeper(const Keeper& other);
    ~Keeper();
    void addElement(Base* element);
    void removeElement(int index);
    Base* getElement(int index);
    int getSize();
    void setSize(int size);
    void clear();
    void saveToFile();
    void loadFromFile();

};