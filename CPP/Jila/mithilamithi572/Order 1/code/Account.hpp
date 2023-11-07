#ifndef CODE_ACCOUNT_HPP
#define CODE_ACCOUNT_HPP

#include <string>
#include <vector>

#include "Post.hpp"

using namespace std;

class Account {
private:
    string username;
    string password;
    vector<Post> posts;
public:
    Account();
    Account(string,string);

    //ACCESSOR and MUTATORS
    void setUsername(string);
    string getUsername() const;

    void setPassword(string);
    string getPassword() const;

    // Displaying

    bool addPost(string,string);

    void viewPosts() const;
};


#endif //CODE_ACCOUNT_HPP
