#include "Animal.h"
#include "AnimalDB.h"

void readFile(const string filename, AnimalDB &animals) {
    // open file, check if failed
    ifstream din;
    din.open(filename.c_str());

    if (din.fail()) {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }

    // declare local temp. class variables for reading data
    int id = 1;
    string type;
    float weight;
    int age;
    float price;
    string extra;
    char dollar;

    while (!din.eof()) {
        // logic for reading in data, ignoring unwanted data
        din >> type >> weight;
        getline(din, extra);
        din >> age;
        getline(din, extra);
        din.get(dollar);
        din >> price;
        getline(din, extra);

        // define new Animal object and insert new animal into Donna's inventory
        Animal newAnimal(id++, type, weight, age, price);
        if (!din.eof())
            animals.insertDonnaAnimal(newAnimal);
    }
    din.close();
}

void writeFile(const string filename, AnimalDB animals) {
    // open file for output, check if failed
    ofstream dout;
    dout.open(filename.c_str());

    if (dout.fail()) {
        cout << "Error; file " << filename << " could not be opened" << endl;
        return;
    }

    // loop for each index in the userCart array, write data of each Animal object to output file in CSV formats
    for (int i = 0; i < animals.getNumChoices(); i++) {
        Animal currentAnimal = animals.getUserAnimal(i);
        dout << currentAnimal.getID() << ','
        << currentAnimal.getType() << ','
        << currentAnimal.getWeight() << ','
        << currentAnimal.getAge() << ','
        << currentAnimal.getPrice() << ',' << endl;
    }
    dout << ",,,," << animals.getCurrentTotal();
    dout.close();
}

void printMenu() {
    cout << "\nWelcome to Donna's Farm! Here are your choices:"
    << "\n1: Print all animals in Donna's inventory"
    << "\n2: Print your current shopping cart"
    << "\n3: Print animals of a certain type"
    << "\n4: Print animals within a range of weight"
    << "\n5: Print animals within a range of age"
    << "\n6: Add an animal to your shopping cart"
    << "\n7: Print your current shopping cart total"
    << "\n8: Complete your order, print receipt and exit the program\n";
}

char getUserChoice() {
    char userChoice = '\0';

    do {
        cout << "\nEnter menu selection: ";
        cin >> userChoice;
        if (userChoice < '1' || userChoice > '8')
            cout << "\nError: invalid input. Please try again." << endl;
    } while (userChoice < '1' || userChoice > '8');

    return userChoice;
}

int main() {
    //you will be writing this code!
    
    return 0;
}