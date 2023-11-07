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

void writeFile(const string filename, const AnimalDB &animals) {
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
    AnimalDB animals;

    // Populate the database
    readFile("DonnaInvenroey.txt",animals);
    string type;
    double lower_limit,upper_limit;
    int low_age,max_age;
    int ID;

    Animal animal;

    // user's choice
    char user_choice;
    do {

        printMenu();
        user_choice = getUserChoice();

        // handle the option
        switch (user_choice) {
            case '1':
                if (!animals.printInventory()) cout << "Inventory is empty\n\n";
                break;
            case '2':
                if (!animals.printCart()) cout << "Cart is Empty\n\n";
                break;
            case '3':
                // get the type from the user
                cout << "Enter the type of the animal : ";
                cin >> type;
                if (!animals.getDonnaAnimalByType(type)) cout << "No animal found in given type!\n\n";
                break;

            case '4':
                // get the type from the user
                cout << "Enter the lower weight limit : ";
                cin >> lower_limit;

                cout << "Enter the upper weight limit : ";
                cin >> upper_limit;


                if (!animals.getDonnaAnimalByWeight(lower_limit,upper_limit)) cout << "No animal found in given weight range!\n\n";
                break;

            case '5':
                cout << "Enter the maximum age limit : ";
                cin >> low_age;

                cout << "Enter the minimum age limit : ";
                cin >> max_age;

                if (!animals.getDonnaAnimalByAge(low_age,max_age)) cout << "No animal found with given ages\n\n";
                break;

            case '6':
                cout << "Enter the ID of the animal : ";
                cin >> ID;
                animal = animals.getDonnaAnimalById(ID);

                if (!animal.getType().empty()){
                    if (!animals.insertUserAnimal(animal)){
                        cout << "Can not insert the animal\n\n";
                    }
                }
                else{
                    cout << "No animal found by the ID\n\n";
                }
                break;

            case '7':
                cout << "Your current cart total : $" << animals.getCurrentTotal() << endl;
                break;

            case '8':
                break;

            default:
                cout << "Invalid input\n\n";
                break;
        }
    } while (user_choice != '8');


    writeFile("receipt.txt",animals);
    return 0;
}