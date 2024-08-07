//#include "MergeSort.h"
//#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 


int numberOfAccounts = 0;

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

node* sortedMerge(node* first, node* second)
{
	node* result = NULL;

	/* Base cases */
	if (first == NULL)
	{
		return (second);
	}
	else if (second == NULL)
	{
		return (first);
	}



	/* Pick either a or b, and recur */
	if (first->user.getUsername().compare(second->user.getUsername()) < 0)
	{
		result = first;
		result->next = sortedMerge(first->next, second);
	}
	else
	{
		result = second;
		result->next = sortedMerge(first, second->next);
	}

	return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into first and second halves, and return the two lists using the reference parameters.
   If the length is odd, the extra node should go in the first list. Uses the fast/slow pointer strategy. */

void splitList(node* source, node** firstRef, node** secondRef)
{
	node* slow = source;
	node* fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL)
	{
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two at that point. */
	*firstRef = source;
	*secondRef = slow->next;
	slow->next = NULL;
}

/* Sorts the linked list by changing next pointers (not data) */
void mergeSort(node** headRef)
{
	node* head = *headRef;
	node* first;
	node* second;

	/* Base case -- Length 0 ior 1 */
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}

	/* Split head into 'first' and 'second' sublists */
	splitList(head, &first, &second);

	mergeSort(&first);
	mergeSort(&second);

	/* answer = merge the two sorted lists together */
	*headRef = sortedMerge(first, second);
}

/* Function to print nodes in a given linked list */
void printList(node* node)
{
	while (node != NULL)
	{
		cout << node->user.getUsername() << "/n";
		node = node->next;
	}
}

/* Function to insert a node at the beginning of the linked list */
void push(node** head_ref, User user)
{
	/* Allocate node */
	node* new_node = new node(user);

	/* Link the old list of the new node */
	new_node->next = (*head_ref);

	/* Move the head to point to the new node */
	(*head_ref) = new_node;

}


void addUserToList(node* head, User user)
{
	node* traverse = head;
	node* n = new node(user);

	if (head == NULL)
	{
		head = n;
	}
	else
	{
		n->next = head;
		head = n;
	}
//FIXME mergeSort(head); 

}

// Sets the user's name and password
User createUser(int accountNumber, string username, string password, node *&head)
{
	User* user = new User(username, password, accountNumber);
	addUserToList(head, *user);
	return *user;
}

// Creates a file name "Users" if one doesn't already exist and adds users to it
void createFile(node *currentUser)
{
	ofstream myFile;
	myFile.open("Users", ios::trunc);
	myFile << numberOfAccounts;

	while (currentUser->next != NULL)
	{
		myFile << "\n";
		myFile <<  currentUser->user.getUsername();
		myFile << "\n";
		myFile << currentUser->user.getPassword();
		myFile << "\n"; 
		myFile << currentUser->user.getAccountNumber();

		currentUser = currentUser->next; 
	}

	myFile << "\n";
	myFile << currentUser->user.getUsername();
	myFile << "\n";
	myFile << currentUser->user.getPassword();
	myFile << "\n";
	myFile << currentUser->user.getAccountNumber();
	myFile << "\n";

	myFile.close();
}

// Checks if the username and password are correct, un: username, p: password 
bool infoCheck(node *traverse, string un_input, string p_input)
{	
	bool found = false, correct = true; 
	const int len = p_input.length() + 1;
	char* input_pass = new char [len];
	strcpy(input_pass, p_input.c_str());

	while (traverse != nullptr && found == false)
	{
		if (un_input.compare(traverse->user.getUsername()) == 0)
		{
			found = true;
		}
		else
		{
			traverse = traverse->next; 
		}
		
	}

	const int len2 = traverse->user.getPassword().length() + 1;
	char* stored_pass = new char[len2];
	strcpy(stored_pass, traverse->user.getPassword().c_str());

	for (int i = 0; i < len - 1; i++)
	{
		if (input_pass[i] == stored_pass[i])
		{
			continue;
		}
		else
		{
			correct = false;
			break;
		}
	}
	
	delete[] input_pass; 
	delete[] stored_pass;
	

	return correct; 
}




void getUsers()
{
	User user;
	string name, password; 
	int accountNumber; 

	ifstream inputFile("Users.txt");

	if (!inputFile.is_open())
	{
		return; 
	}


	for (int i = 0; i < 3; i++)
	{
		getline(inputFile, name);
		getline(inputFile, password);
		inputFile >> accountNumber; 
	}

	node* n = new node(user);

}

void readFile(node *&head)
{
	string username, password;
	int accountNumber;
	ifstream usersFile;

	usersFile.open("Users", ios::out);

	if (usersFile.is_open())
	{
		usersFile >> numberOfAccounts;
		usersFile.ignore();
		for (int i = 0; i < numberOfAccounts; i++)
		{
			getline(usersFile, username);
			getline(usersFile, password);
			usersFile >> accountNumber;
			usersFile.ignore();
			createUser(accountNumber, username, password, head);

		}
	}
}

int main() 
{
	int choice = 0;
	node *head = NULL; 
	bool proceed = true, valid = false;
	string answer = " ";
	string i_username = "", i_password = ""; 

	readFile(head);

	while (proceed == true)
	{
		
		// Displays the choices and gets the choice from the user
		cout << "What would you like to do?";
		cout << "\n1. Create a new account";
		cout << "\n2. Sign in\n"; 
		cin >> choice; 
		
		
		
		// Determines what to do depending on what the user input 
		switch (choice)
		{
		case 1: 
			numberOfAccounts += 1; 
			cout << "Enter Username: ";
			cin >> i_username;
			cout << "Enter Password: ";
			cin >> i_password;
			createUser(numberOfAccounts, i_username, i_password, head);
			valid = false;
			break;

		case 2:
			cout << "Enter Username: ";
			cin >> i_username;
			cout << "Enter Password: ";
			cin >> i_password; 
			infoCheck(head, i_username, i_password);
			valid = false;
			break; 
		
		default:
			cout << "Please enter a valid response.\n";
			valid = true;
			cin.clear();
			cin.ignore(100000, '\n');
		}

		// Determines what the user wants to do after a transaction and makes sure the input is valid 
		while (valid == false)
		{
			cout << "\nWould you like to perform another action?";
			cout << "\ny";
			cout << "\nn\n";
			cin >> answer;

			if (answer.compare("y") == 0)
			{
				proceed = true; 
				valid = true; 
				break; 
			}
			else if (answer.compare("n") == 0)
			{
				proceed = false;
				valid = true; 
				break; 
			}

			else
			{
				cout << "Please enter a valid response.\n";
			}
		}

		
		
	}

	cout << "Thank you for your transaction!"; 
	createFile(head);
	
	return 0; 
}

/*
* THINGS STILL NEEDED:
* Need to check if there is someone with that username already 
* Need to make sure there are no special characters in the username
* When checking password need to make sure that if the 1st password is shorter but containsthe correct characters it doesn't return "correct = true"
* Merge sort header broken
* Bugs:
* - If you input two things when determining what to do it will just skip the input of the username 
* 
*/