#include "User.h"
#include <iostream>
#include <string>
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

	// Returns user's username
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

class node
{
public:
	User user;
	node* next;

	node(User currentUser)
	{
		user = currentUser;
		next = NULL;
	}

};