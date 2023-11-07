/*
List class implementation for term projects
CSCI 235 Fall 2022
Hunter College
*/
#include <iostream>
#include "LinkedList.hpp"
#include "Account.hpp"

/* Default constructor*/
template<typename ItemType>
LinkedList<ItemType>::LinkedList() : head_{nullptr}, size_{0} {}



/* Destructor */
template<typename ItemType>
LinkedList<ItemType>::~LinkedList() {
    //clear();
}

/* @return  : the head pointer
This function is for grading purposes*/
template<typename ItemType>
Node<ItemType>* LinkedList<ItemType>::getHeadPtr() const {
    return head_;
}

/*
    @post   : removes all items from the caller list
**/
template<typename ItemType>
void LinkedList<ItemType>::clear() {
    Node<ItemType>* curr_item = head_;
    Node<ItemType>* temp = curr_item;
    for(int i = 0; i<size_; i++) {
        temp = curr_item;
        curr_item = curr_item->getNext();
        delete temp;
    }
    temp = nullptr;
    size_ = 0;
}

/*
    @param  item: the item to insert in the list
    @param  position: the position where to inserted
    @pre position is a valid place within the list, otherwise false will be returned
    @return   :  true if the item has been inserted in the caller list,
                false otherwise
    @post     : Inserts item in  list at  position

**/
template<typename ItemType>
bool LinkedList<ItemType>::insert(const ItemType& item, const int &position){
    if((position < 0 || position > size_)){
        return false;
    }

    Node<ItemType> *node = new Node<ItemType>();
    node->setItem(item);

    if(size_ == 0){
        head_ = node;
    }
    else {
        Node<ItemType> *iterator;

        if(position == 0){
            node->setNext(head_);
            head_ = node;
        }

        else if (position == size_){
            iterator = getAtPos(size_-1);
            iterator->setNext(node);
        }
        else {
            iterator = getAtPos(position-1);
            node->setNext(iterator->getNext());
            iterator->setNext(node);
        }
    }
    size_++;
    return true;
}

/*
    @param  position:  the position where to remove
    @pre position is a valid place within the list, otherwise false will be returned
    @pre      : returns true if the item at position has been removed from the list,
                false otherwise
    @post     : removes node at  position
**/
template <typename ItemType>
bool LinkedList<ItemType>::remove(const int&position) {
    if (position < 0 || position >= size_) {
        return false;
    }

    Node<ItemType> *iterator;

    if (position == 0){
        iterator = head_;
        head_ = head_->getNext();
    }
    else {
        iterator = getAtPos(position-1);
        iterator->setNext(iterator->getNext()->getNext());
        iterator = iterator->getNext();
    }

    size_--;
    return true;

}

/*
    @param   item : the item to find in the list
    @pre      : takes item object and checks if exist in list and return
    @return   : returns the position (index) of object in the list

**/
template<typename ItemType>
int LinkedList<ItemType>::getIndexOf(const ItemType &item) const {
    Node<ItemType>* curr_item = head_;
    int counter = 0;
    while(curr_item != nullptr) {
        if(curr_item->getItem() == item) {
            return counter;
        }
        counter++;
        curr_item = curr_item->getNext();
    }
    return -1;
}
/* @return  : the size of the list */
template<typename ItemType>
int LinkedList<ItemType>::getSize() const {
    return size_;
}
/* @return  : true if the list is empty, false otherwise */
template<typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return size_ == 0 ? true : false;
}
// PRIVATE METHODS

/*
    @param   pos : the position of the item
    @pre     : pos is a valid place in the list
    @return  : a pointer to the node at pos, if pos is invalid, returns nullptr
**/
template<typename ItemType>
Node<ItemType>* LinkedList<ItemType>::getAtPos(const int &pos) const {

    if(pos < 0 || pos >= size_) {
        return nullptr;
    }

    Node<ItemType>* curr_item = head_;
    int counter = 0;
    while(counter < pos && curr_item != nullptr) {
        counter++;
        curr_item = curr_item->getNext();
    }
    return curr_item;
}


/*
    A copy constructor
    @param            :   Another LinkedList passed by reference

    Initializes this LinkedList with the same items as the provided LinkedList
**/

//template<typename ItemType>
//LinkedList<ItemType>::LinkedList(const LinkedList<ItemType> &oldLinkedList) {
//    // copy the size
//    size_ = oldLinkedList.size_;
//
//    if (oldLinkedList.head_ == nullptr) {
//        head_ = nullptr;
//    }
//    else {
//        //copy all nodes of OldLinkedList to the caller object
//        //attach first node to the head of the caller object
//        Node<ItemType>* newNode = new Node<ItemType>();
//        newNode->setItem(oldLinkedList.head_->getItem());
//        newNode->setNext(nullptr);
//        head_ = newNode;
//
//        //Depp copy the other items
//        Node<ItemType>* pNode = oldLinkedList.head_->getNext();
//        Node<ItemType>* current = head_;
//        while (pNode != nullptr)
//        {
//            current->setNext(new Node<ItemType>());
//
//            current->getNext()->setItem(pNode->getItem());
//
//            current->getNext()->setNext(nullptr);
//
//            current = current->getNext();
//
//            pNode = pNode->getNext();
//        }
//    }
//}



template<typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList &list) : head_{nullptr}, size_{0} {
    if (!list.isEmpty()) {
        Node<ItemType> *copyHead = list.getHeadPtr();
        int counter = 0;

        while (counter < list.getSize()) {
            insert(copyHead->getItem(), counter);
            counter++;
            copyHead = copyHead->getNext();
        }
    }
}



/*
    A reversed copy function
    @param            :   Another LinkedList passed by reference

    Sets the current LinkedList with the same items as the provided LinkedList
    but in reverse order
*/

template <typename ItemType>
void LinkedList<ItemType>::reverseCopy(const LinkedList<ItemType> &a_list) {
    LinkedList<ItemType> newList(a_list);
    size_ = a_list.getSize();

    Node<ItemType> *current = newList.getHeadPtr();
    Node<ItemType> *prev = nullptr, *next = nullptr;


    while (current != nullptr){
        next = current->getNext();

        // set the next of the current
        current->setNext(prev);

        prev = current;
        current = next;
    }
     head_ = prev;
}

/*
    @param            :   Pointer to an object passed by reference
    @return           :   Return true if item moved to top else false
    This function will take the item from its current position and move it to the front
    of the list.
    For example, given the list 1 -> 3 -> 5 -> 6, moving the item at position 2 to the
    top of the list would result in 5 -> 1 -> 3 -> 6 (recall that positions start at 0
    and end at n-1).

    You are encouraged to create your own helper functions for this endeavour.
*/
template <typename ItemType>
bool LinkedList<ItemType>::moveItemToTop(ItemType& item){
    // get the index of the item
    int index = getIndexOf(item);

    // remove that item from the list
    bool isRemoved = remove(index);

    // insert back that item ti the 0 position

    return isRemoved && insert(item,0);
}




template class LinkedList<Post*>;

