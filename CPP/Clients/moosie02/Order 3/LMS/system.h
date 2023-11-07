#ifndef LMS_SYSTEM_H
#define LMS_SYSTEM_H

#include "Teacher.h"
#include <fstream>
#include <iostream>
#include <ctime>

void save_data(Student * people[],int people_count, Book * books[], int books_count);

void  populate_data(Student ** &people,int * people_count, Book ** &books, int * books_count);

bool authenticate_user(string & username, string & password,  Student ** people, int people_count);

int date_counter(int  current_day, clock_t  prev_number_of_ticks);

Student * search_user(const string &username, Student** people,int people_count);

int menu(Student * student);

void sort_books(Book ** &books,int size);

void search_menu(Student * student,Book ** books, int book_count);

void borrow_book(Student * student,Book ** books, int book_count,int current_date);

void return_book(Student * student);

void renew_book(Student * student,int current_date);

#endif //LMS_SYSTEM_H
