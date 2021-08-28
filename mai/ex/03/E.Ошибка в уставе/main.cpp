#include <iostream>
#include <stack>


using namespace std;





// functions
inline bool is_pair(char lhs, char rhs)
{
	return
		( lhs == '(' && rhs == ')' ) ||
		( lhs == '{' && rhs == '}' ) ||
		( lhs == '[' && rhs == ']' );
}

inline bool is_open(char ch)
{
	return
		ch == '(' ||
		ch == '{' ||
		ch == '[';
}





// main
int main( int argc, char *argv[] )
{
	int n;
	stack<char> s;


	cin >> n;
	char ch;
	for(int i = 0; i < n; ++i)
	{
		cin >> ch;

		if(s.empty())
		{
			if(!is_open(ch))
				goto nein_label;

			s.push(ch);
			continue;
		}

		if(is_pair(s.top(), ch))
		{
			s.pop();
			continue;
		}

		if(!is_open(ch))
			goto nein_label;

		s.push(ch);
	}

	if(!s.empty())
		goto nein_label;


	// output
	cout << "Ja" << endl;
	return 0;


nein_label:
	cout << "Nein" << endl;
	return 0;
}





// end
