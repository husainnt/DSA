#pragma once // Header guard

#include <iostream>
#include <string>
using namespace std;

class Transaction {
private:
    int transaction_id;
    double amount;
    string transaction_type;

public:
    Transaction() : transaction_id(0), amount(0), transaction_type("") {}
    Transaction(int id, double amt, string type) : transaction_id(id), amount(amt), transaction_type(type) {}

    void display_transaction() {
        cout << "Transaction ID: " << transaction_id << endl;
        cout << "Amount: " << amount << endl;
        cout << "Type: " << transaction_type << endl << endl;
    }

    string get_transaction_type() const {
        return transaction_type;
    }

    double get_amount() const {
        return amount;
    }
};

