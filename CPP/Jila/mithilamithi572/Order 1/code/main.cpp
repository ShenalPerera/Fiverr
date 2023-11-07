#include <iostream>
#include "Post.hpp"
#include "Account.hpp"

#include <string>

using namespace std;

int main() {
    Post post("Title 1","This is a dummy body");
    post.displayPost();

    cout << "\nBody is changing....\n\n";

    post.setBody("This body is now changed using public method of setBody()");
    post.setTitle("This is the changed title");
    post.displayPost();


    /// Testing the Account class

    string titles_and_body [5][2] {{"Title 1","Dummy body 1"},{"Title 2","Dummy body 2"},{"Title 3","Dummy body 3"},{"Title 4","Dummy body 4"},{"Title 5","Dummy body 5"}};
    // Create Account object
    Account account("Shenal_33","My_password");

    for (auto & i : titles_and_body) {
        account.addPost(i[0],i[1]);
    }

    account.viewPosts();
    return 0;
}
