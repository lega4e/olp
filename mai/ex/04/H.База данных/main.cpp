#include <iostream>
#include <map>


using namespace std;





// types
struct UserData
{
	string password;
	bool in = false;
};





// main
int main( int argc, char *argv[] )
{
	map<string, UserData> base;
	string command, name, password;
	
	
	
	// proccess
	auto it = base.begin();
	while(cin >> command)
	{
		if(command == "register")
		{
			cin >> name >> password;
			it = base.find(name);
			if(it != base.end())
				cout << "login already in use\n";
			else
				cout << "account created\n",
				base[name] = UserData{password, false};
		}
		else if(command == "login")
		{
			cin >> name >> password;
			it = base.find(name);
			if(it == base.end() || it->second.password != password)
				cout << "wrong account info\n";
			else
			{
				if(it->second.in)
					cout << "already logged in\n";
				else
					cout << "logged in\n",
					it->second.in = true;
			}
		}
		else if(command == "logout")
		{
			cin >> name;
			it = base.find(name);
			if(it == base.end() || !it->second.in)
				cout << "incorrect operation\n";
			else
				cout << "logged out\n",
				it->second.in = false;
		}
		else
			throw 1;

	}



	return 0;
}





// end
