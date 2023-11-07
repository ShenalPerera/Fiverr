//
//  Book.cpp
//  H1 Q4
//
//  Created by Mustafa Anjum on 9/26/22.
//

#include "Book.hpp"
#include <iostream>

Book::Book(int no, const std::string &title, const std::string &author, const std::string &genre, int noOfPages)
{
    this->no = no;
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->noOfPages = noOfPages;
}

Book &Book::operator=(const Book& b) {
    if (this != &b) {
        this->no = b.no;
        this->title = b.title;
        this->author = b.author;
        this->genre = b.genre;
        this->noOfPages = b.noOfPages;
    }
    return *this;
}

void Book::display() {
    std::cout << "\nBook no: " << no
        << "\nTitle: " << author
        << "\nAuthor: " << author
        << "\nGenre: " << genre
        << "\nNo of pages: " << noOfPages << std::endl;
}
