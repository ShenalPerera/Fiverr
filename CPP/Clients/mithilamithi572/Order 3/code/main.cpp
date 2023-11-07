#include <iostream>
#include "Network.hpp"
#include "Account.hpp"


using namespace std;
int main() {
    Network<Account> network;
    cout << "Current size = " << network.getSizeOfNetwork() << endl;
    cout << "Is empty = " << network.isEmpty() << endl;

    // Dummy accounts
    Account * account1 = new Account("Username1","password1");
    Account * account2 = new Account("Username2","Password2");
    Account * account3 = new Account("Username3","password3");



    if (network.addAccount(account1))  cout << "Adding account1             -> successful" << endl;
    if (!network.addAccount(account1)) cout << "Check adding account1 again -> successful" << endl;
    if (network.addAccount(account2))  cout << "Adding account2             -> successful" << endl;

    cout << "Current size = " << network.getSizeOfNetwork() << endl;
    cout << "Is empty = " << network.isEmpty() << endl;

    if (network.removeAccount(account1)) cout << "remove account1 -> successful" << endl;
    cout << "Current size = " << network.getSizeOfNetwork() << endl;


    cout << "clear the network" << endl;
    network.clear();

    cout << "Current size = " << network.getSizeOfNetwork() << endl;
    cout << "Is empty = " << network.isEmpty() << endl;

    cout << "Check contains" << endl;
    if (!network.containsAccount(account1)) cout << "contains function (account1) -> passed" << endl;
    network.addAccount(account3);

    cout << "Current size = " << network.getSizeOfNetwork() << endl;
    if (network.containsAccount(account3)) cout << "contains function (account3) -> passed" << endl;

    cout << "check populate function" << endl;
    network.populateNetwork("accounts.txt");
    cout << "Current size = " << network.getSizeOfNetwork() << endl;
    network.addAccount(account1);
    cout << "Current size = " << network.getSizeOfNetwork() << endl << endl;

    cout << "Check -= operator" << endl;
    cout << "Current size = " << network.getSizeOfNetwork() << endl;
    Network<Account>  bots;
    bots.addAccount(account1);
    bots.addAccount(account3);
    cout << "remove account 1 and account 3" << endl;
    network -= bots;
    cout << "Current size = " << network.getSizeOfNetwork() << endl;

    // Test Modified account class
    Account * new_account = new Account("Test_account","password");

    cout << "check network " << new_account->getNetwork() << endl;
    cout << "set network " << endl;
    Network<Account> * network1 = new Network<Account>;

    new_account->setNetwork(&network);
    cout << "check network " << new_account->getNetwork() << endl;

    if (new_account->followAccount("user2")){
        cout << "Follow success" << endl;
    }
    if (!new_account->followAccount("user2")){
        cout << "Follow success" << endl;
    }
    if (new_account->followAccount("user1234")){
        cout << "Follow success" << endl;
    }
    cout << new_account->followAccount("Username1")<<" "<< new_account->followAccount("Username3")<< endl;
    network.addAccount(account1);
    network.addAccount(account3);
    account1->addPost("Dummy post1 from Username1" , "This is dummy body");
    account1->addPost("Dummy post2 from Username1" , "This is dummy body");
    account3->addPost("Dummy post 1 from username3", "This is dummy body");

    Post post("Post without user","This will not be added to the feed");
    if (!network.addToFeed(post)) cout << "Success" << endl;
    post.setUsername("Username1");
    if (!network.addToFeed(post)) cout << "Success" << endl;


    network.printFeedForAccount(*new_account);

    return 0;
}
