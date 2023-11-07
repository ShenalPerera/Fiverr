#include <iostream>
#include "get_size.h"

int main() {
    int file1_value = get_size("test_1.txt");
    int file2_value = get_size("test_2.txt");

    cout << "test_1.txt file has 4 words and get_size(\"test_1.txt\") = " << file1_value << endl;
    cout << "test_2.txt file has 6 words and get_size(\"test_1.txt\") = " << file2_value << endl;

    return EXIT_SUCCESS;
}

