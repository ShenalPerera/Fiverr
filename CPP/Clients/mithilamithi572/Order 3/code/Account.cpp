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
    this->network = nullptr;
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

    post.setUsername(this->username);

    this->posts.push_back(post);

    if (network != nullptr){
        network->addToFeed(post);
    }

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


Network<Account>  * Account::getNetwork() const {
    return network;
}

void Account::setNetwork(Network<Account> *network_entry) {
    this->network = network_entry;
}

bool Account::followAccount(string username_to_follow) {

    for (auto & following_username : following_usernames) {
        if (following_username == username_to_follow){
            return false;
        }
    }

    if (network != nullptr){
        following_usernames.push_back(username_to_follow);
        return true;
    }
    return false;

}

vector<string> Account::getFollowers() const {
    return following_usernames;
}