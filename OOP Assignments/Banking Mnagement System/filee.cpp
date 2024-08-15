#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int MAX_CUSTOMERS = 100;

class account
{
private:
    int Accid;
    float balance;
    char creationdate[11]; // mm/dd/yyyy format
    char acctype;

public:
    account()
    {
        Accid = 0;
        balance = 0.0;
        strcpy(creationdate, "");
        acctype = '\0';
    }

    void fortrx()
    {
        cout << "Enter your account id: " << endl;
        cin >> Accid;
        cout << "Enter your account type  ('S' for saving and 'C' for current): " << endl;
        cin >> acctype;
    }

    void add()
    {
        cout << "Enter a suitable account id for your account: " << endl;
        cin >> Accid;
        cout << "Enter the opening balance for your account: " << endl;
        cin >> balance;
        cout << "Enter the date as of today on which the account is being created in the form (mm/dd/yyyy): " << endl;
        cin >> creationdate;
        cout << "Choose your account type ('S' for saving and 'C' for current): " << endl;
        cin >> acctype;
    }

    void displayAccount() const
    {
        cout << "Account ID: " << Accid << ", Balance: " << balance << ", Creation Date: " << creationdate << ", Account Type: " << acctype << endl;
    }

    int getAccid() const { return Accid; }
    float getBalance() const { return balance; }
    const char *getCreationDate() const { return creationdate; }
    char getAcctype() const { return acctype; }
};

class customer : public account
{
private:
    char Firstname[50];
    char Lastname[50];
    long cnic;

public:
    customer() : account()
    {
        strcpy(Firstname, "");
        strcpy(Lastname, "");
        cnic = 0;
    }

    void createacc()
    {
        cout << "Enter your First Name: " << endl;
        cin >> Firstname;
        cout << "Enter your Last Name: " << endl;
        cin >> Lastname;
        cout << "Enter your CNIC: " << endl;
        cin >> cnic;
        add();
    }

    void addcustomer()
    {
        cout << "Enter your First Name: " << endl;
        cin >> Firstname;
        cout << "Enter your Last Name: " << endl;
        cin >> Lastname;
        cout << "Enter your CNIC: " << endl;
        cin >> cnic;
    }

    void displayCustomer() const
    {
        cout << "Customer Name: " << Firstname << " " << Lastname << ", CNIC: " << cnic << endl;
        displayAccount();
    }

    const char *getFirstname() const { return Firstname; }
    const char *getLastname() const { return Lastname; }
    long getCnic() const { return cnic; }
};

class transaction : public account
{
private:
    int txid;
    char trxtype;
    float amount;
    char date[11]; // mm/dd/yyyy format
    int time;

public:
    transaction() : account()
    {
        txid = 0;
        trxtype = '\0';
        amount = 0.0;
        strcpy(date, "");
        time = 0;
    }

    void performtransac()
    {
        fortrx();
        cout << "Enter type of transaction('D' for debit and 'C' for credit): " << endl;
        cin >> trxtype;
        cout << "Enter amount for transaction: " << endl;
        cin >> amount;

        // Store the transaction in "transactions.txt"
        ofstream transFile("transactions.txt", ios::app);
        if (transFile.is_open())
        {
            transFile << getAccid() << " " << trxtype << " " << amount << endl;
            transFile.close();
        }
        else
        {
            cout << "Unable to open transactions file." << endl;
        }
    }
};

void loadCustomersFromFile(const char *filename, customer customers[], int &count)
{
    ifstream inFile(filename);
    if (!inFile.is_open())
    {
        cout << "Unable to open file " << filename << endl;
        return;
    }

    count = 0;
    while (inFile >> customers[count].getFirstname() >> customers[count].getLastname() >> customers[count].getCnic() >> customers[count].getAccid() >> customers[count].getBalance() >> customers[count].getCreationDate() >> customers[count].getAcctype())
    {
        count++;
    }
    inFile.close();
}

void saveCustomersToFile(const char *filename, customer customers[], int count)
{
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        cout << "Unable to open file " << filename << endl;
        return;
    }

    for (int i = 0; i < count; ++i)
    {
        outFile << customers[i].getFirstname() << " " << customers[i].getLastname() << " " << customers[i].getCnic() << " "
                << customers[i].getAccid() << " " << customers[i].getBalance() << " " << customers[i].getCreationDate() << " "
                << customers[i].getAcctype() << endl;
    }
    outFile.close();
}

void displayAllCustomers(customer customers[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        customers[i].displayCustomer();
    }
}

int main()
{
    customer customers[MAX_CUSTOMERS];
    int customerCount = 0;

    loadCustomersFromFile("bank.txt", customers, customerCount);

    int choice;
    while (true)
    {
        cout << "1. Add an account" << endl;
        cout << "2. Add a customer" << endl;
        cout << "3. Perform a transaction" << endl;
        cout << "4. Display all customers" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (customerCount < MAX_CUSTOMERS)
            {
                customers[customerCount].createacc();
                customerCount++;
                saveCustomersToFile("bank.txt", customers, customerCount);
            }
            else
            {
                cout << "Customer limit reached." << endl;
            }
            break;
        case 2:
            if (customerCount < MAX_CUSTOMERS)
            {
                customers[customerCount].addcustomer();
                customerCount++;
                saveCustomersToFile("bank.txt", customers, customerCount);
            }
            else
            {
                cout << "Customer limit reached." << endl;
            }
            break;
        case 3:
        {
            transaction trans;
            trans.performtransac();
        }
        break;
        case 4:
            displayAllCustomers(customers, customerCount);
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
