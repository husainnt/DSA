#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <ctime>
using namespace std;
char load = 219;
struct Node
{
	string NAME, PIN_N, MOBILE, CNIC_c, DATE;
	int AMOUNT;
	Node *prev;
	Node *next;
};
class Double_Pointer_Linked
{
private:
	Node *head, *tail;

public:
	Double_Pointer_Linked()
	{
		head = NULL;
	}
	void insert(string N, string P, string M, string C, int A, string D)
	{
		Node *newnode = new Node;

		newnode->NAME = N;
		newnode->PIN_N = P;
		newnode->MOBILE = M;
		newnode->CNIC_c = C;
		newnode->AMOUNT = A;
		newnode->DATE = D;
		newnode->next = NULL;
		newnode->prev = NULL;
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
	}
	void Create_New_Account(string N, string P, string M, string C, int A, string D)
	{
		int n;
		ifstream r("count.txt");
		if (r)
		{
			r >> n;
		}

		r.close();
		ifstream w("User.txt");
		string VL1, VL2, VL3, VL4, VL6;
		int VL5;
		Double_Pointer_Linked ob;
		for (int i = 0; i < n; i++)
		{

			w >> VL1;
			w >> VL2;
			w >> VL3;
			w >> VL4;
			w >> VL5;
			w >> VL6;
			insert(VL1, VL2, VL3, VL4, VL5, VL6);
			i = i + 5;
		}
		insert(N, P, M, C, A, D);
		Node *ptr;
		Update(ptr);
	}
	void display_ALL()
	{

		int n;
		ifstream r("count.txt");
		if (r)
		{
			r >> n;
		}

		r.close();
		ifstream w("User.txt");
		string VL1, VL2, VL3, VL4, VL6;
		int VL5;
		Double_Pointer_Linked ob;
		for (int i = 0; i < n; i++)
		{

			w >> VL1;
			w >> VL2;
			w >> VL3;
			w >> VL4;
			w >> VL5;
			w >> VL6;
			insert(VL1, VL2, VL3, VL4, VL5, VL6);
			i = i + 5;
		}
		Node *ptr;
		ptr = head;
		while (ptr != NULL)
		{
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t"
				 << "    NAME : " << ptr->NAME << endl;
			// cout<<"\t\t\t\t"<<"    ID : "<< ptr->PIN_N <<endl;
			cout << "\t\t\t\t\t"
				 << "    MOBILE : " << ptr->MOBILE << endl;
			cout << "\t\t\t\t\t"
				 << "    CNIC : " << ptr->CNIC_c << endl;
			cout << "\t\t\t\t\t"
				 << "    AMOUNT : " << ptr->AMOUNT << endl;
			cout << "\t\t\t\t\t"
				 << "    DATE : " << ptr->DATE << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			ptr = ptr->next;
		}
	}
	///////////////////////////////////
	void Update(Node *obj)
	{
		Node *ptr;
		ptr = obj;
		ptr = head;
		ofstream w("User.txt");
		while (ptr != NULL)
		{

			w << ptr->NAME << endl;
			w << ptr->PIN_N << endl;
			w << ptr->MOBILE << endl;
			w << ptr->CNIC_c << endl;
			w << ptr->AMOUNT << endl;
			w << ptr->DATE << endl;
			ptr = ptr->next;
		}
	}
	///////////////////////////////////
	void Deposit(string ID1, int New_amount)
	{
		int n;
		ifstream r("count.txt");
		if (r)
		{
			r >> n;
		}

		r.close();
		ifstream w("User.txt");
		string VL1, VL2, VL3, VL4, VL6;
		int VL5;
		Double_Pointer_Linked ob;
		for (int i = 0; i < n; i++)
		{

			w >> VL1;
			w >> VL2;
			w >> VL3;
			w >> VL4;
			w >> VL5;
			w >> VL6;
			insert(VL1, VL2, VL3, VL4, VL5, VL6);
			i = i + 5;
		}

		Node *ptr;
		ptr = head;
		while (ptr != NULL)
		{
			if (ptr->NAME == ID1)
			{

				ptr->AMOUNT = ptr->AMOUNT + New_amount;

				Update(ptr);
			}

			ptr = ptr->next;
		}
	}
	///////////////////////////////////
	void Withdraw_Amount(string ID1, int New_amount)
	{
		int n;
		ifstream r("count.txt");
		if (r)
		{
			r >> n;
		}

		r.close();
		ifstream w("User.txt");
		string VL1, VL2, VL3, VL4, VL6;
		int VL5;
		Double_Pointer_Linked ob;
		for (int i = 0; i < n; i++)
		{

			w >> VL1;
			w >> VL2;
			w >> VL3;
			w >> VL4;
			w >> VL5;
			w >> VL6;
			insert(VL1, VL2, VL3, VL4, VL5, VL6);
			i = i + 5;
		}

		Node *ptr;
		ptr = head;
		while (ptr != NULL)
		{
			if (ptr->NAME == ID1)
			{
				if (ptr->AMOUNT < New_amount)
				{

					system("cls");
					system("color 0A"); // this function set text color green
					cout << "\n\n\n\n\n\n";
					cout << "\t\t\t\t\t";
					for (int i = 0; i <= 31; i++)
						cout << load;
					cout << "\n";
					cout << "\t\t\t\t\t" << load << "                              " << load << endl;
					cout << "\t\t\t\t\t" << load << "  Sorry! Bank Balance is Low  " << load << endl;
					cout << "\t\t\t\t\t" << load << "                              " << load << endl;
					cout << "\t\t\t\t\t";
					for (int i = 0; i <= 31; i++)
						cout << load;
					cout << "\n";
					getch();
					system("cls");
				}
				else
					ptr->AMOUNT = ptr->AMOUNT - New_amount;

				Update(ptr);
			}

			ptr = ptr->next;
		}
	}
	//////////////////////////////////

	void Search_Account(string ID1, string no)
	{

		int n;
		ifstream r("count.txt");
		if (r)
		{
			r >> n;
		}

		r.close();
		ifstream w("User.txt");
		string VL1, VL2, VL3, VL4, VL6;
		int VL5;
		Double_Pointer_Linked ob;
		for (int i = 0; i < n; i++)
		{

			w >> VL1;
			w >> VL2;
			w >> VL3;
			w >> VL4;
			w >> VL5;
			w >> VL6;
			insert(VL1, VL2, VL3, VL4, VL5, VL6);
			i = i + 5;
		}

		int c = 0;
		Node *ptr;
		ptr = head;
		while (ptr != NULL)
		{
			if (ptr->NAME == ID1 || ptr->CNIC_c == no)
			{
				system("cls");
				cout << "\n\n\n\n\n\n";
				cout << "\t\t\t\t\t";
				for (int j = 0; j <= 31; j++)
					cout << load;
				cout << "\n";
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t";
				for (int j = 0; j <= 31; j++)
					cout << load;
				cout << "\n";
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
				cout << "\t\t\t\t\t" << load << "      |      Detail     |     " << load << endl;
				cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t"
					 << "    NAME : " << ptr->NAME << endl;
				// cout<<"\t\t\t\t"<<"    ID : "<< ptr->PIN_N <<endl;
				cout << "\t\t\t\t\t"
					 << "    MOBILE : " << ptr->MOBILE << endl;
				cout << "\t\t\t\t\t"
					 << "    CNIC : " << ptr->CNIC_c << endl;
				cout << "\t\t\t\t\t"
					 << "    AMOUNT : " << ptr->AMOUNT << endl;
				cout << "\t\t\t\t\t"
					 << "    DATE : " << ptr->DATE << endl;
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				c++;
				cout << "\t\t\t\t\t";
				for (int j = 0; j <= 31; j++)
					cout << load;
				cout << "\n";
			}

			ptr = ptr->next;
		}
		if (c == 0)
		{
			system("cls");
			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "  SORRY THIS ID NOT FOUND     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
		}
	}

	/////////////////////////////////
};
class Bank
{
public:
	// Starting line design
	virtual void starting_line(string a) {

	};
	// Introduction of group memebers
	virtual void group_introduction() {

	};

	// user login function
	virtual bool User_login() {

	};
	virtual int main_manu()
	{
	}
	// Main manue function
	virtual int setting()
	{
	}
	virtual void change_user_id()
	{
	}
	virtual void change_user_PIN()
	{
	}
	virtual void logout()
	{
	}
	virtual void Create_Account()
	{
	}
	virtual bool login_user_account()
	{
	}

	virtual void Search_accounts()
	{
	}
	virtual int User_Login_Manu()
	{
	}
	virtual void Withdraw()
	{
	}
	virtual void Detail()
	{
	}
	virtual string IntToString(int a)
	{
	}
	virtual void Deposit()
	{
	}
	virtual void Display_Accounts()
	{
	}
};

class Man_u : public Bank
{
private:
	string ID, PIN, confirm_pin;
	char password, password2;
	int confirm;

public:
	int main_manu()
	{
		int Select;
		do
		{
			system("cls");
			system("color 0A"); // this function set text color green
			cout << "\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 33; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                                " << load << endl;
			cout << "\t\t\t\t\t" << load << "   BANKING MANAGEMENT SYSTEM    " << load << endl;
			cout << "\t\t\t\t\t" << load << "                                " << load << endl;
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 33; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                                " << load << endl;
			cout << "\t\t\t\t\t" << load << "                                " << load << endl;
			cout << "\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
			cout << "\t\t\t\t\t" << load << "       |     Main Manu   |      " << load << endl;
			cout << "\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
			cout << "\t\t\t\t\t" << load << "                                " << load << endl;
			cout << "\t\t\t\t\t" << load << "    [1]  :  Create Account      " << load << endl;
			cout << "\t\t\t\t\t" << load << "    [2]  :  Login User Account  " << load << endl;
			cout << "\t\t\t\t\t" << load << "    [3]  :  Display Accounts    " << load << endl;
			cout << "\t\t\t\t\t" << load << "    [4]  :  Search Accounts     " << load << endl;
			cout << "\t\t\t\t\t" << load << "    [5]  :  Setting             " << load << endl;
			cout << "\t\t\t\t\t" << load << "________________________________" << load << endl;
			cout << "\t\t\t\t\t" << load << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << load << endl;
			cout << "\t\t\t\t\t" << load << "      Logout (Press: esc)       " << load << endl;
			cout << "\t\t\t\t\t" << load << "________________________________" << load << endl;
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 33; i++)
				cout << load;
			cout << "\n";

			Select = _getch();
		} while (Select != '1' && Select != '2' && Select != '3' && Select != '4' && Select != '5' && Select != '6' && Select != 27);
		return Select; // used to return the selected value

	} // end manu func

	// Setting function
	int setting()
	{
		int Select;
		do
		{
			system("cls");
			system("color 0A"); // this function set text color green
			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      -------------------     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      |     SETTING     |     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      -------------------     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      [1]   :  Change ID      " << load << endl;
			cout << "\t\t\t\t\t" << load << "      [2]   :  Change PIN     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "______________________________" << load << endl;
			cout << "\t\t\t\t\t" << load << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      Back  (<-Backspace)     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";

			Select = _getch();
		} while (Select != '1' && Select != '2' && Select != 8);
		return Select; // it is used to return the selected value
	} // end setting func

	// Logout function
	void logout()
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t\t";
		cout << "Logout.";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);

	} // end logout fun

	// this pin is used to change user ID for login in software
	void change_user_id()
	{
		system("cls");
		string ID, PIN;
		int confirm;
		ifstream read("user login.txt");
		read >> ID;
		read >> PIN;
		read.close();
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      |     SETTING     |     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "      New ID :";
		cin >> ID;

		cout << "\t\t\t\t\t" << load << "      New ID Confirm  (Y/N)   " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		confirm = _getch();

		if (confirm == 'y' || confirm == 'Y')
		{
			ofstream wrt("user login.txt");
			wrt << ID << endl;
			wrt << PIN;
			wrt.close();
		}
		else if (confirm == 'n' || confirm == 'N')
		{
		}

		else
			change_user_id();

		system("cls");
	} // end ID func

	// this Function is used to change user PIN for login in software
	void change_user_PIN()
	{

		ifstream read("user login.txt");
		read >> ID;
		// cin >> pin;
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "      -------------------     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      |     SETTING     |     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      -------------------     " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t       New PIN :     ";

		while (password != 13)
		{
			if (password >= 48 && password <= 57) // only enter numeric value in PIN
			{
				PIN.push_back(password); // store char by char in string (PIN)
				cout << '*';
			}
			password = _getch();
		}
		cout << endl;
		cout << "\t\t\t\t\t       Confirm PIN : ";

		while (password2 != 13) // for confirm PIN
		{
			if (password2 >= 48 && password2 <= 57) // only enter numeric value in PIN
			{
				confirm_pin.push_back(password2); // store char by char in string (confirm_pin)
				cout << '*';
			}
			password2 = _getch();
		}
		cout << endl;
		cout << "\t\t\t\t\t" << load << "      Submite  (Y/N)          " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int j = 0; j <= 31; j++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		confirm = _getch();

		if (confirm == 'y' || confirm == 'Y')
		{
			if (PIN == confirm_pin)
			{
				ofstream wrt("user login.txt");
				wrt << ID << endl;
				wrt << PIN;

				wrt.close();
			}
		}
		else if (confirm == 'n' || confirm == 'N')
		{
		}

		else
		{
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n\n";
			cout << "\t\t\t\t\tPlease Enter Correct ID and PIN\n\n";
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";
			change_user_PIN();
		}

		read.close();
	} // PIN func end
};
class Login : public Bank
{
public:
	// Starting line design
	void starting_line(string a)
	{
		system("cls");
		system("color 7d");
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t" << a << endl
			 << endl
			 << endl;
		for (int i = 0; i < 118; i++)
		{
			Sleep(15);
			cout << load;
		}
		system("CLS");

	} // end starting line fun

	// Introduction of group memebers
	void group_introduction()
	{

		system("color 0A");
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      |  Group Members  |     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "        Hussain Tahir      " << load << endl;
		cout << "\t\t\t\t\t" << load << "        Haider Rizwan         " << load << endl;
		cout << "\t\t\t\t\t" << load << "                           " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		getch();
		system("cls");

		system("color 0A");
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n\n\n";
		cout << "\t\t\t      Loading ";

		for (int i = 0; i < 35; i++)
		{
			cout << load;
			if (i < 10)
				Sleep(300);
			if (i >= 10 && i < 20)
				Sleep(150);
			if (i >= 10)
				Sleep(25);
		}
		system("cls");

	} // end intro func

	/////////////////////////////////////////////////////

	bool User_login()
	{

		string user_id, pin, compare_id, compare_pin;
		char password;
		system("color 0A");
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 32; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t" << load << "   BANKING MANAGEMENT SYSTEM   " << load << endl;
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 32; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~      " << load << endl;
		cout << "\t\t\t\t\t" << load << "      |      Login      |      " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~      " << load << endl;
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t" << load << "       Please enter your       " << load << endl;
		cout << "\t\t\t\t\t" << load << "      User id and Password     " << load << endl;
		cout << "\t\t\t\t\t" << load << "    For login this Software    " << load << endl;
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t" << load << "                               " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 32; i++)
			cout << load;
		cout << "\n";
		ifstream rd("user login.txt");
		if (!rd.is_open())
		{
			ofstream wrt("user login.txt");
			wrt << "root\n";
			wrt << "1234";
		}
		else
		{
			rd >> compare_id;
			rd >> compare_pin;
			cout << "\n\t\t\t\t\t  User ID:   ";
			cin >> user_id;
			cout << "\t\t\t\t\t      PIN:   ";

			// cin >> pin;

			while (password != 13) // ascii code of enter. this will turminate on enter
			{
				if (password >= 48 && password <= 57) // take value only in numeric form
				{
					pin.push_back(password);
					cout << '*';
				}
				password = _getch(); // take value char by char
			}
		}

		if (user_id == compare_id && pin == compare_pin) // used to compare real ID and PIN with entered values
			return true;
		else
			return false;

	} // end user_login func
};

class Customer : public Bank
{
private:
	char password;
	string id, Phone, CNIC, pin, retype_pin, date;
	int length, Total_amount;

public:
	void Create_Account()
	{
		system("color 0A");
		id = "\0";
		Phone = "\0";
		CNIC = "\0";
		pin = "\0";

		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      |   New Account   |     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t  User Name : ";

		cin >> id;

		length = 0;
		password = 0;

		cout << "\t\t\t\t\t  PIN       : ";
		while (length != 4) // ascii code of enter. this will turminate on enter
		{
			if (password >= 48 && password <= 57) // take value only in numeric form
			{
				pin.push_back(password);
				cout << "*";
				length++;
			}
			password = _getch(); // take value char by char
		}

		length = 0;
		password = 0;
		cout << "\n\t\t\t\t\t  Mobile    : ";
		while (length != 11) // ascii code of enter. this will turminate on enter
		{
			if (password >= 48 && password <= 57) // take value only in numeric form
			{
				Phone.push_back(password);
				cout << password;
				length++;
				if (length == 4)
					cout << "-";
			}
			password = _getch(); // take value char by char
		}
		length = 0;
		password = 0;
		cout << "\n\t\t\t\t\t  CNIC      : ";
		while (length != 13) // ascii code of enter. this will turminate on enter
		{
			if (password >= 48 && password <= 57) // take value only in numeric form
			{
				CNIC.push_back(password);
				cout << password;
				length++;
				if (length == 5 || length == 12)
					cout << "-";
			}
			password = _getch(); // take value char by char
		}
		cout << "\n\t\t\t\t\t  Date     : ";
		time_t now = time(0);
		tm *ltm = localtime(&now);
		// print various components of tm structure.
		cout << ltm->tm_mday;
		cout << ":" << 1 + ltm->tm_mon;
		cout << ":" << 1900 + ltm->tm_year << endl;

		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int j = 0; j <= 31; j++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";

		string a;
		ofstream te("t.txt");
		te << ltm->tm_mday << ":" << 1 + ltm->tm_mon << ":" << 1900 + ltm->tm_year << endl;
		te.close();
		ifstream to("t.txt");
		to >> a;
		Double_Pointer_Linked Ob;
		Ob.Create_New_Account(id, pin, Phone, CNIC, 5000, a);
		ifstream r("count.txt");

		int i = 0;
		if (r)
		{
			r >> i;
			ofstream s("count.txt");
			i = i + 6;
			s << i;
		}
		else
		{
			ofstream s("count.txt");
			i = 0;
			i = i + 6;
			s << i;
		}

		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n\n";
		cout << "\t\t\t\t\t" << load << "   Account Has Been Created   " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n\n";
		r.close();
	}

	void Display_Accounts()
	{
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int i = 0; i <= 31; i++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "      -------------------     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      |   All Accounts  |     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      -------------------     " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;

		Double_Pointer_Linked ob;

		ob.display_ALL();
	}
};
class User_Account : public Bank
{
private:
	string id, check_id, pin, check_pin, data, data1, data2, data3, data4;
	int password, length, no, g;
	int index, index1, index2, position;
	int W, D;

public:
	//////////////////////////////////////////////////

	bool login_user_account()
	{
		bool log = false;
		system("color 0A");
		length = 0;
		password = 0;
		pin = "\0";
		cout << "\n\n\n\n\n\n";
		cout << "\t\t\t\t\t";
		for (int j = 0; j <= 31; j++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int j = 0; j <= 31; j++)
			cout << load;
		cout << "\n";
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      |  Login Account  |     " << load << endl;
		cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t         ID  : ";
		cin >> id;
		cout << "\t\t\t\t\t         PIN : ";
		while (password != 13 && length != 4) // ascii code of enter. this will turminate on enter
		{
			if (password >= 48 && password <= 57) // take value only in numeric form
			{
				pin.push_back(password);
				cout << "*";
				length++;
			}
			password = _getch(); // take value char by char
		}
		ifstream r("count.txt");
		if (r)
		{
			r >> no;
		}

		r.close();
		ifstream w("User.txt");
		for (int i = 0; i < no; i++)
		{
			cout << endl;
			w >> check_id;
			w >> check_pin;
			w >> data1;
			w >> data2;
			w >> data3;
			w >> data4;
			if (check_id == id && check_pin == pin)
			{

				cout << "\t\t\t\t\t";
				for (int j = 0; j <= 31; j++)
					cout << load;
				cout << "\n";
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t       WELCOME  [" << check_id << "]" << endl;
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				position = i;
				cout << "\t\t\t\t\t";
				for (int j = 0; j <= 31; j++)
					cout << load;
				cout << "\n\n";
				getch();
				log = true;
			}

			i = i + 5;
		}
		w.close();
		if (log == false)
		{
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "     Incorrect Password       " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n\n";
			getch();
		}
		return log;
	}

	//	|||||||||||||||||||||||||||||||||||||||||||||||||

	void Search_accounts()
	{
		system("color 0A");
		length = 0;
		password = 0;
		pin = "\0";
		int option;
		do
		{
			system("cls");
			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      |     Search      |     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "        [1]   :   ID          " << load << endl;
			cout << "\t\t\t\t\t" << load << "        [2]   :   CNIC        " << load << endl;
			cout << "\t\t\t\t\t" << load << "______________________________" << load << endl;
			cout << "\t\t\t\t\t" << load << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << load << endl;
			cout << "\t\t\t\t\t" << load << "      Back  (<-Backspace)     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			option = getch();
		} while (option != '1' && option != '2' && option != 8);
		string id1, cn;
		if (option == '1')
		{
			system("cls");
			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      |  Search by ID   |     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t      ID  : ";
			cin >> id1;
		}

		if (option == '2')
		{
			system("cls");
			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      |  Search by CNIC |     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t      CNIC : ";
			char p = 0;
			while (p != 13 && length != 13) // ascii code of enter. this will turminate on enter
			{
				if (p >= 48 && p <= 57) // take value only in numeric form
				{
					pin.push_back(p);
					cout << p;
					length++;
					if (length == 5 || length == 12)
						cout << "-";
				}
				p = _getch(); // take value char by char
			}
		}
		cn = pin;
		Double_Pointer_Linked ob;
		if (option != 8)
			ob.Search_Account(id1, cn);
	}

	/////////////////////////////////////////

	int User_Login_Manu()
	{
		int S;
		do
		{
			system("cls");
			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      |   User Account  |     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      [1]   :   Deposit       " << load << endl;
			cout << "\t\t\t\t\t" << load << "      [2]   :   Withdraw      " << load << endl;
			cout << "\t\t\t\t\t" << load << "      [3]   :   Detail        " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "______________________________" << load << endl;
			cout << "\t\t\t\t\t" << load << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << load << endl;
			cout << "\t\t\t\t\t" << load << "      Back  (<-Backspace)     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			S = _getch();
		} while (S != '1' && S != '2' && S != '3' && S != 8);
		return S;
	}
	void Detail()
	{
		Double_Pointer_Linked obj;
		obj.Search_Account(id, "0");
		getch();
	}

	void Withdraw()
	{
		do
		{
			system("cls");
			int take1;
			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      | Deposit  Amount |     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t         Amount  : ";
			cin >> W;
			if (W <= 0)
			{
				cout << "\n\t\t\t\t\t";
				for (int i = 0; i <= 31; i++)
					cout << load;
				cout << "\n";
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t" << load << "  Please Enter Valid Range    " << load << endl;
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t";
				for (int i = 0; i <= 31; i++)
					cout << load;
				cout << "\n";
				getch();
			}

		} while (W <= 0);

		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "       Yes : ('Y' OR 'y')     " << load << endl;
		cout << "\t\t\t\t\t" << load << "        NO : ('N' OR 'n')     " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int j = 0; j <= 31; j++)
			cout << load;
		cout << "\n";

		do
		{
			g = getch();
		} while (g != 'Y' && g != 'y' && g != 'N' && g != 'n');
		system("cls");
		if (g == 'Y' || g == 'y')
		{
			Double_Pointer_Linked Ob;
			Ob.Deposit(id, W);
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t           Slip.";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			Detail();
		}
	}

	void Deposit()
	{
		do
		{

			system("cls");
			int take1;
			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      | Withdraw Amount |     " << load << endl;
			cout << "\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t         Amount  : ";
			cin >> W;
			if (W <= 0)
			{
				cout << "\n\t\t\t\t\t";
				for (int i = 0; i <= 31; i++)
					cout << load;
				cout << "\n";
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t" << load << "  Please Enter Valid Range    " << load << endl;
				cout << "\t\t\t\t\t" << load << "                              " << load << endl;
				cout << "\t\t\t\t\t";
				for (int i = 0; i <= 31; i++)
					cout << load;
				cout << "\n";
				getch();
			}

		} while (W <= 0);

		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t" << load << "       Yes : ('Y' OR 'y')     " << load << endl;
		cout << "\t\t\t\t\t" << load << "        NO : ('N' OR 'n')     " << load << endl;
		cout << "\t\t\t\t\t" << load << "                              " << load << endl;
		cout << "\t\t\t\t\t";
		for (int j = 0; j <= 31; j++)
			cout << load;
		cout << "\n";
		do
		{
			g = getch();
		} while (g != 'Y' && g != 'y' && g != 'N' && g != 'n');
		system("cls");
		if (g == 'Y' || g == 'y')
		{
			Double_Pointer_Linked Ob;
			Ob.Withdraw_Amount(id, W);
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "\t\t\t\t\t           Slip.";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << "\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			Detail();
		}
	}
};

// main prgram
int main()
{
	Bank *a[4];
	Login obj1;
	Man_u obj2;
	Customer obj3;
	User_Account obj4;
	a[0] = &obj1; // creat an object of class bank
	a[1] = &obj2;
	a[2] = &obj3;
	a[3] = &obj4;
	int select2;
	a[0]->group_introduction();
	system("cls");
	string wlm = "WELCOME TO BANKING MANAGEMENT SYSTEM";
	a[0]->starting_line(wlm);
	while (true)
	{
		system("cls");

		bool check;					// used for get true or false value
		check = a[0]->User_login(); // this function will return true or false
		if (check == true)			// if it check==true true then user can enter in software
		{
			int Select;
			wlm = "     THANKS YOU SUCCESSFULY ENTERED ";
			a[0]->starting_line(wlm);
			do
			{
				system("cls");
				Select = a[1]->main_manu();
				system("cls");
				if (Select == '1')
				{
					a[2]->Create_Account();
					_getch();
				}
				else if (Select == '2')
				{
					bool c;
					do
					{
						system("cls");
						c = a[3]->login_user_account();
					} while (c == false);
					if (c == true)
						do
						{
							select2 = a[3]->User_Login_Manu();
							if (select2 == '1')
							{
								a[3]->Withdraw();
								_getch();
							}
							if (select2 == '2')
							{
								a[3]->Deposit();
								_getch();
							}
							if (select2 == '3')
							{
								a[3]->Detail();
								_getch();
							}

						} while (select2 != 8);
					select2 = 0;
				}

				else if (Select == '3')
				{
					a[2]->Display_Accounts();
					_getch();
				}

				else if (Select == '4')
				{
					a[3]->Search_accounts();
					_getch();
				}
				else if (Select == '5') // into Setting portion
				{
					do
					{
						select2 = a[1]->setting();
						if (select2 == '1') // for change user ID
						{
							a[1]->change_user_id();
							_getch();
						}
						else if (select2 == '2') // for change user PIN
						{
							system("cls");
							a[1]->change_user_PIN();
							_getch();
						}
					} while (select2 != 8);
				}
				else if (Select == 27)
				{
					a[1]->logout();
					string wlm = "              Loging Out"; // this strng will on above the starting line
					a[0]->starting_line(wlm);
				}
			} while (Select != 27);
		}
		else // if user enter wrong ID or Password then an error message display
		{	 // if (chaeck == false) then
			system("cls");
			cout << "\n\n\n\n\n\n";
			cout << "\t\t\t\t\t";
			for (int i = 0; i <= 31; i++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
			cout << "\t\t\t\t\t" << load << "                              " << load << endl;
			cout << "\t\t\t\t\t";
			for (int j = 0; j <= 31; j++)
				cout << load;
			cout << "\n";
			cout << "\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "\t\t\t\t\tPlease Enter Correct ID and PIN\n";
			cout << "\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			_getch();
		}
	} // while true end bracket
}
