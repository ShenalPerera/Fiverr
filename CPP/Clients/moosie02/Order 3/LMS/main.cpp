#include <iostream>

#include "system.h"

using namespace std;


int main() {

    int date = 0;

    // Initial clock ticks
    clock_t initial_tick = clock();

    // people array to hold the both student and teaches
    Student ** people;
    Book ** books ;

    // sizes of the people and books
    int people_count;
    int books_count;


    // To start the system populate the arrays and the count variables
    populate_data(people,&people_count,books,&books_count);
    // sort the books by ID
     sort_books(books,books_count);

    string username;
    string password;

    // prompt the login to the system
    cout << "-------------------Login page-------------------" << endl;
    cout <<"\nEnter your username : " ;
    cin >> username;
    cout <<"Enter your password : " ;
    cin >> password;



    // authenticate the user and change the branch
    if (authenticate_user(username,password,people,people_count)){  // inside this branch user is authenticated

        Student * user = search_user(username,people,people_count); // get the user object (never null)
        int user_choice;
        do {

            // handle each case from the app
             user_choice = menu(user);

            switch (user_choice) {
                case 1:
                    search_menu(user,books,books_count);
                    break;
                case 2:
                    // Custom delay
                    date = date_counter(date,initial_tick);
                    borrow_book(user,books,books_count,date);
                    initial_tick = clock();
                    break;
                case 3:
                    return_book(user);
                    break;
                case 4:
                    date = date_counter(date,initial_tick);
                    renew_book(user,date);
                    initial_tick = clock();

                    break;
                default:

                    break;


            }

            if (user->getUserType() == 0){
                switch (user_choice) {
                    case 5:
                        user->addNewBook(books,&books_count);
                        sort_books(books,books_count);
                        break;
                    case 6:
                        user->deleteCopy(books,&books_count);
                        sort_books(books,books_count);
                        break;
                }
            }

        } while (user_choice !=0);
    }

    save_data(people,people_count,books,books_count);


    for (int i = 0; i < books_count; ++i) {
        cout << books[i];
    }

    return 0;
}


