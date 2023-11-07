#include "AnimalDB.h"

AnimalDB::AnimalDB():current_inventory_size(0),current_cart_size(0) {}

int AnimalDB::getCurrentInventorySize() const {
    return current_inventory_size;
}

int AnimalDB::getNumChoices() const {
    return current_cart_size;
}

AnimalDB::AnimalDB(const AnimalDB & old) {
    Animal new_inventory[MAX_SIZE];
    Animal new_user_choices[MAX_SIZE];

    // init the size filed
    this->current_inventory_size = old.current_inventory_size;
    this->current_cart_size = old.current_cart_size;

    int max_iter = (current_inventory_size - current_cart_size) > 0 ? current_inventory_size: current_cart_size;

    // copy the value of arrays
    for (int i = 0; i < max_iter; ++i) {
        if (i < current_inventory_size){
            new_inventory[i] = old.inventory[i];

        }
        if (i < current_cart_size){
            new_user_choices[i] = old.cart[i];
        }
    }


}

Animal AnimalDB::getUserAnimal(int index) const{
    if (index < 0 || index >= current_cart_size){
        cerr << "Index is out of bound!" << endl;
        exit(1);
    }

    return cart[index];
}

Animal AnimalDB::getDonnaAnimalById(int ID) {
    // Check through the inventory
    for (int i = 0; i < current_inventory_size; ++i) {
        Animal animal = inventory[i];

        // if the ID is match then return that animal
        if (animal.getID() == ID) return animal;
    }

}


double AnimalDB::getCurrentTotal() const{
    double total_price = 0;

    // Loop through the cart and cumulatively add each  item's price to the total
    for (int i = 0; i < current_cart_size; ++i) {
        total_price += cart[i].getPrice();
    }

    // return the price
    return total_price;
}


bool AnimalDB::insertDonnaAnimal(Animal& animal) {
    // check the inventory if full
    if (current_inventory_size >= MAX_SIZE){
        cout << "Inventory is full" << endl;
        return false;
    }


    // add the animal while increasing the current size
    animal.setID(current_inventory_size + 1);
    inventory[current_inventory_size++] = animal;

    return true;

}

bool AnimalDB::insertUserAnimal(const Animal &animal) {
    // check the inventory if full
    if (current_cart_size >= MAX_SIZE){
        cout << "Cart is full" << endl;
        return false;
    }

    // add the animal while increasing the current size
    cart[current_cart_size++] = animal;

    return true;

}


bool AnimalDB::printInventory() {
    if (current_inventory_size == 0) {
        return false;
    }
    else{
        // print each animal
        for (int i = 0; i < current_inventory_size; ++i) {
            inventory[i].print();
            cout << endl;
        }
    }
    return true;
}

bool AnimalDB::printCart() {
    if (current_cart_size == 0) {
        return false;
    }
    else{
        // print each animal
        for (int i = 0; i < current_cart_size; ++i) {
            cart[i].print();
            cout << endl;
        }
    }
    return true;
}


bool AnimalDB::getDonnaAnimalByType(std::string _type) {
    bool isFoundAny = false;

    // Check through the inventory and if type is matched print the animal
    for (int i = 0; i < current_inventory_size; ++i) {
        Animal animal = inventory[i];

        if (animal.getType() == _type){
            animal.print();
            cout << endl;
            isFoundAny = true;
        }
    }
    return isFoundAny;
}


bool AnimalDB::getDonnaAnimalByWeight(double min_weight, double max_weight) {
    bool isFoundAny = false;

    // Check through the inventory and if type is matched print the animal
    for (int i = 0; i < current_inventory_size; ++i) {
        Animal animal = inventory[i];

        if (animal.getWeight() >= min_weight && animal.getWeight() <= max_weight){
            animal.print();
            cout << endl;
            isFoundAny = true;
        }
    }
    return isFoundAny;
}


bool AnimalDB::getDonnaAnimalByAge(int min_age, int max_age) {
    bool isFoundAny = false;

    // Check through the inventory and if type is matched print the animal
    for (int i = 0; i < current_inventory_size; ++i) {
        Animal animal = inventory[i];

        if (animal.getAge() >= min_age && animal.getAge() <= max_age){
            animal.print();
            cout << endl;
            isFoundAny = true;
        }
    }
    return isFoundAny;
}

bool AnimalDB::getDonnaAnimalByPrice(double _price) {
    bool isFoundAny = false;

    // Check through the inventory and if type is matched print the animal
    for (int i = 0; i < current_inventory_size; ++i) {
        Animal animal = inventory[i];

        if (animal.getPrice() == _price){
            animal.print();
            cout << endl;
            isFoundAny = true;
        }
    }
    return isFoundAny;
}


bool AnimalDB::getDonnaAnimalByParam(int ID, const std::string _type, double _weight, int _age) {
    bool isFoundAny = false;

    // Check through the inventory and if type is matched print the animal
    for (int i = 0; i < current_inventory_size; ++i) {
        Animal animal = inventory[i];

        if (animal.getID() == ID && animal.getType() == _type && animal.getWeight() == _weight && animal.getAge() ==_age){
            animal.print();
            cout << endl;
            isFoundAny = true;
        }
    }
    return isFoundAny;
}