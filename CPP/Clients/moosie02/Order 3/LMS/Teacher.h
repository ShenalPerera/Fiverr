#ifndef LMS_TEACHER_H
#define LMS_TEACHER_H

#include "Student.h"


using namespace std;

class Teacher: public Student{
public:
    Teacher();

    Teacher(const string &username, const string &password);

    void addNewBook(Book** &pBook,int * count);

    void deleteCopy(Book** &pBook,int * count);
};


#endif //LMS_TEACHER_H
