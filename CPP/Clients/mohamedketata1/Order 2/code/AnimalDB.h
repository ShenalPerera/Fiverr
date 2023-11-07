
#ifndef CODE_ANIMALDB_H
#define CODE_ANIMALDB_H

#include "Animal.h"

const int MAX_SIZE = 100;

class AnimalDB {
private:
    int current_inventory_size;
    int current_cart_size;
    Animal inventory[MAX_SIZE];
    Animal cart[MAX_SIZE];

public:
    AnimalDB();

    AnimalDB(const AnimalDB &old);

    int getCurrentInventorySize() const;

    int getNumChoices() const;

    Animal getUserAnimal(int index) const;

    Animal getDonnaAnimalById(int ID);

    double getCurrentTotal() const;

    bool insertDonnaAnimal(Animal& animal);

    bool insertUserAnimal(const Animal& animal);

    bool printInventory();

    bool printCart();

    bool getDonnaAnimalByType(string _type);

    bool getDonnaAnimalByWeight(double min_weight,double max_weight);

    bool getDonnaAnimalByAge(int min_age,int max_age);

    bool getDonnaAnimalByPrice(double _price);

    bool getDonnaAnimalByParam(int _ID,const string _type, double _weight, int _age);

};


#endif //CODE_ANIMALDB_H
