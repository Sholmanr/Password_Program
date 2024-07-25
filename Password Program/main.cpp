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
void createFile(node *currentUser)
{
	fstream myFile;
	myFile.open("Users", ios::app);
	myFile << numberOfAccounts;

	while (currentUser->next != NULL)
	{
		myFile <<  currentUser->user.getUsername();
		myFile << "\n";
		myFile << currentUser->user.getPassword();
		myFile << "\n"; 
		myFile << currentUser->user.getAccountNumber();
		myFile << "\n";
	}
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


void addUserToList(node *&head)
{
	User user;
	numberOfAccounts += 1;

	user = createUser(numberOfAccounts);

	node *n = new node(user);
	if (head == NULL)
	{
		head = n; 
	}
	else
	{
		n->next = head;
		head = n; 
		
	}
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


int main() 
{
	int choice = 0;
	node *head = NULL; 
	bool proceed = true, valid = false;
	char answer = ' ';
	string i_username = "", i_password = ""; 

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
			addUserToList(head);
			break;

		case 2:
			cout << "Enter Username: ";
			cin >> i_username;
			cout << "Enter Password: ";
			cin >> i_password; 
			infoCheck(head, i_username, i_password);
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

			if (answer == 'y')
			{
				proceed = true; 
				valid = true; 
				break; 
			}
			else if (answer == 'n')
			{
				proceed = false;
				valid = true; 
				break; 
			}

			else
			{
				cout << "Please enter a valid response.";
				valid = false; 
				break;
			}
		}

		
		
	}

	cout << "Thank you for your transaction!"; 
	//createFile();
	
	return 0; 
}

/*
* THINGS STILL NEEDED:
* Need to check if there is someone with that username already 
* Need to make sure there are no special characters in the username
* When checking password need to make sure that if the 1st password is shorter but containsthe correct characters it doesn't return "correct = true"
*/