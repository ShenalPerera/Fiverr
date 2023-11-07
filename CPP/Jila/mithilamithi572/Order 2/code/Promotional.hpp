#ifndef CODE_PROMOTIONAL_HPP
#define CODE_PROMOTIONAL_HPP
#include <string>

#include "Post.hpp"

using namespace std;
class Promotional : public Post{
private:
    string url;

public:
    // Constructors
    Promotional();  // default
    Promotional(string,string,string); // parameterized constructor

    // Method to get the link
    string getLink() const;

    // Mutator
    bool setLink(string link);

    void displayPost() const;
};


#endif //CODE_PROMOTIONAL_HPP
