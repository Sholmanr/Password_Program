#include <iostream>
#include <string>
using namespace std;

#ifndef Users_H
#define Users_H

class User
{
public:
	User();
	User(string user_name, string use_password, int account_number);
	~User();
	void Set_Name(User user, string new_name);
	string getUsername();
	string getPassword();
	int getAccountNumber();
};

class node
{
public:
	User user;
	node* next; 
	node(User currentUser);
};


#endif // !1
