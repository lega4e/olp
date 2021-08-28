#include <algorithm>
#include <iostream>
     
     
using namespace std;




     
// main
int main( int argc, char *argv[] )
{
	struct Command
	{
		string name;
		int exs = 0, penalty = 0;
	};

	long long n;
	Command *coms;



	// input
	cin >> n;
	coms = new Command[n];
	for(auto *b = coms, *e = coms+n; b != e; ++b)
		cin >> b->name >> b->exs >> b->penalty;



	// sort
	sort(
		coms, coms+n,
		[](Command const &lhs, Command const &rhs)->bool {
			if(lhs.exs != rhs.exs)
				return lhs.exs > rhs.exs;
			if(lhs.penalty != rhs.penalty)
				return lhs.penalty < rhs.penalty;
			return lhs.name > rhs.name;
		}
	);



	// output
	for(auto *b = coms, *e = coms+n; b != e; ++b)
		cout << b->name << '\n';
	cout << flush;



	return 0;
}





// end
