#include <iostream>
#include <fstream>
#include "Network.hpp"
#include "Account.hpp"

using namespace std;

template<class itemType>
Network<itemType>::Network():item_count(0){
}

/**
        Accessor function
        @return : int - the current size of the network (number of items in the array)
*/
template<class itemType>
int Network<itemType>::getSizeOfNetwork() const {
    return this->item_count;
}

/**
     @return : bool - true if the bag is empty, false otherwise
*/
template<class itemType>
bool Network<itemType>::isEmpty(){
    return item_count == 0;
}

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

template<class itemType>
bool Network<itemType>::addAccount(itemType * entryItem) {
    bool has_room = (item_count < DEFAULT_CAPACITY);
    if (has_room)
    {
        for (int i = 0; i < item_count; ++i) {
            if (itemArray[i]->getUsername() == entryItem->getUsername()){
                return false;
            }
        }
        itemArray[item_count] = entryItem;
        item_count++;
        entryItem->setNetwork(this);
        return true;

    } // end if
    return false;
}


template<class itemType>
bool Network<itemType>::removeAccount(const itemType * an_entry) {
    int found_index = getIndexOf(an_entry->getUsername());
    bool can_remove = !isEmpty() && (found_index > -1);
    if (can_remove)
    {
        item_count--;
        itemArray[found_index] = itemArray[item_count];
    } // end if
    return can_remove;
} // end remove


template<class ItemType>
void Network<ItemType>::clear(){
    item_count = 0;
} // end clear

template<class ItemType>
bool Network<ItemType>::containsAccount(const ItemType * searchItem) {
    return getIndexOf(searchItem->getUsername()) > -1;
} // end contains



template<class ItemType>
int Network<ItemType>::getIndexOf(string username) const
{
    bool found = false;
    int result = -1;
    int search_index = 0;
// If the bag is empty, item_count_ is zero, so loop is skipped
    while (!found && (search_index < item_count))
    {
        if (itemArray[search_index]->getUsername() == username)
        {
            found = true;
            result = search_index;
        }else
        {
            search_index++;
        } // end if
    } // end while
    return result;
} // end getIndexOf

template<class itemType>
void Network<itemType>::populateNetwork(string filename) {
    // create an object of the fstream with given file name
    ifstream fin(filename);

    // Check the status of the file
    if (fin.fail()){

        cerr << "Error opening input file!" << endl;
        exit(1);
    }

    string username;
    string password;
    string line;
    do {

        getline(fin,line);
        size_t spaceIndex = line.find(' ');
        size_t new_line = line.find('\n');

        if (line == ";"){
            break;
        }
        if (spaceIndex == -1){
            cout << "Improper Format" << endl;
            exit(1);
        }

        username = line.substr(0,spaceIndex);
        password = line.substr(spaceIndex+1,new_line);

        if (username.empty() || password.empty() || password == " "){
            cout << "Improper Format" << endl;
            exit(1);
        }


        this->addAccount(new Account(username,password));

    } while (true);
}


template<class itemType>
void Network<itemType>::operator-=(Network<itemType> secondNetwork) {
    for (int i = 0; i < secondNetwork.getSizeOfNetwork() ; ++i) {
        if (this->containsAccount(secondNetwork.itemArray[i])){
            this->removeAccount(secondNetwork.itemArray[i]);
        }
    }
}


template<class itemType>
void Network<itemType>::printFeedForAccount(itemType item) {

    for (int i = 0; i < item.getFollowers().size(); ++i) {
        string tempUsername = item.getFollowers().at(i);


        for (int j = 0; j < feed.getSize(); ++j) {
            if (feed.getAtPos(j)->getItem()->getUsername() == tempUsername){

                feed.getAtPos(j)->getItem()->displayPost();
            }
        }


    }

}


template<class itemType>
bool Network<itemType>::authenticateFollow(itemType item, string username) {
    vector<string> followers = item.getFollowers();


    for (auto & follower : followers) {
        if (username ==  follower){
            if (this->getIndexOf(username) == -1 && this->getIndexOf(item.getUsername()) ==  -1){
                return true;
            }
            break;
        }
    }
    return false;
}


template<class itemType>
bool Network<itemType>::addToFeed(Post post) {
    if (post.getUsername().empty()){
        return false;
    }
    feed.insert(&post,0);
    return true;
}

/**
    @param            :   A string (word or phrase, case-sensitive) passed by reference
    @return           :   The number of items removed from the list

    This function will look through the body and title of all Posts in the Network's feed.
    If a Post contains the provided word or phrase, then it must be removed from the Network's `feed_` as well as the Account's `posts_`.

    You are encouraged to create your own helper functions for this endeavour.
    */
template<class ItemType>
int Network<ItemType>::removeIfContains(string& word){

    int count = 0;
    // go through the posts list (Linked list)
    for (int i = 0; i <feed.getSize() ; ++i) {
        // Hold the temp post
        Post * post = feed.getAtPos(i)->getItem();

        // check the given word is found
        if (post->getBody().find(word) != string::npos || post->getTitle().find(word) != string::npos){
            getAccount(post->getUsername())->removeFromPosts(word);
            this->feed.remove(i);   // remove the post
            count++;
        }

    }
    return count;
}


/**
    @param            :   A string (User name of the account)
    @return           :   pointer of the account

    This function will look through the username of all accounts in the Network's accounts and return the account.

   */

template<class ItemType>
ItemType * Network<ItemType>::getAccount(string username){
    for(int i = 0; i < getSizeOfNetwork(); i++){
        if (itemArray[i]->getUsername() == username){
            return itemArray[i];
        }
    }
}

template <class ItemType>
void Network<ItemType>::updatePost(Post * post,string &title,string &body){
    for (int i = 0; i < feed.getSize(); ++i) {
        if (post->getTitle() == feed.getAtPos(i)->getItem()->getTitle()){
            feed.getAtPos(i)->getItem()->setTitle(title);
            feed.getAtPos(i)->getItem()->setBody(body);
            feed.getAtPos(i)->getItem()->setTimeStamp();
            Post * post1 = feed.getAtPos(i)->getItem();
            feed.moveItemToTop(post1);

            break;
        }
    }

}

template <class ItemType>
bool Network<ItemType>::removePostFromNetwork(Post *post) {
    for (int i = 0; i < feed.getSize(); ++i) {
        if (post->getTitle() == feed.getAtPos(i)->getItem()->getTitle()){
            feed.remove(i);
            return true;
        }
    }
    return false;
}




// Just for resolve the linker errors
template class Network<Account>;
template class Node<Post*>;
template class LinkedList<Post*>;

