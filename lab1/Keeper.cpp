#include "Keeper.h"
#include "Car.h"
#include "Bus.h"
#include "Motorcycle.h"

Keeper::Keeper() {
    std::cout << "Keeper default constructor" << std::endl;
    size=0;
    capacity=8;
    array = new Base*[capacity];
}
Keeper::Keeper(Base** array, int size) {
    std::cout << "Keeper constructor" << std::endl;
    this->capacity = 8;
    this->array = new Base*[capacity];
    resize(size);
    for (int i = 0; i < size; i++) {
        this->array[i] = array[i];
    }
}

Keeper::Keeper(const Keeper& other) {
    std::cout << "Keeper copy constructor" << std::endl;
    size = other.size;
    capacity = other.capacity;
    array = new Base*[capacity];
    for (int i = 0; i < size; i++) {
        array[i] = other.array[i];
    }
}

void Keeper::resize(int newSize) {
    int diff = newSize - this->size;
    bool need  = diff>0 ? capacity < newSize : capacity/2 > newSize;
    while(need) {
        if(!(diff<0 && capacity==8)){
            resize((diff>0));
        }

        need  = diff>0 ? capacity < newSize : capacity/2 > newSize;
   }
}

void Keeper::resize(bool dir){
    capacity = dir ? capacity * 2 : capacity / 2;
    Base** newArray = new Base*[capacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}
Keeper::~Keeper() {
    for (int i = 0; i < size; i++) {
        delete array[i];
    }
    delete[] array;
    std::cout << "Keeper destructor" << std::endl;
}

void Keeper::addElement(Base* element) {
    resize(size+1);
    array[size] = element;
    size++;
}

void Keeper::removeElement(int index) {
    if(index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    delete array[index];
    for(int i = index; i < size - 1; i++) {
        array[i] = array[i+1];
    }
    size--;
    resize(size-1);
}

Base* Keeper::getElement(int index) {
    if(index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

int Keeper::getSize() {
    return size;
}

void Keeper::setSize(int size) {
    this->size = size;  
}

void Keeper::clear() {
    for(int i = 0; i < size; i++) {
        delete array[i];
    }
    size = 0;
    capacity = 8;
}

void Keeper::saveToFile() {
    std::ofstream file("Keeper.txt");
    if(!file.is_open()) {
        throw std::runtime_error("File not opened");
    }
    file << size << std::endl;
    for (int i = 0; i < size; i++) {
        file<<array[i]->serialize()<<std::endl;
    }
    file.close();

}

std::string Keeper::getSubstr(std::string& line, char separator){
    int index = line.find(separator);
    if(index == -1) {
        return line;
    }
    std::string result  = line.substr(0, index);
    line.erase(0, index + 1);
    return result;
}
void Keeper::loadFromFile() {
    std::ifstream file("Keeper.txt");
    if(!file.is_open()) {
        throw std::runtime_error("File not opened");
    }
    int newSize;
    std::string newSizeStr;
    std::getline(file, newSizeStr);
    newSize = std::stoi(newSizeStr);
    clear();
    resize(newSize);
    
    std::string type;
    std::string brand;
    std::string model;
    double engineVolume;
    std::string color;
    bool transmissionType;
    double enginePower;
    std::string terrainType;
    int passengerCapacity;
    int seatCount;
    std::string endPoint;

    std::string line;
    for (int i = 0; i < newSize; i++) {
        std::getline(file, line);
        type = getSubstr(line, ',');
        if(type == "Car") {
            brand = getSubstr(line, ',');
            model = getSubstr(line, ',');
            engineVolume = std::stod(getSubstr(line, ','));
            color = getSubstr(line, ',');
            transmissionType = std::stoi(getSubstr(line, ','));
            Car* car = new Car(brand, model, engineVolume, color, TransmissionType(transmissionType));
            array[i] = car;
            size++;
        }else if(type == "Motorcycle") {
            brand = getSubstr(line, ',');
            model = getSubstr(line, ',');
            engineVolume = std::stod(getSubstr(line, ','));
            enginePower = std::stod(getSubstr(line, ','));
            terrainType = getSubstr(line, ','); 
            Motorcycle* motorcycle = new Motorcycle(brand, model, engineVolume, enginePower, terrainType);
            array[i] = motorcycle;
            size++;
        }else if(type == "Bus") {
            brand = getSubstr(line, ',');
            model = getSubstr(line, ',');
            passengerCapacity = std::stoi(getSubstr(line, ','));
            seatCount = std::stoi(getSubstr(line, ','));
            endPoint = getSubstr(line, ',');
            Bus* bus = new Bus(brand, model, passengerCapacity, seatCount, endPoint);
            array[i] = bus;
            size++;
        }
    }
    file.close();
}

