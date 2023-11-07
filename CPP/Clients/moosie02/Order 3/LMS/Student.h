#ifndef LMS_STUDENT_H
#define LMS_STUDENT_H

#include <string>
#include <vector>
#include <ostream>
#include <istream>
#include <iostream>

#include "Book.h"


using namespace std;

// Class that represents the student entity of the system



class Student{

private:
    string username;
    string password;
    int max_copies;
    int max_period;
    vector<Book*> copy_list;
    int userType;          // identify the type of the class 1 = student 0 = teacher

    // private member to search from ID binary search;


public:
    Student();

    Student(const string &username, const string &password);

    // Getters and setters

    const string &getUsername() const;

    void setUsername(const string &username);

    const string &getPassword() const;

    void setPassword(const string &password);

    int getMaxCopies() const;

    void setMaxCopies(int maxCopies);

    int getMaxPeriod() const;

    void setMaxPeriod(int maxPeriod);

    const vector<Book*> &getCopyList() const;

    void setCopyList(const vector<Book*> &copyList);

    int getUserType() const;

    void setUserType(int _userType);

    void addCopy(Book * book);

    void returnBook(string ID);

    void renewBook(int current_date);

    // defined as friend because to access the private variables directly
    friend ostream &operator<<(ostream &os, const Student * student);

    friend istream &operator>>(istream &is, Student * student);

    void searchBook(int key, Book ** books, int book_count);

    void borrowBook(string &ID,Book ** books, int book_count, int current_date);

    // does not have a body
    virtual void addNewBook(Book** &pBook,int * count);

    virtual void deleteCopy(Book** &pBook,int  * count);

    Book * binary_search(string &ID,Book** books,int book_count);
};


#endif //LMS_STUDENT_H
