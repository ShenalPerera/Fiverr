//============================================================================
// Name        : HashTable.cpp
// Author      : John Watson
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <climits>
#include <iostream>
#include <string> // atoi
#include <time.h>


#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

const unsigned int DEFAULT_SIZE = 179;

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};
void displayBid(Bid bid);
//============================================================================
// Hash Table class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a hash table with chaining.
 */
class HashTable {

private:
    // Define structures to hold bids
    struct Node {
        Bid bid;
        unsigned int key;
        Node *next;

        // default constructor
        Node() {
            key = UINT_MAX;
            next = nullptr;
        }

        // initialize with a bid
        Node(Bid aBid) : Node() {
            bid = aBid;
        }

        // initialize with a bid and a key
        Node(Bid aBid, unsigned int aKey) : Node(aBid) {
            key = aKey;
        }
    };

    vector<Node*> nodes;

    unsigned int tableSize = DEFAULT_SIZE;

    unsigned int hash(int key);

public:
    HashTable();
    HashTable(unsigned int size);
    virtual ~HashTable();
    void Insert(Bid bid);
    void PrintAll();
    void Remove(string bidId);
    Bid Search(string bidId);
};

/**
 * Default constructor
 */
HashTable::HashTable() {
    // FIXME (1): Initialize the structures used to hold bids
    this->nodes.resize(tableSize);
    // Initialize node structure by resizing tableSize

}

/**
 * Constructor for specifying size of the table
 * Use to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 */
HashTable::HashTable(unsigned int size) {
    // invoke local tableSize to size with this->
    // resize nodes size
    this->tableSize = size;
    this->nodes.resize(tableSize);
    cout << nodes.size();
}


/**
 * Destructor
 */
HashTable::~HashTable() {
    // FIXME (2): Implement logic to free storage when class is destroyed
    
    // erase nodes beginning
    for (int i = 0; i < tableSize; ++i) {
        // get the head of each linked list
        Node * current = nodes.at(i);

        while (current != nullptr){
            Node * temp = current;
            current = current->next;
            delete temp;
        }
    }
}

/**
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * @param key The key to hash
 * @return The calculated hash
 */
unsigned int HashTable::hash(int key) {
    // FIXME (3): Implement logic to calculate a hash value
    // return key tableSize
    return key % tableSize;
}

/**
 * Insert a bid
 *
 * @param bid The bid to insert
 */
void HashTable::Insert(Bid bid) {
    // FIXME (5): Implement logic to insert a bid
    // create the key for the given bid
    int key = stoi(bid.bidId);
    int hashKey = hash(key);


    // retrieve node using key
    Node* temp = nodes.at(hashKey);
    Node* newNode = new Node(bid,key);
    // if no entry found for the key
    if (temp == nullptr){

        // assign this node to the key position
        nodes.at(hashKey) = newNode;
    }
    // else if node is not used
    else if(temp->key == UINT_MAX){
        // assing old node key to UNIT_MAX, set to key, set old node to bid and old node next to null pointer
        temp->key = key;
        temp->bid = bid;
        temp->next = nullptr;
    }
        // else find the next open node
    else{
        // add new newNode to end
        Node * current = nodes.at(hashKey);
        while (current->next != nullptr) current = current->next;
        current->next =newNode;

    }


}

/**
 * Print all bids
 */
void HashTable::PrintAll() {
    // FIXME (6): Implement logic to print all bids
    // for node begin to end iterate
    for (int i = 0; i <tableSize; ++i) {
        Node * node = nodes.at(i);
        if (node == nullptr) continue;
        //   if key not equal to UINT_MAx
        if (node->key != UINT_MAX){
            // output key, bidID, title, amount and fund
            cout << "Key " <<hash(node->key) << ": "<<node->bid.bidId << " | " << node->bid.title << " | " << node->bid.amount << " | " << node->bid.fund << endl;
            // node is equal to next iter
            node = node->next;
            // while node not equal to nullptr
            while (node != nullptr){
                // output key, bidID, title, amount and fund

                cout << "    " << i << ": "<< node->bid.bidId<<" | " << node->bid.title << " | " << node->bid.amount << " | " << node->bid.fund << endl;
                // node is equal to next node
                node = node->next;
            }

        }

    }


}

/**
 * Remove a bid
 *
 * @param bidId The bid id to search for
 */
void HashTable::Remove(string bidId) {
    // FIXME (7): Implement logic to remove a bid
    // set key equal to hash atoi bidID cstring
    int key = hash(stoi(bidId));
    // erase node begin and key
    Node* temp = nullptr;
    Node* head = nodes.at(key);
    // if given position is null return
    if (head == nullptr) return;
    // if the table has only one entry set it as to null(only the head and match occurs in the head
    if (head->key == stoi(bidId)) {
        // get the head
        temp = nodes.at(key);
        // set the head position next node
        nodes.at(key) = nodes.at(key)->next;
        free(temp);
    }

    else{
        Node * current = nodes.at(key);
        // loop through the linked list(chain)
        while (current->next != nullptr){

            // check the given bidId is match with entry
            if (stoi(bidId) == current->next->key){
                // If the matching occur at the end
                current->next = current->next->next;
                free(temp);
                break;
            }
            current = current->next;
        }
    }
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid HashTable::Search(string bidId) {
    Bid bid;

    // FIXME (8): Implement logic to search for and return a bid

    // create the key for the given bid
    int key = hash(stoi(bidId));
    Node * current = nodes.at(key);

    while (current != nullptr){
        if (current->key == stoi(bidId)){
            return current->bid;
        }
        current = current->next;
    }
    // if entry found for the key
         //return node bid

    // if no entry found for the key
      // return bid
    // while node not equal to nullptr
        // if the current node matches, return it
        //node is equal to next node

    return bid;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, HashTable* hashTable) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            hashTable->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98109";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a hash table to hold all the bids
    HashTable* bidTable;

    Bid bid;
    bidTable = new HashTable();
    
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(csvPath, bidTable);

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bidTable->PrintAll();
            break;

        case 3:
            ticks = clock();

            bid = bidTable->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
                cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 4:
            bidTable->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
