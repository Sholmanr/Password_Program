#include <iostream>
using namespace std; 
#pragma once
#ifndef MergeSort
#define MergeSort
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

	node(User currentUser)
	{
		user = currentUser;
		next = NULL;
	}

};
void mergeSort(node**);
void printList(node*);
node* sortedMerge(node*, node*);
void splitList(node*, node**, node**);
void push(node**, int);

#endif // !1
