#include "Node.hpp"
#include "Post.hpp"

template<class ItemType>
Node<ItemType>::Node() :nextPtr_{nullptr}{}


/*
    Parametarized Constructor
    @param item - the item to be constructed
    @param next_node - the next node to point to
 */
template <class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType> *next_node) : item{item}, nextPtr_{next_node} {}


template<class ItemType>
Node<ItemType>::~Node() {
    delete nextPtr_;
}


/*
    @param  item: the item to set the node item
    @post     : set the item of the node

**/
template<class ItemType>
void Node<ItemType>::setItem(const ItemType &item) {
    this->item = item;
}

/*

    @pre      : returns the item of the node
**/
template<class ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> *nextPtr) {
    this->nextPtr_ = nextPtr;
}

template<class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const {
    return nextPtr_;
}


template class Node<Post*>;