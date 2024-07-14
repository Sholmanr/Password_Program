#include <iostream>
using namespace std; 


class User
{
private:
	string username, password; 
public: 
	User(string user_name, string use_password)
	{
		username = user_name;
		password = use_password;
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
	
};

User createUser()
{
	string name, password;

	cout << "Username: ";
	cin >> name;
	cout << "Password: ";
	cin >> password; 

	User* user = new User(name, password);

	return *user;
}

int main() 
{
	User user1 = createUser();
	cout << user1.getUsername();
	cout << user1.getPassword();

	return 0; 
}