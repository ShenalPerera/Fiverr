/*----
  implementation file for my collection of linked list functions
      that use my Node class

  by: Sharon Tuttle
  last modified: 2022-10-27
----*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include "Node.h"
#include "linked-list-functs.h"
using namespace std;

/*----
  signature: insert_at_front: Node*& NodeDataType -> void

  purpose: expects a head pointer to a linked list that is
      PASSED BY REFERENCE, and a piece of data we want to "add"
      to the front of this list, has the side-effects of:
      *   creating a new Node with this data
      *   adding this new node to the FRONT of this list,
          CHANGING the address in the head pointer ARGUMENT
      ...and returns nothing

  tests:
      for:
      Node *start_here = NULL;

      insert_at_front(start_here, 47);

      afterwards:
      *   start_here should point to a Node containing 47
          and that Node should have a next data field of NULL

      if I THEN:
      insert_at_front(start_here, 36);

      afterwards:
      *   start_here should point to a Node containing 36
          and that Node should point to the Node containing 36
          and the Node containing 36 should have a next data field
          of NULL

----*/

void insert_at_front(Node*& head_ptr, NodeDataType new_data)
{
    // need a new Node to hold the new element

    Node *new_node_ptr;

    new_node_ptr = new Node(new_data);

    // to add this new node to the front of the list,
    //    I have 2 cases: is the list currently
    //    empty, or not?

    // I'm handling the empty case first

    if (head_ptr == NULL)
    {
        head_ptr = new_node_ptr;
    }

    // and if the list was not empty, handle that here

    else
    {
        // make the next data field of the new node
        //    point to the CURRENT first node

        new_node_ptr->set_next(head_ptr);

        // NOW it is OK to change the head_ptr to
        //    to the new node

        head_ptr = new_node_ptr;
    }
}

/*---
    signature: print_list: Node* -> void
    purpose: expects a pointer to the beginning of a linked
        list, has the side effect of printing the data in
        each node to the screen on its own line, and returns
        nothing
    tests:
        for:
        Node *my_first;
        my_first = NULL;

        print_list(my_first);
        ...prints to the screen:

List contents:
==============
==============

        if I then:
        insert_at_front(my_first, 12);
        insert_at_front(my_first, 700);
        insert_at_front(my_first, 15);

        print_list(my_first);
        ...prints to the screen:

List contents:
==============
15
700
12
==============

---*/

void print_list(Node* head_ptr)
{
    cout << "List contents:" << endl;
    cout << "==============" << endl;

    // set up a pointer to help me "walk through" the list

    Node *curr_node_ptr;

    // start it where the current head_ptr is

    curr_node_ptr = head_ptr;

    while (curr_node_ptr != NULL)
    {
        cout << curr_node_ptr->get_data() << endl;

        curr_node_ptr = curr_node_ptr->get_next();
    }

    cout << "==============" << endl;
}

/*---
  signature: delete_list: Node*& -> int
  purpose: expects a pointer to a dynamic linked list
      PASSED BY REFERENCE, has the side-effect of
      freeing those list nodes and setting the argument pointer
      to NULL, and returns the number of list nodes freed.

  tests: if I have:
     Node *start_test = NULL;

     delete_list(start_test) == 0

     if I have:
     insert_at_front(start_test, 400);
     insert_at_front(start_test, 300);
     insert_at_front(start_test, 200);
     insert_at_front(start_test, 100);

     delete_list(start_test) == 4

---*/

int delete_list(Node*& head_ptr)
{
    Node *curr_ptr;
    int num_freed = 0;

    curr_ptr = head_ptr;

    while (curr_ptr != NULL)
    {
        head_ptr = head_ptr->get_next();
        delete curr_ptr;
        curr_ptr = head_ptr;
        num_freed++;
    }

    return num_freed;
}


/*----
  signature: insert_at_end: Node*& NodeDataType -> int

  purpose: expects a head pointer to a linked list that is
      PASSED BY REFERENCE, and a piece of data we want to "add"
      to the end of this list, has the side-effects of:
      *   creating a new Node with this data
      *   adding this new node to the END of this list

----*/

int insert_at_end(Node*& head_ptr, NodeDataType new_data){

    Node * new_node_ptr = new Node(new_data, NULL);

    // handle the empty linked list
    if (head_ptr == NULL){
        head_ptr = new_node_ptr;
        return 1;
    }

    Node * current_node = head_ptr;
    int size = 1;

    while (current_node->get_next() != NULL){
        current_node = current_node->get_next();
        size++;
    }

    current_node->set_next(new_node_ptr);
    return ++size;

}


int get_size(Node * head_ptr){
    int size = 0;

    Node * current = head_ptr;

    while (current != NULL){
        current = current->get_next();
        size++;
    }
    return size;


}


NodeDataType sum_list(Node * head_ptr){
    NodeDataType sum = 0;

    Node * current = head_ptr;

    while (current != NULL){
        sum = sum + current->get_data();
        current = current->get_next();

    }
    return sum;
}