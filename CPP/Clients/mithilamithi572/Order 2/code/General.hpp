#ifndef CODE_GENERAL_HPP
#define CODE_GENERAL_HPP
#include "Post.hpp"
#include <string>

enum REACTIONS {LIKE,DISLIKE,LAUGH,WOW,SAD,ANGRY};  // Enum for hold the reactions data type

class General : public Post{
private:
    int reactionCount[6];       // integer array

public:
    General();                  // Default constructor
    General(string,string);     // Parameterized constructor

    // Mutator
    bool reactToPost(REACTIONS reaction);  // set the reacts based on the array value

    // GetReaction function
    void getReactions() const;

    //DISPLAYING
    void displayPost() const;       // function to display the post
};


#endif //CODE_GENERAL_HPP
