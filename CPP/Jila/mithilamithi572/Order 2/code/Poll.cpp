#include <iostream>
#include <vector>

#include "Poll.hpp"

Poll::Poll() {};

Poll::Poll(string title, string question, vector<string> options) : Post(title,question) {
    for (int i = 0; i < options.size(); ++i) {
        this->poll_options.push_back( options.at(i)) ;      // copy the values from option to poll_options vector
        this->votes_count.push_back(0);                       // Set the count of votes of each option to zero
    }
}

bool Poll::votePoll(int option) {
    if (option < 0 || option > poll_options.size()-1){  // check invalid index
        return false;                                   // return false
    }
    else{
        this->votes_count.at(option) += 1;                 // if not increase the value by one
    }
}

void Poll::changePollOption(string poll_option, int choice_number) {
    if (choice_number >=0 && choice_number <= poll_options.size()-1){
        this->poll_options.at(choice_number) = poll_option;     // change the relevant position option
    }
    else if(choice_number > poll_options.size()-1){
        this->poll_options.push_back(poll_option);              // add the option to the end
        this->votes_count.push_back(0);
    }
}

void Poll::getPollOptions() const {
    for (int i = 0; i < this->poll_options.size(); ++i) {
        cout << this->votes_count.at(i) << " votes for: " << this->poll_options.at(i) << endl;  // print the row
    }
}

int Poll::getPollVotes(int index_option) {
    return this->votes_count.at(index_option);     // return the relevant count of the votes
}

void Poll::displayPost() const {
    cout << "\n";
    cout << getTitle() << " at " << getTimeStamp() << endl;
    cout << getBody() << endl;
    cout << "\n";

    getPollOptions();           // print the count of each option
    cout << "\n";
}
