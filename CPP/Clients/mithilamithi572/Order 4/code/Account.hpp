#ifndef CODE_ACCOUNT_HPP
#define CODE_ACCOUNT_HPP


#include <string>
#include <vector>

#include "Post.hpp"
#include "Network.hpp"
#include "LinkedList.hpp"

using namespace std;

class Account {
private:
    string username;
    string password;
    LinkedList<Post*> posts;
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

    bool addPost(Post * const post  );

    void viewPosts() const;


    bool followAccount(string username_to_follow);
    vector<string> getFollowers() const;

    /**
     * @param          : A string (user name of the account)
     * @return         : number of posts removed
     *
     * This function will look through the body and title of all Posts in the Network's feed.
        If a Post contains the provided word or phrase, and remove from the Accounts feed.
     */
     int removeFromPosts(string& word);


    bool operator==(const Account &rhs) const;

    bool operator!=(const Account &rhs) const;

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

    void updatePost(Post * post,string& title,string& body);


    /*
    @param            :   A pointer to a Post
    @return           :   If the Post was successfully found and removed

    This function will remove the given Post from its list as well as from the Network's feed.
    Returns True if successfully removed, False if not. Afterwards, tell the Network to remove
    the Post as well from its feed.

    You are encouraged to create your own helper functions for this endevour.
*/
    bool removePost(Post * post);
};


#endif //CODE_ACCOUNT_HPP
