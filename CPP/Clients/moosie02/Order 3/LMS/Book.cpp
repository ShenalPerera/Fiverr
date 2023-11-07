#include <iostream>
#include "Book.h"

Book::Book() {}


Book::Book(const string &isbn, const string &title, const string &author, const string &category, const string &id)
        : ISBN(isbn), title(title), author(author), category(category), ID(id),start_date(-1),expiration_date(-1) {}


const string &Book::getIsbn() const {
    return ISBN;
}

void Book::setIsbn(const string &isbn) {
    ISBN = isbn;
}

const string &Book::getTitle() const {
    return title;
}

void Book::setTitle(const string &title) {
    this->title = title;
}

const string &Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string &author) {
    this->author = author;
}

const string &Book::getCategory() const {
    return category;
}

void Book::setCategory(const string &category) {
    this->category = category;
}

const string &Book::getId() const {
    return ID;
}

void Book::setId(const string &id) {
    ID = id;
}

const string &Book::getReaderName() const {
    return reader_name;
}

void Book::setReaderName(const string &readerName) {
    reader_name = readerName;
}

int Book::getStartDate() const {
    return start_date;
}

void Book::setStartDate(int startDate) {
    start_date = startDate;
}

int Book::getExpirationDate() const {
    return expiration_date;
}

void Book::setExpirationDate(int expirationDate) {
    expiration_date = expirationDate;
}

ostream &operator<<(ostream &os, const Book * book) {
    if (!book){
        return os;
    }

    /*
     * The structure of the file
     * ISBN title author category ID reader_name starting_date expiration_date
     */

    // If there was no reader this part will go to stream
    os << book->ISBN << "\t" << book->title << "\t" << book->author << "\t" << book->category << "\t" << book->ID;

    if (!book->reader_name.empty()){
        os << "\t" << book->reader_name << "\t" << book->start_date << "\t" << book->expiration_date ;
    }
    else{
        os << "\tnull\t" << -1 << "\t" << -1 ;

    }



    os << endl;

    return os;
}


istream &operator>>(istream &is, Book * book){
    if (!book) return is;
    string ISBN;
    string _title;
    string author;
    string category;
    string ID;
    string reader_name("");
    int start_date = -1;
    int expiration_date = -1;

    is >> ISBN >> _title >> author >> category >> ID >> reader_name >> start_date >> expiration_date;




    book->ISBN = ISBN;
    book->title = _title;
    book->author = author;
    book->category = category;
    book->ID = ID;
    book->reader_name = reader_name;
    book->start_date = start_date;
    book->expiration_date = expiration_date;
    return is;
}

bool Book::operator<(const Book &rhs) const {
    // comparison done according to priority

    if (reader_name == "null" && rhs.reader_name != "null") return true;
    if (reader_name != "null" && rhs.reader_name == "null") return false;
    if (expiration_date < rhs.expiration_date) return true;
    if (expiration_date > rhs.expiration_date) return false;
    if (title < rhs.title) return true;
    if (title > rhs.title) return false;
    if (author < rhs.author) return true;
    if (author > rhs.author) return false;
    if (ISBN < rhs.ISBN) return true;
    if (ISBN > rhs.ISBN) return false;
    if (ID < rhs.ID) return true;
    if (ID > rhs.ID) return false;

}


