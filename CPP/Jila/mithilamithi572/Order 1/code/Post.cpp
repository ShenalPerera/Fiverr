#include <iostream>
#include "Post.hpp"

using namespace std;

Post::Post(string title, string body) {
    this->title = title;
    this->body = body;

    this->created_time = time(nullptr);
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
    return asctime(localtime(&created_time));
}

void Post::displayPost() const {
    cout << getTitle() << " posted at " << getTimeStamp();
    cout << getBody() << endl;
}