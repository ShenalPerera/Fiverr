//
//  main.cpp
//  H1 Q4
//
//  Created by Mustafa Anjum on 9/26/22.
//

#include "Book.hpp"

#include <iostream>

int main()
{
    Book book1(1, "ABC", "a", "a", 10);
    Book book2(2, "DEF", "d", "d", 9);
    Book book3(3, "GHJ", "g", "g", 1);
    Book book4(book1);
    Book book5(book3);

    book1.display();
    book2.display();
    book3.display();
    book4.display();
    book5.display();
    
    return 0;
}
