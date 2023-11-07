#ifndef CODE_NETWORK_HPP
#define CODE_NETWORK_HPP
#include <vector>

#include "Post.hpp"

using namespace std;

template<class itemType>

class Network {

protected:
    static const int DEFAULT_CAPACITY = 200;

private:
    itemType * itemArray[2000];
    int item_count;
    vector<Post> feed;

    int getIndexOf(string username) const;

public:
    /**
    Default constructor.
    Initializes private variables to default initial values. */
    Network();
    /**
        Accessor function
        @return : int - the current size of the network (number of items in the array)
    */
    int getSizeOfNetwork() const;

    /**
        @return : bool - true if the bag is empty, false otherwise
    */
    bool isEmpty();

    /**
        @param : a POINTER to the item that will be added to the Network
        @return : bool- true if the item was successfully added, false otherwise
        @post : stores a pointer to the item, if there is room. This is a network
        specific function,
        it has an additional constraint: the item will be added only if no other
        item in the network
        has the same username (usernames are considered unique)
        REMEMBER WE ARE STORING POINTERS TO ITEMS, NOT ITEMS.
        Finally, the Account being added to the network will update it's private
        member to point to this network
        (see Account class modifications below, you may come back and
        implement this feature after
        you work on Task 2, but don't forget!!!).
        NOTE: every object in C++ has access to a pointer to itself called `this`,
        thus the nework can pass `this` pointer to the account!
    */
    bool addAccount(itemType * entryItem);

    /**
        Mutator function
        @param : a POINTER to the item that will be removed from Network
        @return : true if if the item was successfully removed, false otherwise
        @post : updates the bag/network to remove the pointer, if a pointer to that
                item was found.
    */

    bool removeAccount(const itemType * an_entry);

    /**
        Mutator function
        @post : Empties the bag/network
    */
    void clear();

    /**
        @param : a POINTER to the item to find
        @return : true if the item was successfully found, false otherwise
    */
    bool containsAccount(const itemType * searchItem);

    /**
        Mutator function
        @param : the name of an input file
        @pre : The format of the text file is as follows:
        username password
        username password
        ;
        where ';' signals the end of the file. Check the provided example
        (accounts.txt).
        @post : Reads every line in the input file, creates an Account from that
        information and
        adds the Account to the network. If a line of input is missing some
        required information,
        it prints out "Improper Format" and terminates.
        Keep in mind that, although the input will always be an Account, the
        Network class is
        a template, thus it will store a pointer to a generic type. It will do so by
        creating a new
        dynamic object of type ItemType but passing the account information
        (username and password)
        as to the Account constructor. This is a bit hacky, but it will work for
        our Network.
     */
    void populateNetwork(string filename);

    /**
        Mutator function
        @param : a reference to another Network
        @post : Removes from the Network any items that also appear in the other
        Network.
        In other words, removes elements from the network on the left of the
        operator that
        are also found in the network on the right of the operator.
        Why is this useful? For example, given a network of known bot accounts, remove all
        bots from this Network.
    */
    void operator-=(Network<itemType> secondNetwork);

    void printFeedForAccount(itemType item);

    bool authenticateFollow(itemType item, string username);

    bool addToFeed(Post post);

};


#endif //CODE_NETWORK_HPP
