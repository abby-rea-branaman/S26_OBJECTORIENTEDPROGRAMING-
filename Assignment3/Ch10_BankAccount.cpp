#include <iostream>
#include <string>
using namespace std;

// BankAccount class
class BankAccount
{
	private:
		string accountHolderName;
		int accountNumber;
		double balance;
	
	public:
		BankAccount(string name, int number, double initialBalance)
		{
			accountHolderName = name;
			accountNumber = number;
			balance = initialBalance;
		}
		
		//Function to deposit money
		void deposit(double amount)
		{
			balance += amount; // Add the 'amount' to the current balance
			cout << "Deposit successful. New balance: " << balance << endl;
		}
		
		//Function to withdraw money
		void withdraw(double amount)
		{
			if (amount < balance)
			{
				balance -= amount; 
				cout << "Withdrawal successful. New balance: " << balance << endl;
			}
			else
			{
				cout << "Error: Insufficient funds. Current balance: " << balance << endl;
			}
		}
		
		//Function to display the account balance
		void displayBalance()
		{
			cout << "Current balance: " << balance << endl;
		}
};

int main()
{
	// Variables to hold user input
	string name;
	int number;
	double initialBalance;

	int choice;
	double amount = 0.0;

	// Welcome message and account setup
	cout << "Welcome to Assembly Bank!" << endl;
	cout << endl; 
	cout << "Enter account holder name: ";
	getline(cin, name);
	cout << "Enter account number: ";
	cin >> number;
	cout << "Enter initial balance: ";
	cin >> initialBalance;

	// Create a BankAccount object with the provided details
	BankAccount myAccount(name, number, initialBalance);

	// This is the main menu loop that allows the user to perform multiple operations until they choose to exit
	do
	{
		cout << "\nMenu:" << endl;
		cout << "1. Deposit" << endl;
		cout << "2. Withdraw" << endl;
		cout << "3. Display Balance" << endl;
		cout << "4. Exit" << endl;
		
		cout << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter amount to deposit: ";
			cin >> amount;
			myAccount.deposit(amount);
		}
		else if (choice == 2)
		{
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			myAccount.withdraw(amount);
		}
		else if (choice == 3)
		{
			myAccount.displayBalance();
		}
		else if (choice == 4)
		{
			cout << "Exiting the program. Goodbye!" << endl;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 4);
	// Once they choose an option equal to 4, the loop will terminate and the program will end.

	return 0;
}
