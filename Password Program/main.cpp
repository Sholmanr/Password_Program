#include <iostream>
#include <fstream>
using namespace std; 


class User
{
private:
	string username, password;
	int accountNumber; 
public: 
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

int main() 
{
	int numberOfAccounts = 0, choice = 0;
	bool proceed = false;


	if (proceed == false)
	{
		cout << "What would you like to do?";
		cin >> choice; 
	}

	numberOfAccounts += 1; 
	User user1 = createUser(numberOfAccounts);
	createFile(user1);
	return 0; 
}