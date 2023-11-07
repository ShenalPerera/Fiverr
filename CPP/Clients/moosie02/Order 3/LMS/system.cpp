#include "system.h"


void save_data(Student **people,int people_count, Book **books, int books_count) {
    // create the output file stream to save the data
    ofstream people_fout("students.txt");

    // save the count of the people in first line
    people_fout << people_count << endl;

    for (int i = 0; i < people_count; ++i) {
        people_fout << people[i];
    }

    people_fout.close();        // close the file

    // create for a book
    ofstream books_fout("books.txt");

    books_fout << books_count<< endl;

    for (int i = 0; i < books_count; ++i) {
        books_fout << books[i];
    }

    books_fout.close();
}

// This function will populate the arrays from the files
void populate_data(Student ** &people,int * people_count, Book ** &books, int * books_count){
    // create the streams
    ifstream fin_people("students.txt");
    ifstream fin_books("books.txt");

    // handle file error case
    if (fin_people.fail() || fin_books.fail()){
        cerr << "Error occurred when loading data!" << endl;
        exit(0);
    }

    // read the count data of the people and books from the system file then update the pointer varaible of main
    fin_people >> *people_count;
    fin_books >> *books_count;

    // create dynamic arrays for each entity
    people = new Student * [*people_count];
    books = new Book * [*books_count];

    // populate the array using overload operators

    // identify the entity type (teacher or student)
    int type;
    for (int i = 0; i < *people_count; ++i) {
        fin_people >> type;

        // if type is 1 entity is teacher and 1 student
        if (type == 1){
            Student * student = new Student();
            fin_people >> student;
            people[i] = student;

        }
        else if (type == 0){
            Teacher * teacher = new Teacher();
            fin_people >> teacher;
            people[i] = teacher;
        }

    }

    fin_people.close();         // close the file

    // populate the array of the books
    for (int i = 0; i < *books_count; ++i) {
        Book * book = new Book();
        fin_books >> book;

        // save the object pointer to the array
        books[i] = book;

        // check if there is a user for that book
        if (book->getReaderName() != "null"){
            // if yes get the user
            Student * student = search_user(book->getReaderName(),people,*people_count);

            // add that copy to the copies list of the user
            if (student != nullptr){    // ignore the not found users
                student->addCopy(book);
            }
        }
    }
}

/**
 * This function get the username and the password and the pointer array of pointers to the Student and teachers object.
 * Then find the relevant pointer object from the list and check the password. If password matches return true false otherwise
 * @param username
 * @param password
 * @return true if the username and password is match false otherwise
 */
bool authenticate_user(string & username, string & password, Student ** people, int people_count){
    // loop through people list
    for (int i = 0; i < people_count; ++i) {
        if (people[i]->getUsername() == username){
            if (people[i]->getPassword() == password){
                return true;
            }
            cout << "Password is wrong!" << endl;
            return false;
        }

    }

    // if no user found return false
    cout << "No user found" << endl;
    return false;
}

/**
 * This function will get the current value of the day and the last time/initial time of the clock ticks
 * @param current_day
 * @param prev_number_of_ticks
 * @return return the updated day value as an integer
 */
int date_counter(int  current_day, clock_t  prev_number_of_ticks){
    clock_t current_clock_tick = clock();       // get the current clock ticks

    clock_t diff_ticks = current_clock_tick - prev_number_of_ticks; // get the diffference of the clock ticks


    // increase the daya count by how mny days have gone
    int days = (int )((diff_ticks/CLOCKS_PER_SEC)/5);       // get how many slot of 5 have passed
    return days + current_day; // add that many days to the current date
}

Student * search_user(const string &username, Student** people,int people_count){
    for (int i = 0; i < people_count; ++i) {
        if (people[i]->getUsername() == username){
            return people[i];
        }
    }
    return nullptr;
}


int menu(Student * student){
    // show the options to the user with the greeting message
    string type = (student->getUserType() == 1) ? "Student" : "Teacher";    // get the type and aassign string

    cout <<"-------------------------------------------------------" << endl;
    cout <<"                   Welcome to LMS" << endl;
    cout <<"-------------------------------------------------------" << endl << endl;

    cout << "Welcome back, " << type << endl<< endl;

    cout << "Please choose : " << endl;
    cout <<"\t\t\t1 -- Search Book"<< endl;
    cout <<"\t\t\t2 -- Borrow Book"<< endl;
    cout <<"\t\t\t3 -- Return Book"<< endl;
    cout <<"\t\t\t4 -- Renew Book"<< endl;

    // teachers additional functionality
    if (student->getUserType() == 0){
        cout <<"\t\t\t5 -- Request a new book"<< endl;
        cout <<"\t\t\t6 -- Delete a new book"<< endl;
    }

    cout <<"\t\t\t0 -- Log Out"<< endl;

    int user_input;

    // get the user input
    cin >> user_input;
    return user_input;

}


void sort_books(Book ** &books,int size){
    int rounds = 0;

    for (int i = 0; i < size; i++) {
        rounds++;
        int flag = false; // break condition
        for (int j = 0; j < (size - i - 1); j++) {
            if (books[j]->getId() > books[j + 1]->getId()) {
                flag = true;
                Book * temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
        if (flag == false) {
            break;
        }
    }
}


void search_menu(Student * student,Book ** books, int book_count){
    cout << "Please choose key :"<< endl;
    cout <<"\t\t\t1 -- ISBN"<< endl;
    cout <<"\t\t\t2 -- Title"<< endl;
    cout <<"\t\t\t3 -- Category"<< endl;
    cout <<"\t\t\t4 -- ID"<< endl;

    int user_input;
    cin >> user_input;

    student->searchBook(user_input,books,book_count);

}


void borrow_book(Student * student,Book ** books, int book_count,int current_date){
    // get the user input for ID
    string ID;
    cout << "Enter the ID of the book : ";

    cin >> ID;


    student->borrowBook(ID,books,book_count,current_date);

}


void return_book(Student * student){
    string ID;
    cout << "Enter the ID of the book : ";

    cin >> ID;

    student->returnBook(ID);
}

void renew_book(Student * student,int current_date){
    student->renewBook(current_date);
}