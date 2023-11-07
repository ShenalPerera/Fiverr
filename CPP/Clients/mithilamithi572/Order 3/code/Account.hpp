#ifndef CODE_ACCOUNT_HPP
#define CODE_ACCOUNT_HPP


#include <string>
#include <vector>

#include "Post.hpp"
#include "Network.hpp"

using namespace std;

class Account {
private:
    string username;
    string password;
    vector<Post> posts;
    vector<string> following_usernames;
    Network<Account> * network;

public:
    Account();
    Account(string,string);

    //ACCESSOR and MUTATORS
    void setUsername(string);
    string getUsername() const;

    void setNetwork(Network<Account> * network_entry);
    Network<Account> * getNetwork() const;

    void setPassword(string);
    string getPassword() const;

    // Displaying

    bool addPost(string,string);

    void viewPosts() const;


    bool followAccount(string username_to_follow);
    vector<string> getFollowers() const;

};


#endif //CODE_ACCOUNT_HPP
