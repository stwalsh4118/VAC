#include <iostream>
#include <string>
using namespace std;

int main() {
	int totalBalance = 10000;
	bool exit = false;
	string usernames[1000];
	string passwords[1000];
	int accountBalance[1000] = { 0 };
	int accountNumber;
	string username;
	string password;
	int userInput;
	bool loggedIn = false;


	cout << "Welcome to VAC Bank" << endl << endl;
	while (!exit) {
		if (!loggedIn) {
			cout << "Register?(0) or Login?(1) or Exit(2)" << endl;
			cin >> userInput;
			if (userInput == 1) {
				cout << "Login" << endl << "Username: ";
				cin >> username;
				cout << endl << "Password: ";
				cin >> password;
				int i = 0;
				while ((username != usernames[i]) && (i < 1000)) {
					i++;
				}
				if (i >= 1000) {
					loggedIn = false;
					cout << "Log In Failed" << endl;
				}
				else if (password == passwords[i]) {
					loggedIn = true;
					cout << "Logged In Successfully" << endl;
					accountNumber = i;
				}
				else {
					cout << "Log In Failed" << endl;
				}
			}
			else if(userInput==0) {
				cout << "Enter new username(case sensitive): ";
				cin >> username;
				cout << endl << "Enter new password(case sensitive): ";
				cin >> password;
				int i = 0;
				while (usernames[i] != "") {
					i++;
				}
				usernames[i] = username;
				passwords[i] = password;
			}
			else {
				exit = true;
			}
		}
		else {
			cout << "Accout Balance: " << accountBalance[accountNumber] << endl;
			cout << "ATM Balance: " << totalBalance << endl;
			cout << "Withdraw?(0) or Deposit?(1) or Logout?(2)" << endl;
			cin >> userInput;
			if (userInput == 0) {
				cout << "How much do you want to Withdraw?" << endl;
				cin >> userInput;
				if (userInput > accountBalance[accountNumber])
					cout << "You do not have enough money in your account to withdraw this much." << endl;
				else if (userInput > totalBalance)
					cout << "There is not enough money in this ATM to withdraw this much." << endl;
				else {
					cout << "Withdraw successful." << endl;
					totalBalance -= userInput;
					accountBalance[accountNumber] -= userInput;
				}

			}
			else if (userInput == 1) {
				cout << "How much would you like to deposit?" << endl;
				cin >> userInput;
				cout << "Depositing " << userInput << " dollars." << endl;
				accountBalance[accountNumber] += userInput;
				totalBalance += userInput;
			}
			else {
				loggedIn = false;
			}
		}
	}
	return 0;
}