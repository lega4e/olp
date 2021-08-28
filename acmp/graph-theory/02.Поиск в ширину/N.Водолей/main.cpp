#include <iostream>
#include <functional>
#include <fstream>
#include <set>
#include <vector>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	struct Stage {
		int a = 0, b = 0;
	};

	struct Node
	{
		Stage s;
		Stage prev;
		string act;

		bool operator<(Node const &rhs) const
		{
			return s.a != rhs.s.a ?
				s.a < rhs.s.a :
				s.b < rhs.s.b;
		}
	};

	struct Function
	{
		function<Stage(Stage)> f;
		string s;
	};

	int a, b, n;
	ifstream(INPUT_FILE_NAME) >> a >> b >> n;
	Function const funs[] = {
		{
			[=](Stage s)->Stage {
				return { a, s.b };
			},
			">A"
		},
		{
			[=](Stage s)->Stage {
				return { s.a, b };
			},
			">B"
		},
		{
			[=](Stage s)->Stage {
				return { 0, s.b };
			},
			"A>"
		},
		{
			[=](Stage s)->Stage {
				return { s.a, 0 };
			},
			"B>"
		},
		{
			[=](Stage s)->Stage {
				return b - s.b >= s.a ?
					Stage { 0, s.b+s.a } :
					Stage { s.a - (b-s.b), b };
			},
			"A>B"
		},
		{
			[=](Stage s)->Stage {
				return a - s.a >= s.b ?
					Stage { s.a+s.b, 0 } :
					Stage { a, s.b - (a-s.a) };
			},
			"B>A"
		}
	};

	
	
	// solve
	set<Node> nodes, toinsert;
	vector<Stage> front, next;

	front.push_back( {0, 0} );
	nodes.insert( { {0, 0}, {-1, -1}, "" } );
	Node node;
	bool find = false;
	while(!front.empty())
	{
		for(auto b = front.begin(), e = front.end(); b != e; ++b)
		{
			for(auto const &fun : funs)
			{
				node = { fun.f(*b), *b, fun.s };
				if( node.s.a == n || node.s.b == n)
				{
					find = true;
					goto break_label;
				}
				if(auto it = nodes.insert(node); it.second)
				{
					next.push_back(node.s);
				}
			}
		}

		swap(front, next);
		next.clear();
	}
break_label:



	// output
	if(!find)
		ofstream(OUTPUT_FILE_NAME) << "Impossible" << endl;
	else
	{
		vector<string> stack;
		while(!node.act.empty())
		{
			stack.push_back(node.act);
			node.s = node.prev;
			node = *nodes.find(node);
		}

		ofstream fout(OUTPUT_FILE_NAME);
		for(auto b = stack.rbegin(), e = stack.rend(); b != e; ++b)
			fout << *b << "\n";
		fout << flush;
	}





	return 0;
}





// end
