#include <iostream>
#include "Account.hpp"

using namespace std;

Account::Account() {
    this->username = "";
    this->password = "";
}

Account::Account(string username, string password) {
    this->username = username;
    this->password = password;
    this->posts.clear();
}

void Account::setUsername(string username) {
    this->username = username;
}

string Account::getUsername() const {
    return username;
}

void Account::setPassword(string password) {
    this->password = password;
}

string Account::getPassword() const {
    return password;
}

bool Account::addPost(string title, string body) {
    int size = posts.size();

    Post post(title,body);
    this->posts.push_back(post);



    if (!title.empty() && !body.empty() && size + 1 == posts.size()){

        return true;
    }
    return false;
}

void Account::viewPosts() const {

    for (const auto & post : posts) {
        post.displayPost();
    }
}