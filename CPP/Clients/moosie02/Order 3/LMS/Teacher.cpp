#include "Teacher.h"


Teacher::Teacher() {
    setUsername("Default teacher");
    setMaxCopies(10);
    setMaxPeriod(50);
    setUserType(0);
}

Teacher::Teacher(const string &username, const string &password) : Student(username, password) {
    // Unique value for teacher class
    setMaxCopies(10);
    setMaxPeriod(50);
    setUserType(0);

}

void Teacher::addNewBook(Book ** &pBook, int *count) {
    string ISBN,title, author,category;
    cout << "ISBN     : ";
    cin >> ISBN;
    cout << "Title    : ";
    cin >> title;
    cout << "Author   : ";
    cin >> author;
    cout << "Category   : ";
    cin >> category;

    string ID;
    const char alphanum[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";    // get for the ID generation
    ID.reserve(3);

    // generate 3 uppercase letters and count
    for (int i = 0; i < 3; ++i) {
        ID += alphanum[rand() % (sizeof(alphanum) - 1)];
    }


    Book * book = new Book(ISBN,title,author,category,ID);

    Book ** library = new Book * [*count +1];

    // copy the values
    for (int i = 0; i < *count; ++i) {
        library[i] = pBook[i];  // copying
    }

    // add new element
    library[*count] = book;

    // update the count
    *count = * count + 1;

    delete [] pBook;
    pBook = library;


}

void Teacher::deleteCopy(Book** &pBook,int * count){
    string ID;

    cout << "Enter the ID : ";
    cin >> ID;

    int index = -1;
    for (int i = 0; i < *count; ++i) {
        if (pBook[i]->getId() == ID){
            index = i;
            break;
        }
    }

    for (int i =index; i <*count -1 ; ++i) {
        pBook[i] = pBook[i+1];
    }
    *count = * count -1;


}


