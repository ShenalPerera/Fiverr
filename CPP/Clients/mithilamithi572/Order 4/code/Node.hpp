/****************************************************************************************************************************
Title         :   Node.hpp
Author        :
Description   :   header/interface for Node class
****************************************************************************************************************************/
#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

template<class ItemType>
class Node {
private:
    ItemType item;

    Node<ItemType> * nextPtr_;       // next pointer

public:

    /* constructor */
    Node();


    Node(const ItemType& item, Node<ItemType> *next_node);

    /*Destructor*/
    ~Node();

    /*Get the item*/
    ItemType getItem() const;

    /* setItem */
    void setItem(const ItemType& item);

    /* set next pointer */
    void setNext(Node<ItemType> * nextPtr);

    /* get the next pointer */
    Node<ItemType>* getNext() const;
};

//#include "Node.cpp"
#endif //CODE_NODE_HPP
