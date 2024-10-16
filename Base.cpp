#include "Base.h"

Base::Base() :brand(""), model(""),type("") {}
Base::Base(std::string brand, std::string model, std::string type) :brand(brand), model(model),type(type) {}
Base::Base(const Base& other) :brand(other.brand), model(other.model),type(other.type) {}
Base::~Base() {
std::cout << "Base destructor" << std::endl;
}

std::string Base::getBrand() {
    return brand;
}
std::string Base::getModel() {
    return model;
}
void Base::setBrand(std::string brand) {
    this->brand = brand;
}
void Base::setModel(std::string model) {
    this->model = model;
}
std::string Base::getType() {
    return type;
}
void Base::setType(std::string type) {
    this->type = type;
}