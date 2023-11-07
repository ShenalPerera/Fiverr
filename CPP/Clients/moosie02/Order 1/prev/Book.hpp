//
//  Book.hpp
//  H1 Q4
//
//  Created by Mustafa Anjum on 9/26/22.
//

#ifndef Book_hpp
#define Book_hpp

#include <string>
#include <stdio.h>

class Book
{
private:
    int no;
    std::string title;
    std::string author;
    std::string genre;
    int noOfPages;
public:
    Book(int no, const std::string &title, const std::string &author, const std::string &genre, int noOfPages);

    Book &operator=(const Book& b);

    void display();
};

#endif
