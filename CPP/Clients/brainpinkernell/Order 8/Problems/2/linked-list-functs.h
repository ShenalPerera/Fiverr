/*----
  header file for my collection of linked list functions
      that use my Node class

  by: Sharon Tuttle
  last modified: 2022-10-27
----*/

#ifndef LINKED_LIST_FUNCTS_H
#define LINKED_LIST_FUNCTS_H

#include <string>
using namespace std;

void insert_at_front(Node*& head_ptr, NodeDataType new_data);
void print_list(Node* head_ptr);
int delete_list(Node*& head_ptr);

#endif