#pragma once // Header guard

#include "Account.h" // Include necessary dependencies

#include <iostream>
#include <string>
using namespace std;


// Customer class
class Customer {
private:
    string first_name;
    string last_name;
    int costumer_cnic;
    Account* account;

public:
    Customer() : first_name(""), last_name(""), costumer_cnic(0), account(nullptr) {}

    Customer(string fname, string lname, int id) : first_name(fname), last_name(lname), costumer_cnic(id), account(nullptr) {}

    void set_account(Account* acc) {
        account = acc;
    }

    void display_account_details() {
        cout << "Customer Name: " << first_name << " " << last_name << endl;
        cout << "Customer CNIC: " << costumer_cnic << endl;
        if (account != nullptr) {
            cout << "Account Number: " << account->get_account_number() << endl;
            cout << "Balance: " << account->get_balance() << endl;
            cout << "Creation Date: " << account->get_creation_date() << endl;

        } else {
            cout << "No account linked." << endl;
        }
    }

    Account* get_account() const {
        return account;
    }
};