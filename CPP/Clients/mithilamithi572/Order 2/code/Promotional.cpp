#include <iostream>
#include <string>
#include <regex>

#include "Promotional.hpp"

Promotional::Promotional() : Post(){};

Promotional::Promotional(string name, string body, string link): Post(name,body) {
    setLink(link);
}

string Promotional::getLink() const {
    return this->url;
}

bool Promotional::setLink(string link) {
    string regex_str = R"(^https?:\/\/(www\.)[-a-zA-Z0-9@:%_\+~#=]{1,}[\.][-a-zA-Z0-9@:%_\+~#=]{2,}$)";

    if (regex_match(link,regex(regex_str))){
        this->url = link;
        return true;
    }
    else{
        this->url= "Broken Link";
        return false;
    }
}

void Promotional::displayPost() const {
    cout << "\n";
    cout << getTitle() << " at " << getTimeStamp() << ":" << endl;
    cout << getBody() << endl;
    cout << "\n";
    cout << getLink() << endl;
    cout << "\n";
}
