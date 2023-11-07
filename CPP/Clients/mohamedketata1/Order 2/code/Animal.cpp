#include "Animal.h"


Animal::Animal() {}

Animal::Animal(int id, const string &type, double weight, int age, double price) : id(id), type(type), weight(weight),age(age), price(price) {}

Animal::Animal(const Animal &old) {
    this->id = old.id;
    this->type = old.type;
    this->weight = old.weight;
    this->age = old.age;
    this->price = old.price;
}


Animal::~Animal() {

}

int Animal::getID() const {
    return id;
}

void Animal::setID(int _id) {
    Animal::id = _id;
}

const string &Animal::getType() const {
    return type;
}

void Animal::setType(const string &_type) {
    Animal::type = _type;
}

double Animal::getWeight() const {
    return weight;
}

void Animal::setWeight(double _weight) {
    Animal::weight = _weight;
}

int Animal::getAge() const {
    return age;
}

void Animal::setAge(int _age) {
    Animal::age = _age;
}

double Animal::getPrice() const {
    return price;
}

void Animal::setPrice(double _price) {
    Animal::price = _price;
}

void Animal::print() {
    cout << id << endl;
    cout << type << endl;
    cout << weight << " kg\n";
    cout << age << " years old\n";
    cout << "$" << price << endl;
}


