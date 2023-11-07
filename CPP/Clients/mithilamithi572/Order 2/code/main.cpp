#include <iostream>
#include "Post.hpp"
#include "General.hpp"
#include "Poll.hpp"
#include "Promotional.hpp"
#include <ctime>

#include <vector>

using namespace std;

int main() {
    // Testing General class

//    General general("Title1"," This is a dummy body for the general class");
//    general.displayPost();
//
//    general.reactToPost(LIKE);
//    general.displayPost();
//
//    general.reactToPost(ANGRY);
//    general.getReactions();

//    vector<string> count;
//    count.push_back("ten");
//    count.push_back("eleven");
//    count.push_back("Thirteen");
//
//    Poll poll("Poll 1","What is number of players in cricket team ?",count);
//    poll.getPollOptions();
//
//    poll.votePoll(0);
//    poll.votePoll(0);
//    poll.votePoll(1);
//    poll.votePoll(1);
//    poll.votePoll(1);
//    poll.votePoll(1);
//    poll.votePoll(1);
//    poll.votePoll(1);
//    poll.votePoll(1);
//    poll.votePoll(1);
//
//    poll.getPollOptions();
//    poll.changePollOption("nine",3);
//    poll.displayPost();

    Promotional promotional("Advertisement","Dummy body","https://www.validlink.lk");
    promotional.displayPost();



    return 0;
}
