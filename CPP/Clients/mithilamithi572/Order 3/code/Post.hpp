#ifndef CODE_POST_HPP
#define CODE_POST_HPP
#include <string>
#include <time.h>
using namespace std;

class Post {
private:
    string title;
    string body;
    time_t created_time;
    string username;

public:
    Post(string , string);

    // ACCESSORS and Mutators
    void setTitle(string);
    string getTitle() const;

    void setUsername(string username);
    string getUsername() const;


    void setBody(string);
    string getBody() const;

    string getTimeStamp() const;

    // DISPLAYING
    void displayPost() const;

};


#endif //CODE_POST_HPP
