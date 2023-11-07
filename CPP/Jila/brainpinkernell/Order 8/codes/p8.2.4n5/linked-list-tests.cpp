#include <iostream>

#include "linked-list-functs.h"

using namespace std;

int main(){
    Node * head_ptr = NULL;

    // Test on the empty linked list
    cout << "Empty List         | Expected 0 | Result : " << get_size(head_ptr) <<" |" <<endl;


    // insert 1,2,3,4,5
    for (int i = 1; i < 6; ++i) {
        insert_at_front(head_ptr,i);
    }

    cout << "Non Empty List     | Expected 5 | Result : " << get_size(head_ptr) <<" |" <<endl;


    delete_list(head_ptr);
    cout << "After delete List  | Expected 0 | Result : " << get_size(head_ptr) <<" |" <<endl;


    cout << "\n\nTesting sum_list Function\n=========================\n";

    Node * new_head_ptr = NULL;

    // Test on the empty linked list
    cout << "Empty List         | Expected 0 | Result : " << sum_list(head_ptr) <<" |" <<endl;


    // insert 1,2,3,4,5
    for (int i = 1; i < 6; ++i) {
        insert_at_front(head_ptr,i);
    }

    cout << "Non Empty List     | Expected 15| Result : " << sum_list(head_ptr) <<"|" <<endl;

    delete_list(head_ptr);
    cout << "After delete List  | Expected 0 | Result : " << sum_list(head_ptr) <<" |" <<endl;
    return EXIT_SUCCESS;
}