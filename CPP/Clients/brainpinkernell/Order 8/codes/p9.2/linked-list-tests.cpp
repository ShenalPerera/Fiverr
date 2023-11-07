#include <iostream>

#include "linked-list-functs.h"

using namespace std;

int main(){
    Node * head_ptr = NULL;

    // add value to empty linked list
    if (insert_at_end(head_ptr,1) == 1){
        cout << "Current size is 1" << endl;
    }
    print_list(head_ptr);
    cout << "Test results" << endl;
    cout << "1\n\n";


    // add value to list contains exactly one value
    if (insert_at_end(head_ptr,2) == 2){
        cout << "Current size is 2" << endl;
    }
    print_list(head_ptr);
    cout << "Test results" << endl;
    cout << "1\n2\n\n";


    // insert 3,4,5,6,7,8,9
    for (int i = 3; i < 10; ++i) {
        insert_at_end(head_ptr,i);
    }

    // add value to list contains exactly one value
    if (insert_at_end(head_ptr,10) == 10){
        cout << "Current size is 10" << endl;
    }
    print_list(head_ptr);
    cout << "Test results" << endl;
    cout << "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n\n";

    return EXIT_SUCCESS;
}