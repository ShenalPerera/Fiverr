#ifndef CODE_ANIMAL_H
#define CODE_ANIMAL_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Animal {
private:
    int id;
    string type;
    double weight;
    int age;
    double price;

public:
    // default constructor
    Animal();

    // Setter constructor
    Animal(int id, const string &type, double weight, int age, double price);

    // Copy constructor
    Animal(const Animal &old);

    ~Animal();

    int getID() const;

    void setID(int id);

    const string &getType() const;

    void setType(const string &type);

    double getWeight() const;

    void setWeight(double weight);

    int getAge() const;

    void setAge(int age);

    double getPrice() const;

    void setPrice(double price);

    void print();
};


#endif //CODE_ANIMAL_H
