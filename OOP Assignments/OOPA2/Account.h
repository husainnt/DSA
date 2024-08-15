#pragma once // Header guard

#include "Transaction.h" // Include necessary dependencies

#include <iostream>
#include <string>

using namespace std;


// Account class
class Account {
private:
    int account_number;
    string account_type;
    double balance;
    string creation_date;

    Transaction* transactions[100]; // Maximum 100 transactions per account
    int num_transactions;

public:
    Account() : account_number(0), account_type(""), balance(0), num_transactions(0), creation_date("") {
        // Initialize transactions array
        for (int i = 0; i < 100; ++i) {
            transactions[i] = nullptr;
        }
    }

    Account(int acc_number, string savingcurrent, int balances, string creation_dates)
        : account_number(acc_number), account_type(savingcurrent), balance(balances), num_transactions(0), creation_date(creation_dates) {
        // Initialize transactions array
        for (int i = 0; i < 100; ++i) {
            transactions[i] = nullptr;
        }
    }

    void add_transaction(Transaction* transaction) {
        // Ensure maximum transactions limit is not exceeded
        if (num_transactions < 100) {
            transactions[num_transactions++] = transaction;
            // Update balance based on transaction type
            if (transaction->get_transaction_type() == "Deposit") {
                balance += transaction->get_amount();
            } else if (transaction->get_transaction_type() == "Withdrawal") {
                balance -= transaction->get_amount();
            }
            // Save transaction to file
            ofstream outFile("transaction.txt", ios::app); // Open file in append mode
            if (outFile.is_open()) {
                outFile << "Account Number: " << account_number << endl;
                outFile << "Amount: " << transaction->get_amount() << endl;
                outFile << "Type: " << transaction->get_transaction_type() << endl << endl;
                outFile << "Balance: " << balance << endl;

                outFile.close();
            } else {
                cout << "Unable to open file." << endl;
            }
        } else {
            cout << "Maximum transactions limit reached for this account." << endl;
        }
    }

    void display_transactions() {
        cout << "Transactions for Account Number: " << account_number << endl;
        for (int i = 0; i < num_transactions; ++i) {
            if (transactions[i] != nullptr) {
                transactions[i]->display_transaction();
            }
        }
    }

    double get_balance() const {
        return balance;
    }

    int get_account_number() const {
        return account_number;
    }

    string get_creation_date() const {
        return creation_date;
    }
};