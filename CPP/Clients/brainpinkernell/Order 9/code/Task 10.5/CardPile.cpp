#include "GameCard.h"
#include "CardPile.h"

#include <iostream>


CardPile::CardPile() {
    this->size = 0;
    cards = NULL;
}

CardPile::CardPile(string _name) {
    this->name = _name;
    this->size = 0;
    cards = NULL;
}

string CardPile::get_name() const {
    return name;
}

int CardPile::get_size() const {
    return size;
}

GameCard CardPile::get_top_card() const {
    return cards->get_data();
}

void CardPile::set_name(string _name) {
    name = _name;
}

void CardPile::display() const {
    cout << "Name : " << name << endl;
    cout << "Size : " << size<< endl;
    print_list(cards);
}

void CardPile::add_card(GameCard gameCard) {

    Node *new_node_ptr;

    new_node_ptr = new Node(gameCard);

    // to add this new node to the front of the list,
    //    I have 2 cases: is the list currently
    //    empty, or not?

    // I'm handling the empty case first

    if (cards == NULL)
    {
        cards = new_node_ptr;
    }

        // and if the list was not empty, handle that here

    else
    {
        // make the next data field of the new node
        //    point to the CURRENT first node

        new_node_ptr->set_next(cards);

        // NOW it is OK to change the head_ptr to
        //    to the new node

        cards = new_node_ptr;
    }
    size++;
}

NodeDataType CardPile::remove_card() {
    if (cards == NULL) {
        cerr << "Can not remove\n";
        exit(1);
    }

    // Move the head pointer to the next node
    Node* temp = cards;
    NodeDataType card = cards->get_data();
    cards = cards->get_next();

    delete temp;
    size--;

    return card;
}

CardPile::~CardPile() {

    delete_list(cards);
}

//CardPile::CardPile(const CardPile &old) {
//
//    size = old.size;
//    name = old.name;
//
//    if (old.cards == nullptr)
//    {
//        cards = nullptr;
//        return;
//    }
//
//    Node* temp = old.cards;
//    Node * head = old.cards;
//
//
//
//    while (temp != NULL)
//    {
//        insert_at_front(head,temp->get_data());
//        temp = temp->get_next();
//    }
//
//}

CardPile &CardPile::operator=(const CardPile &old) {
    delete_list(cards);

    Node * head = old.cards;
    Node * current = old.cards;

    while (current!= NULL){
        insert_at_end(head, current->get_data());
        current = current->get_next();
        cout << "Test";
    }
    size = old.size;
    name = old.name;

    return *this;
}
