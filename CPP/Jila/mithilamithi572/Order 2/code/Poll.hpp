#ifndef CODE_POLL_HPP
#define CODE_POLL_HPP

#include <vector>
#include <string>

#include "Post.hpp"


class Poll: public Post{
private:
    vector<string> poll_options;    // String vector to hold the poll options
    vector<int> votes_count;        // Count of the votes of each poll stores

public:
    // Constructors
    Poll();
    Poll(string,string, vector<string>);    // parameterized constructor

    bool votePoll(int option);              // Mutator to vote a poll option

    void changePollOption(string poll_option,int choice_number);

    // Accessors
    void getPollOptions() const;
    int getPollVotes(int index_option);

    //DISPLAY
    void displayPost() const;
};


#endif //CODE_POLL_HPP
