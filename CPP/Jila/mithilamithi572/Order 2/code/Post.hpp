#ifndef CODE_POST_HPP
#define CODE_POST_HPP
#include <string>

using namespace std;

class Post {
private:
    string username;    // private member username
    string title;
    string body;
    time_t created_time;
public:

    // default constructor
    Post();

    // Overloaded constructor
    Post(string , string);

    // Accessor function
    string getUsername() const; // method to get the username
    string getTitle() const;    // method to get the title
    string getBody() const;     // Method to get the body
    string getTimeStamp() const;// Method to get the timestamp


    // mutator function
    void setUsername(string _username);
    void setTitle(string);
    void setBody(string);


    // DISPLAYING
    void displayPost() const;
};


#endif //CODE_POST_HPP
