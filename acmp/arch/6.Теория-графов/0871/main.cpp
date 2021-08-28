#include <iostream>
#include <fstream>
#include <set>


using namespace std;





// structs
struct Link
{
	int f, s;
};



inline bool operator==(Link const &lhs, Link const &rhs)
{
	return lhs.f == rhs.f && lhs.s == rhs.s;
}

inline bool operator<(Link const &lhs, Link const &rhs) 
{
	return lhs.f < rhs.f ? true : (
		lhs.f == rhs.f ? lhs.s < rhs.s : false
	);
}





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	set<Link> links;
	int num;
	
	
	
	// input
	{
		int linkcount;

		ifstream fin(INPUT_FILE_NAME);
		fin >> num >> linkcount;

		Link link;
		for(int i = 0; i < linkcount; ++i)
		{
			fin >> link.f >> link.s;
			if(link.f > link.s)
				swap(link.f, link.s);
			links.insert(link);
		}
	}
	
	
	
	// output
	for(auto b = links.begin(), e = links.end(); b != e; ++b)
	{
		cout << b->f << " " << b->s << endl;
	}

	

	return 0;
}





// end
