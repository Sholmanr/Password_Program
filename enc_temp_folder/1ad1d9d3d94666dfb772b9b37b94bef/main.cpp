#include <iostream>
#include <fstream>
using namespace std; 


class User
{
private:
	string username, password;
	int accountNumber; 
public: 
	// Default constructor for User class 
	User()
	{
		username = "Default";
		password = "1234";
		accountNumber = 0000000;
	}

	// Constructor for User class 
	User(string user_name, string use_password, int account_number)
	{
		username = user_name;
		password = use_password;
		accountNumber = account_number;
		
	}

	~User()
	{} 

	void Set_Name(User user, string new_name)
	{
		user.username = new_name; 
	}

	// REturns user's username
	string getUsername()
	{
		return username; 
	}

	// Returns user's password
	string getPassword()
	{
		return password; 
	}

	int getAccountNumber()
	{
		return accountNumber; 
	}
	
};



// Sets the user's name and password
User createUser(int accountNumber)
{
	string name, password;

	cout << "Username: ";
	cin >> name;
	cout << "Password: ";
	cin >> password; 

	User* user = new User(name, password, accountNumber);

	return *user;
}

// Creates a file name "Users" if one doesn't already exist and adds users to it
void createFile(User user)
{
	fstream myFile;
	myFile.open("Users", ios::app);
	myFile <<  user.getUsername();
	myFile << user.getPassword();
	myFile << user.getAccountNumber();
	myFile.close();
}

bool infoCheck()
{
	return true; 
}

int main() 
{
	int numberOfAccounts = 0, choice = 0;
	bool proceed = true, valid = false;
	char answer = ' ';
	User user;  

	while (proceed == true)
	{
		// Displays the choices and gets the choice from the user
		cout << "What would you like to do?";
		cout << "\n1. Create a new account";
		cout << "\n2. Sign in"; 
		cin >> choice; 
		
		// Determines what to do depending on what the user input 
		switch (choice)
		{
		case 1:
			numberOfAccounts += 1;
		    user = createUser(numberOfAccounts);
			createFile(user);
			break;

		case 2:
			infoCheck();
			break; 
		}
		valid = false; 
		// Determines what the user wants to do after a transaction and makes sure the input is valid 
		while (valid == false)
		{
			cout << "\nWould you like to perform another action?";
			cout << "\ny";
			cout << "\nn\n";
			cin >> answer;

			switch (answer)
			{
			case 'y':
				proceed = true; 
				valid = true; 
				break; 
		
			case 'n':
				proceed = false;
				valid = true; 
				break; 

			default: 
				cout << "Please enter a valid response.";
				valid = false; 
				break;
			}

		}
		
	}

	cout << "Thank you for your transaction!"; 
	
	return 0; 
}