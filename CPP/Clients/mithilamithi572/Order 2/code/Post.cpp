#include <iostream>
#include "Post.hpp"

Post::Post() {};    // implement default constructor

Post::Post(string title, string body) {        // parameterized constructor
    this->title = title;
    this->body = body;
    this->created_time = time(nullptr);
}

// Accessors and mutators

string Post::getUsername() const {
    return username;                // return the username in accessor
}

void Post::setUsername(string _username) {
    this->username = _username;              // set username into given username in the argument of mutator
}


void Post::setTitle(string title) {
    this->title = title;
}

string Post::getTitle() const {
    return title;
}

void Post::setBody(string body) {
    this->body= body;
}

string Post::getBody() const {
    return body;
}

string Post::getTimeStamp() const {
    string str = asctime(localtime(&created_time));
    str.pop_back();
    return str;
}

void Post::displayPost() const {
    cout << getTitle() << " posted at " << getTimeStamp();
    cout << getBody() << endl;
}