#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

using namespace std;

// Forward declarations
class Transaction;
class Account;
class Customer;

const int MAX_CUSTOMERS = 100;
const int MAX_ACCOUNTS = 100;
const int MAX_TRANSACTIONS = 100;

// Transaction class
class Transaction
{
private:
    int account_number;
    string account_type;
    double balance;
    string creation_date;

    Transaction *transactions[MAX_TRANSACTIONS]; // Maximum 100 transactions per account
    int num_transactions;

public:
    Account() : account_number(0), account_type(""), balance(0), num_transactions(0), creation_date("")
    {
        // Initialize transactions array
        for (int i = 0; i < MAX_TRANSACTIONS; ++i)
        {
            transactions[i] = nullptr;
        }
    }

    Account(int acc_number, string savingcurrent, int balances, string creation_dates)
        : account_number(acc_number), account_type(savingcurrent), balance(balances), num_transactions(0), creation_date(creation_dates)
    {
        // Initialize transactions array
        for (int i = 0; i < MAX_TRANSACTIONS; ++i)
        {
            transactions[i] = nullptr;
        }
    }

    void add_transaction(Transaction *transaction)
    {
        // Ensure maximum transactions limit is not exceeded
        if (num_transactions < 100)
        {
            transactions[num_transactions++] = transaction;
            // Update balance based on transaction type
            if (transaction->get_transaction_type() == "Deposit")
            {
                balance += transaction->get_amount();
            }
            else if (transaction->get_transaction_type() == "Withdrawal")
            {
                balance -= transaction->get_amount();
            }
            // Save transaction to file
            ofstream outFile("transaction.txt", ios::app); // Open file in append mode
            if (outFile.is_open())
            {
                outFile << "Account Number: " << account_number << endl;
                outFile << "Amount: " << transaction->get_amount() << endl;
                outFile << "Type: " << transaction->get_transaction_type() << endl
                        << endl;
                outFile << "Balance: " << balance << endl;

                outFile.close();
            }
            else
            {
                cout << "Unable to open file." << endl;
            }
        }
        else
        {
            cout << "Maximum transactions limit reached for this account." << endl;
        }
    }

    void display_transactions()
    {
        cout << "Transactions for Account Number: " << account_number << endl;
        for (int i = 0; i < num_transactions; ++i)
        {
            if (transactions[i] != nullptr)
            {
                transactions[i]->display_transaction();
            }
        }
    }

    double get_balance() const
    {
        return balance;
    }

    int get_account_number() const
    {
        return account_number;
    }

    string get_creation_date() const
    {
        return creation_date;
    }
};

// Account class
class Account
{
private:
    int account_number;
    string account_type;
    double balance;
    string creation_date;

    Transaction *transactions[MAX_TRANSACTIONS]; // Maximum 100 transactions per account
    int num_transactions;

public:
    Account() : account_number(0), account_type(""), balance(0), num_transactions(0), creation_date("")
    {
        // Initialize transactions array
        for (int i = 0; i < MAX_TRANSACTIONS; ++i)
        {
            transactions[i] = nullptr;
        }
    }

    Account(int acc_number, string savingcurrent, int balances, string creation_dates)
        : account_number(acc_number), account_type(savingcurrent), balance(balances), num_transactions(0), creation_date(creation_dates)
    {
        // Initialize transactions array
        for (int i = 0; i < MAX_TRANSACTIONS; ++i)
        {
            transactions[i] = nullptr;
        }
    }

    void add_transaction(Transaction *transaction)
    {
        // Ensure maximum transactions limit is not exceeded
        if (num_transactions < 100)
        {
            transactions[num_transactions++] = transaction;
            // Update balance based on transaction type
            if (transaction->get_transaction_type() == "Deposit")
            {
                balance += transaction->get_amount();
            }
            else if (transaction->get_transaction_type() == "Withdrawal")
            {
                balance -= transaction->get_amount();
            }
            // Save transaction to file
            ofstream outFile("transaction.txt", ios::app); // Open file in append mode
            if (outFile.is_open())
            {
                outFile << "Account Number: " << account_number << endl;
                outFile << "Amount: " << transaction->get_amount() << endl;
                outFile << "Type: " << transaction->get_transaction_type() << endl
                        << endl;
                outFile << "Balance: " << balance << endl;

                outFile.close();
            }
            else
            {
                cout << "Unable to open file." << endl;
            }
        }
        else
        {
            cout << "Maximum transactions limit reached for this account." << endl;
        }
    }

    void display_transactions()
    {
        cout << "Transactions for Account Number: " << account_number << endl;
        for (int i = 0; i < num_transactions; ++i)
        {
            if (transactions[i] != nullptr)
            {
                transactions[i]->display_transaction();
            }
        }
    }

    double get_balance() const
    {
        return balance;
    }

    int get_account_number() const
    {
        return account_number;
    }

    string get_creation_date() const
    {
        return creation_date;
    }
};
// Customer class
class Customer
{
private:
    string first_name;
    string last_name;
    int customer_cnic;
    Account *account;

public:
    Customer() : first_name(""), last_name(""), customer_cnic(0), account(nullptr) {}

    Customer(string fname, string lname, int id) : first_name(fname), last_name(lname), customer_cnic(id), account(nullptr) {}

    void set_account(Account *acc)
    {
        account = acc;
    }

    void display_account_details()
    {
        cout << "Customer Name: " << first_name << " " << last_name << endl;
        cout << "Customer CNIC: " << customer_cnic << endl;
        if (account != nullptr)
        {
            cout << "Account Number: " << account->get_account_number() << endl;
            cout << "Balance: " << account->get_balance() << endl;
            cout << "Creation Date: " << account->get_creation_date() << endl;
        }
        else
        {
            cout << "No account linked." << endl;
        }
    }

    Account *get_account() const
    {
        return account;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        QLabel *loadingLabel = new QLabel("Loading...", this);
        layout->addWidget(loadingLabel);

        progressBar = new QProgressBar(this);
        progressBar->setRange(0, 100);
        layout->addWidget(progressBar);

        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
        timer->start(100);

        QPushButton *startButton = new QPushButton("Start", this);
        connect(startButton, &QPushButton::clicked, this, &MainWindow::startMenu);
        layout->addWidget(startButton);

        setWindowTitle("Bank Management System");
        resize(400, 200);
    }

private slots:
    void updateProgressBar()
    {
        static int progress = 0;
        progressBar->setValue(progress);
        progress = (progress + 1) % 101;
    }

    void startMenu()
    {
        menuScreen = new QWidget(this);
        menuScreen->setWindowTitle("Menu");
        menuScreen->resize(400, 200);

        QVBoxLayout *layout = new QVBoxLayout(menuScreen);

        QLabel *menuLabel = new QLabel("Menu Screen", menuScreen);
        layout->addWidget(menuLabel);

        QPushButton *option1Button = new QPushButton("Display All Customers", menuScreen);
        connect(option1Button, &QPushButton::clicked, this, &MainWindow::displayAllCustomers);
        layout->addWidget(option1Button);

        QPushButton *option2Button = new QPushButton("Perform Transaction", menuScreen);
        connect(option2Button, &QPushButton::clicked, this, &MainWindow::performTransaction);
        layout->addWidget(option2Button);

        QPushButton *option3Button = new QPushButton("Add Customer", menuScreen);
        connect(option3Button, &QPushButton::clicked, this, &MainWindow::addCustomer);
        layout->addWidget(option3Button);

        QPushButton *option4Button = new QPushButton("Search Customer", menuScreen);
        connect(option4Button, &QPushButton::clicked, this, &MainWindow::searchCustomer);
        layout->addWidget(option4Button);

        QPushButton *exitButton = new QPushButton("Exit", menuScreen);
        connect(exitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
        layout->addWidget(exitButton);

        menuScreen->show();
    }

    void displayAllCustomers(Customer customers[], Account accounts[])
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

    void performTransaction(Customer customers[], Account accounts[])
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
                Transaction transaction(0, amount, type); // Transaction ID is not used here
                accounts[i].add_transaction(&transaction);
                cout << "Transaction added successfully." << endl;
                account_found = true;
                break; // Exit the loop once the account is found
            }
        }
        if (!account_found)
        {
            cout << "Invalid account ID. Please try again." << endl;
        }
    }

    void addCustomer(Customer customers[], Account accounts[], Transaction transactions[], int &count)
    {
        // Check if the arrays are full
        if (count >= MAX_CUSTOMERS || count >= MAX_ACCOUNTS)
        {
            cout << "Cannot add more customers. Arrays are full." << endl;
            return;
        }

        string fname, lname, account_type, creation_date;
        int cnic, account_number, balance;

        cout << "Enter customer details (First Name Last Name CNIC): " << endl;
        cout << "Enter First Name: ";
        cin >> fname;

        cout << "Enter Last Name: ";
        cin >> lname;

        cout << "Enter CNIC: ";
        cin >> cnic;

        cout << "Enter Account Number: ";
        cin >> account_number;

        cout << "Enter Account Type (Saving/Current): ";
        cin >> account_type;

        cout << "Enter Current Balance: ";
        cin >> balance;

        cout << "Enter Creation Date (without space): ";
        cin >> creation_date;

        // Create Customer and Account objects
        customers[count] = Customer(fname, lname, cnic);
        accounts[count] = Account(account_number, account_type, balance, creation_date);
        customers[count].set_account(&accounts[count]);
        accounts[count].add_transaction(&transactions[count]);

        // Increment count
        count++;

        // Write data to file
        ofstream outFile("bank.txt", ios::app); // Open file in append mode
        if (outFile.is_open())
        {
            outFile << fname << "\t" << lname << "\t" << cnic << "\t" << account_number << "\t" << account_type << "\t" << balance << "\t" << creation_date << endl;
            outFile.close();
        }
        else
        {
            cout << "Unable to open file." << endl;
        }

        cout << "Customer added successfully." << endl;
    }

    void searchCustomer(Customer customers[], int count)
    {
        long search_cnic;
        bool found = false;

        cout << "Enter CNIC to search: ";
        cin >> search_cnic;

        for (int i = 0; i < count; ++i)
        {
            if (customers[i].get_account() != nullptr &&
                customers[i].get_account()->get_account_number() != 0 &&
                customers[i].get_account()->get_balance() != 0 &&
                !customers[i].get_account()->get_creation_date().empty())
            {
                // Additional checks added to ensure valid data before accessing
                if (customers[i].get_account()->get_account_number() == search_cnic)
                {
                    cout << "Customer Found!" << endl;
                    customers[i].display_account_details();
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            cout << "Customer not found." << endl;
        }
    }

private:
    QProgressBar *progressBar;
    QWidget *menuScreen;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

#include "main.moc"
