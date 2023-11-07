#include <iostream>
#include <vector>
#include <fstream>

#include "Account.h"
#include "Transaction.h"

void accountRead(const string filename, vector<Account> & accounts);
void transactionRead(const string filename, vector<Transaction> & transactions);
void transactionWrite(const string filename, vector<Transaction> transactions);


int main() {
    vector<Account> accounts;
    vector<Transaction> transactions;

    accountRead("accounts.txt",accounts);

    // print account vector to console
    for (auto & account : accounts) {
        account.print();
        cout << endl;
    }

    transactionRead("encryptedTransactions.txt",transactions);

    // print transactions to the console
    for (auto & transaction : transactions) {
        transaction.print();
    }


    // find the account of Donna
    Account tempAccount;
    for (auto & account : accounts) {
        if (account.firstName == "Donna"){
            tempAccount = account;
            break;
        }
    }

    // Check through the transactions
    for (auto & transaction : transactions) {
        if (transaction.decrypt(tempAccount.getAccountNumber(),tempAccount.getPIN())){
            cout << "Donna is innocent" << endl;
            break;
        }
    }

    // find the hackers
    bool isHacker = true;

    // decrypt the data
    for (int i = 0; i < accounts.size(); ++i) {
        Account temp = accounts.at(i);
        isHacker = true;
        // update the transaction for this account
        for (int j = 0; j < transactions.size(); ++j) {
            if (transactions.at(j).decrypt(temp.getAccountNumber(),temp.getPIN())) {
                isHacker = false;
            }

        }
        if (isHacker){
            cout << temp.firstName << " is a hacker" << endl;
        }


    }

    // write to the file
    transactionWrite("decryptedTransactions.txt", transactions);


    return 0;
}


void accountRead(const string filename, vector<Account> & accounts){
    // create stream object
    ifstream fin(filename);

    // check the error condition in fille
    if (fin.fail()){
        cerr << "File can not be opened" << endl;
        exit(1);
    }
    string firstName,lastName,PIN, accountNumber;
    while (fin >> firstName >> lastName >> PIN >> accountNumber){

        // create account objects from the read file details
        Account tempAccount(firstName, lastName, PIN, accountNumber);

        // add the account to the vector
        accounts.push_back(tempAccount);
    }
    fin.close();
}



void transactionRead(const string filename, vector<Transaction> & transactions){
    // create stream object
    ifstream fin(filename);

    // check the error condition in fille
    if (fin.fail()){
        cerr << "File can not be opened" << endl;
        exit(1);
    }
    string fromAccount,toAccount,amount;
    while (fin >> fromAccount >> toAccount >> amount){

        // create account objects from the read file details
        Transaction tempTransaction(fromAccount, toAccount, amount);

        // add the account to the vector
        transactions.push_back(tempTransaction);
    }
    fin.close();
}


void transactionWrite(const string filename, vector<Transaction> transactions){
    // create stream object
    ofstream fout(filename);

    // check the error condition in fille
    if (fout.fail()){
        cerr << "File can not be opened" << endl;
        exit(1);
    }

    for (auto & transaction : transactions) {
        fout << transaction.getFromAccountNumber() << " " << transaction.getToAccountNumber() << " " << transaction.getAmount() << endl;
    }
    fout.close();
}