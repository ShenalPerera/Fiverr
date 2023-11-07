/*----
  header file for my collection of linked list functions
      that use my Node class

  by: Sharon Tuttle
  last modified: 2022-10-27
----*/

#ifndef LINKED_LIST_FUNCTS_H
#define LINKED_LIST_FUNCTS_H

#include <string>
#include "GameCard.h"
#include "Node.h"


using namespace std;

void insert_at_front(Node*& head_ptr, NodeDataType new_data);
int insert_at_end(Node*& head_ptr, NodeDataType new_data);        // insert at the end
void print_list(Node* head_ptr);
int delete_list(Node*& head_ptr);
bool remove_instance(Node *& head_ptr, NodeDataType remove_data);

#endif