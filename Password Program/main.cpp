#include <iostream>
using namespace std; 


class User
{
private:
	string name; 
public: 
	User(string user_name)
	{
		name = user_name;
	}

	~User()
	{} 

	void Set_Name(User user, string new_name)
	{
		user.name = new_name; 
	}

	string Get_name()
	{
		return name; 
	}
	
};

int main() 
{
	string input; 
	cout << "WHat is your name?"; 
	cin >> input; 
	User *user1 = new User("Simjae");
	cout << user1->Get_name();
	return 0; 
}