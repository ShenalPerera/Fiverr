#include <iostream>
#include <string>

#include "General.hpp"

General::General() {};

General::General(string title, string body): Post(title,body) {
    // Loop through the integer array and initialized to zero
    for (int & i : this->reactionCount) {
        i = 0;
    }
}

bool General::reactToPost(REACTIONS reaction) {
    if (reaction <LIKE || reaction > ANGRY){        // check the limit of the given reaction
        return false;                               // return false if out of range
    }
    else{                                           // if within the range
        this->reactionCount[reaction] += 1;         // increase the relevant reaction's count by one
    }
}

void General::getReactions() const {
    cout << "Like : " << reactionCount[LIKE] << " | Dislike : " << reactionCount[DISLIKE] << " | Laugh : "
    << reactionCount[LAUGH] << " | Sad : " << reactionCount[SAD] << " | Angry : " << reactionCount[ANGRY];

}

void General::displayPost() const {
    cout << "\n" << getTitle() << " at " << getTimeStamp() << ":" << endl;
    cout << getBody() << endl;
    cout << "\n" ;
    getReactions();
    cout << endl;
}