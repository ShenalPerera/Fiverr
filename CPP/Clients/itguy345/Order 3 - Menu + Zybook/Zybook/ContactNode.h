#ifndef ZYBOOK_CONTACTNODE_H
#define ZYBOOK_CONTACTNODE_H
#include <string>
using namespace std;

class ContactNode {
    private:
        char contactName[30];
        char contactPhoneNum[30];
        ContactNode* nextNodePtr;

    public:
        ContactNode(char* name, char* phoneNumber);
        void InsertAfter(ContactNode* contactNode);
        string GetName();
        char* GetPhoneNumber();
        ContactNode* GetNext() ;
        void PrintContactNode();
};


#endif //ZYBOOK_CONTACTNODE_H
