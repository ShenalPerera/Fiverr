#include <iostream>

#include "linked-list-functs.h"

using namespace std;

int main(){
    Node * head_ptr = NULL;

    cout << "Empty list                  |  Expected 0  |   Result " << remove_instance(head_ptr,1) <<"   |"<< endl;

    // insert 1,2,3,4,5,6
    for (int i = 1; i < 7; ++i) {
        insert_at_front(head_ptr,i);
    }

    insert_at_front(head_ptr,6);
    insert_at_front(head_ptr,7);

    cout << "Value not in the list       |  Expected 0  |   Result " << remove_instance(head_ptr,10) << "   |" << endl;
    print_list(head_ptr);
    cout << "Results\n=======\n";
    cout << "7\n6\n6\n5\n4\n3\n2\n1\n=======\n\n";

    cout << "Value in the middle         |  Expected 1  |   Result " << remove_instance(head_ptr,4) <<  "   |" << endl;
    print_list(head_ptr);
    cout << "Results\n=======\n";
    cout << "7\n6\n6\n5\n3\n2\n1\n=======\n\n";

    cout << "Value has twice in the list |  Expected 1  |   Result " << remove_instance(head_ptr,6) <<  "   |" << endl;
    print_list(head_ptr);
    cout << "Results\n=======\n";
    cout << "7\n6\n5\n3\n2\n1\n=======\n\n";

    cout << "Value at Last               |  Expected 1  |   Result " << remove_instance(head_ptr,7) <<  "   |" << endl;
    print_list(head_ptr);
    cout << "Results\n=======\n";
    cout << "6\n5\n3\n2\n1\n=======\n\n";

    cout << "Value at First              |  Expected 1  |   Result " << remove_instance(head_ptr,1) <<  "   |" << endl;
    print_list(head_ptr);
    cout << "Results\n=======\n";
    cout << "6\n5\n3\n2\n=======\n\n";


    remove_instance(head_ptr,6);
    remove_instance(head_ptr,5);
    remove_instance(head_ptr,2);

    cout << "Only one value              |  Expected 1  |   Result " << remove_instance(head_ptr,3) <<  "   |" << endl;
    print_list(head_ptr);
    cout << "Results\n=======\n";
    cout << "=======\n\n";
    return EXIT_SUCCESS;
}