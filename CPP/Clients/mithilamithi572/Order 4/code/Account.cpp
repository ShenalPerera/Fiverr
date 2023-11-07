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

bool Account::addPost(Post * const  post) {
    int size = posts.getSize();

    this->posts.insert(post,0);

    if (network != nullptr){
        network->addToFeed(*post);
    }

    if (!post->getTitle().empty() && !post->getTitle().empty() && size + 1 == posts.getSize()){

        return true;
    }
    return false;
}

void Account::viewPosts() const {

//    for (const auto & post : posts) {
//        post.displayPost();
//    }

    for (int i = 0; i < posts.getSize(); ++i) {
        posts.getAtPos(i)->getItem()->displayPost();
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


/**
     * @param          : A string (user name of the account)
     * @return         : Pointer of the Account if valid username
     *
     * This function will look through the body and title of all Posts in the Network's feed.
        If a Post contains the provided word or phrase, and remove from the Accounts feed.
     */

int Account::removeFromPosts(string& word) {
    int count = 0;
    // go through the posts list (Linked list)
    for (int i = 0; i <posts.getSize() ; ++i) {
        // Hold the temp post
        Post * post = posts.getAtPos(i)->getItem();

        // check the given word is found
        if (post->getBody().find(word) != string::npos || post->getTitle().find(word) != string::npos){

            this->posts.remove(i);   // remove the post
            count++;
        }

    }

    return count;
}

bool Account::operator==(const Account &rhs) const {
    return username == rhs.username &&
           password == rhs.password;
}

bool Account::operator!=(const Account &rhs) const {
    return !(rhs == *this);
}


/*
    @param            :   Pointer to a Post object
    @param            :   The new title of the Post (or an empty string if you do not
                          want to change it)
    @param            :   The new body of the Post (or an empty string if you do not
                          want to change it)

    @post            :   This function will take the Post and given the new title and body,
                         update the Posts title and body as appropriate. It will also update the `timestamp_` to the current time of the update. This function should then
                         update the location of the Post in its list of `posts_` to the front of the list as well as utilizing its Network pointer to do the same in the `feed_`.

    You are encouraged to create your own helper functions for this endevour.
*/


void Account::updatePost(Post * post,string &title,string &body){
    for (int i = 0; i < posts.getSize(); ++i) {
        if (post->getTitle() == posts.getAtPos(i)->getItem()->getTitle()){
            posts.getAtPos(i)->getItem()->setTitle(title);
            posts.getAtPos(i)->getItem()->setBody(body);
            posts.getAtPos(i)->getItem()->setTimeStamp();
            Post * post1 = posts.getAtPos(i)->getItem();
            posts.moveItemToTop(post1);
            network->updatePost(post,title,body);
            break;
        }
    }

}


/*
    @param            :   A pointer to a Post
    @return           :   If the Post was successfully found and removed

    This function will remove the given Post from its list as well as from the Network's feed.
    Returns True if successfully removed, False if not. Afterwards, tell the Network to remove
    the Post as well from its feed.

    You are encouraged to create your own helper functions for this endevour.
*/
bool Account::removePost(Post *post) {
    for (int i = 0; i < posts.getSize(); ++i) {
        if (post->getTitle() == posts.getAtPos(i)->getItem()->getTitle()){
            posts.remove(i);
            return network->removePostFromNetwork(post);
        }
    }
}