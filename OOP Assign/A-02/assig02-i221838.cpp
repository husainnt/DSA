//22i-1838,Hussain Tahir, OOP A-02,Sec:B 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Transaction.h"
#include "Account.h"
#include "Customer.h"

// Forward declarations
class Transaction;
class Account;
class Customer;

using namespace std;

const int MAX_CUSTOMERS = 100;
const int MAX_ACCOUNTS = 100;
const int MAX_TRANSACTIONS = 100;
int count = 0;

int read_data_from_file(const string &filename, Customer customers[], Account accounts[], Transaction transactions[])
{
    int countx;
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        int cust_idx = 0, acc_idx = 0, trans_idx = 0;
        while (getline(file, line))
        {
            stringstream ss(line);
            string token;

            // Read customer data
            getline(ss, token, '\t');
            string fname = token;
            getline(ss, token, '\t');
            string lname = token;
            getline(ss, token, '\t');
            int cnic;
            try
            {
                cnic = stoi(token);
            }
            catch (const invalid_argument &e)
            {
                cerr << "Invalid CNIC: " << token << endl;
                continue; // Skip this line and continue to the next iteration
            }
            customers[cust_idx] = Customer(fname, lname, cnic);

            // Read account data
            getline(ss, token, '\t');
            int account_number;
            try
            {
                account_number = stoi(token);
            }
            catch (const invalid_argument &e)
            {
                cerr << "Invalid account number: " << token << endl;
                continue; // Skip this line and continue to the next iteration
            }
            getline(ss, token, '\t');
            string account_type = token;
            getline(ss, token, '\t');
            int balance;
            try
            {
                balance = stoi(token);
            }
            catch (const invalid_argument &e)
            {
                cerr << "Invalid balance: " << token << endl;
                continue; // Skip this line and continue to the next iteration
            }
            getline(ss, token, '\t');
            string creation_date = token;
            accounts[acc_idx] = Account(account_number, account_type, balance, creation_date);

            // Associate customer with account and add transaction
            customers[cust_idx++].set_account(&accounts[acc_idx]);
            accounts[acc_idx++].add_transaction(&transactions[trans_idx++]);
            countx = acc_idx;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
    return countx;
}


void display_all_customers(Customer customers[], Account accounts[]);
void perform_transaction(Customer customers[], Account accounts[]);
void add_customer(Customer customers[], Account accounts[], Transaction transactions[], int count);
void search_costumer(Customer customers[], Account accounts[]);

int main()
{
    Customer customers[MAX_CUSTOMERS];
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
   
    count = read_data_from_file("bank.txt", customers, accounts, transactions);

    int choice;
    do
    {
 
        cout << "\nMENU:" << endl;
        cout << "1. Display All Customers" << endl;
        cout << "2. Perform Transaction" << endl;
        cout << "3. Add costumer" << endl;
        cout << "4. search costumer" << endl;

        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            display_all_customers(customers, accounts);
            break;
        case 2:
            perform_transaction(customers, accounts);
            break;
        case 3:
            add_customer(customers, accounts, transactions, count);
            break;
        case 4:
            search_costumer(customers, accounts);
            break;
        case 5:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
void search_costumer(Customer customers[], Account accounts[])
{
    int account_id;

    cout << "Enter Account Number to search Costumer: ";
    cin >> account_id;
    bool account_found = false;
    for (int i = 0; i < MAX_ACCOUNTS; i++)
    {
        if (account_id == accounts[i].get_account_number())
        {

            cout << endl;

            cout << "Details of the account" << endl;

            cout << "Customer details:" << endl;
            customers[i].display_account_details();

            cout << endl;
            cout << "Transactions for account:" << endl;
            accounts[i].display_transactions();
            cout << endl;
            break;
        }
        else
            cout << "Account not found" << endl;
        break;
    }
}
// Function definitions
void display_all_customers(Customer customers[], Account accounts[])
{
    
    for (int i = 0; i < MAX_CUSTOMERS; ++i)
    {
        if (customers[i].get_account() != nullptr && accounts[i].get_account_number() != 0)
        {
            cout << "Customer details:" << endl;
            customers[i].display_account_details();
            cout << endl;
        }
    }
}

void perform_transaction(Customer customers[], Account accounts[])
{
    int account_id;

    cout << "Enter account Number: ";
    cin >> account_id;
    bool account_found = false;
    for (int i = 0; i < MAX_ACCOUNTS; i++)
    {
        if (account_id == accounts[i].get_account_number())
        {
            double amount;
            string type;
            cout << "Enter transaction amount: ";
            cin >> amount;
            cout << "Enter transaction type (Deposit/Withdrawal): ";
            cin >> type;
            Transaction transaction(accounts[i].get_balance(), amount, type);
            accounts[i].add_transaction(&transaction);
            cout << "Transaction added successfully." << endl;
            account_found = true;
            break; 
        }
    }
    if (!account_found)
    {
        cout << "Invalid account ID. Please try again." << endl;
    }
}

void add_customer(Customer customers[], Account accounts[], Transaction transactions[], int count)
{

    
    string fname, lname, account_type, creation_date;
    int cnic, account_number, balance;

    cout << "Enter customer details (First Name Last Name CNIC): " << endl;
    cout << "Enter First Name  " << endl;
    cin >> fname;

    cout << "Enter Last Name  " << endl;
    cin >> lname;

    cout << "Enter  CNIC ";

    cin >> cnic;

    cout << "Enter Account Number " << endl;

    cin >> account_number;
    cout << "Enter  Account Type(Saving/Current)  " << endl;

    cin >> account_type;
    cout << "currrent Balance " << endl;

    cin >> balance;
    cout << "Enter  Creation Date (without space) " << endl;

    cin >> creation_date;

    

    customers[count] = Customer(fname, lname, cnic);
    accounts[count] = Account(account_number, account_type, balance, creation_date);
    customers[count].set_account(&accounts[count]);
    accounts[count].add_transaction(&transactions[count]);

    ofstream outFile("bank.txt", ios::app); 
    if (outFile.is_open())
    {
        
        outFile << fname << "\t" << lname << "\t" << cnic << "\t"
                << account_number << "\t" << account_type << "\t" << balance << "\t"
                << creation_date << endl;
        outFile.close();
        cout << "Data written to file successfully." << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
