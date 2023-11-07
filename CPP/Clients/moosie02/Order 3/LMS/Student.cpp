#include "Student.h"

using namespace std;


Student::Student():max_period(30),max_copies(5),userType(1) {
    this->username = "Default student";
    this->password = "abc@123";
}

Student::Student(const string &username, const string &password) : username(username),password(password),userType(1){
    // These values are fixed for the student
    setMaxPeriod(30);
    setMaxCopies(5);
}

const string &Student::getUsername() const {
    return username;
}

void Student::setUsername(const string &username) {
    this->username = username;
}

const string &Student::getPassword() const {
    return password;
}

void Student::setPassword(const string &password) {
    this->password = password;
}

int Student::getMaxCopies() const {
    return max_copies;
}

void Student::setMaxCopies(int maxCopies) {
    max_copies = maxCopies;
}

int Student::getMaxPeriod() const {
    return max_period;
}

void Student::setMaxPeriod(int maxPeriod) {
    max_period = maxPeriod;
}

const vector<Book*> &Student::getCopyList() const {
    return copy_list;
}

void Student::setCopyList(const vector<Book*> &copyList) {
    copy_list = copyList;
}

// function to add a copy to the borrowed book list
void Student::addCopy( Book * book) {
    copy_list.push_back(book);
}

ostream &operator<<(ostream &os, const Student * student) {

    if(!student) return os;
    /* text file has the format =>
     * 0/1<tab>username<tab>password<tab>borrowed copies id seperated by tab
     *
    */
    os << student->userType << "\t" << student->username << "\t" << student->password;

    // output the buffer with a new line
    os << endl;
    return os;
}

istream &operator>>(istream &is, Student * student) {
    string username;
    string password;

    // get username and the password
    is >> username >> password;

    // update the user value
    student->username = username;
    student->password = password;
    return is;
}

int Student::getUserType() const {
    return userType;
}

void Student::setUserType(int _userType) {
    Student::userType = _userType;
}

void Student::searchBook(int key, Book **books,int book_count) {

    string value;

    // Temp vector
    vector<Book *> temp_books;


    // handle the case
    switch (key) {
        case 1:
            cout << "Enter the ISBN : ";
            cin >> value;

            for (int i = 0; i < book_count; ++i) {
                if (books[i]->getIsbn() == value){
                    temp_books.push_back(books[i]);
                }
            }
            break;
        case 2:
            cout << "Enter the Title : ";
            cin >> value;

            for (int i = 0; i < book_count; ++i) {
                if (books[i]->getTitle() == value){
                    temp_books.push_back(books[i]);
                }
            }
            break;
        case 3:
            cout << "Enter the Category : ";
            cin >> value;

            for (int i = 0; i < book_count; ++i) {
                if (books[i]->getCategory() == value){
                    temp_books.push_back(books[i]);
                }
            }
            break;

        case 4:
            cout << "Enter the ID : ";
            cin >> value;

            temp_books.push_back(binary_search(value,books,book_count));
            break;

        default:
            cout << "Invalid input" << endl << endl;
            break;


    }

    // sort the vector
    for (int i = 0; i < temp_books.size(); i++) {
        for (int j = i; j < (temp_books.size()); j++) {
            if (*temp_books[j] < *temp_books[i]) {

                std::swap(temp_books[i], temp_books[j]);
            }
        }
    }

    for (auto temp : temp_books) {
        cout <<   "ISBN     : " << temp->getIsbn() <<
                "\nTitle    : " << temp->getTitle() <<
                "\nAuthor   : " <<temp->getAuthor() <<
                "\nCategory : " << temp->getCategory() <<
                "\nID       : " << temp->getId() << endl << endl;
    }
}

Book *Student::binary_search(std::string &ID, Book **books, int book_count) {
    // value for need for binary search
    int lo = 0, hi = book_count - 1;
    int mid;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1) {
        mid = (hi + lo) / 2;
        if (books[mid]->getId() < ID) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (books[lo]->getId() == ID) {
        return books[lo];
    }
    else if (books[hi]->getId() == ID) {
        return books[hi];
    }
    else {
        return nullptr;
    }

}

void Student::borrowBook(std::string &ID, Book **books, int book_count, int current_date) {
    // check for overdue copies
    bool isValid = true;
    for (auto & i : copy_list) {
        if (i->getExpirationDate() < current_date){   // if the current date has passed the expiration date
            isValid = false;
            break;
        }
    }

    // return from the function if not valid (has overdue books)
    if (!isValid){
        cout << "You have overdue copies. Can not perform the operation" << endl << endl;
        return;
    }

    if (copy_list.size() >= max_copies){
        cout << "Can not borrow more than " << max_copies << "copies" << endl<< endl;
        return;
    }
    Book * book = binary_search(ID,books,book_count);
    if (book == nullptr){
        cout << "Not an valid ID!" << endl << endl;
        return;
    }

    // add the user field, start date and the expiration date to the book
    book->setReaderName(this->username);
    book->setStartDate(current_date);
    book->setExpirationDate(current_date + max_period);

    // add the copy to the users copies list
    addCopy(book);

}


void Student::returnBook(std::string ID) {
    int index = -1;
    // find the index of given ID;
    for (int i = 0; i < copy_list.size(); ++i) {
        if (copy_list.at(i)->getId() == ID){
            index = i;
            break;
        }
    }

    if (index == -1){
        cout << "Not valid ID" << endl;
        return;
    }

    Book * book = copy_list.at(index);
    book->setReaderName("null");
    book->setStartDate(-1);
    book->setExpirationDate(-1);

    copy_list.erase(copy_list.begin() + index); // erase the element


}


void Student::renewBook(int current_date) {


    // sorted the array
    for (int i = 0; i < copy_list.size(); i++) {
        for (int j = i; j < (copy_list.size()); j++) {
            if (*copy_list[j] < *copy_list[i]) {

                std::swap(copy_list[i], copy_list[j]);
            }
        }
    }


    for (auto temp : copy_list) {
        cout <<   "ISBN     : " << temp->getIsbn() <<
             "\nTitle    : " << temp->getTitle() <<
             "\nAuthor   : " <<temp->getAuthor() <<
             "\nCategory : " << temp->getCategory() <<
             "\nID       : " << temp->getId() << endl << endl;
    }

    string ID;

    cout << "Enter ID : ";
    cin >> ID;

    bool isFound = false;
    // find the index of given ID;
    for (auto & i : copy_list) {
        if (i->getId() == ID){
            isFound = true;
            i->setStartDate(current_date);
            i->setExpirationDate(current_date + max_period);
            break;
        }
    }

    if (!isFound)
        cout << "Not valid ID" << endl;



}

void Student::addNewBook(Book ** &pBook, int *count) {

}

void Student::deleteCopy(Book ** &pBook, int *count) {

}
