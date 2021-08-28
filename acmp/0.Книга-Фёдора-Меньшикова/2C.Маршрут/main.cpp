#include <cstring>
#include <iostream>
#include <fstream>
#include <list>


using namespace std;





// structs
struct RouteNode
{
	int x, y;
	int counter;
	RouteNode *prev;

	void free()
	{
		if(prev && !--prev->counter)
		{
			prev->free();
			delete prev;
		}
		return;
	}
};

struct LifeRoute
{
	RouteNode *r;
	int waittime;
};

struct Field
{
	int n;
	char *d;

	inline char &at(int x, int y)
	{
		return d[ y*n + x ];
	}
};




// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions



RouteNode *find_route(Field f)
{
	// no k > 0 because we not go up
#define is_valid(k) ( k < f.n )

	// check-field
	Field checkf{ f.n, new char[f.n*f.n] };
	memset( checkf.d, 0, sizeof(*checkf.d)*checkf.n*checkf.n );

	// list of life routs
	list< LifeRoute > liferouts;
	liferouts.push_back(
		LifeRoute{ new RouteNode{0, 0, 0, nullptr}, 0 }
	);

	// possible ways
	constexpr static char const pways[2][2] = {
		{ 1, 0 },
		{ 0, 1 }
	};
	
	// buffers
	RouteNode *cr;
	int bx, by;
	while(!liferouts.empty())
	{
		for(auto b = liferouts.begin(), e = liferouts.end(); b != e;)
		{
			if(b->waittime)
			{
				--b->waittime;
				++b;
				continue;
			}
			cr = b->r;
			for(auto const &i : pways)
			{
				bx = cr->x+i[0];
				by = cr->y+i[1];

				if(
					is_valid( bx ) &&
					is_valid( by ) &&
					!checkf.at( bx, by )
				)
				{
					checkf.at( bx, by ) = 1;
					++cr->counter;
					if(bx == f.n-1 && by == f.n-1)
					{
						liferouts.erase(b);
						cr = new RouteNode{ bx, by, 0, cr};
						goto find_result_label;
					}
					liferouts.push_front(
						LifeRoute{ new RouteNode{ bx, by, 0, cr }, (int)f.at(bx, by) - 0x30 } // time!!!
					);
				}
			}
			if( !cr->counter )
			{
				cr->free();
				delete cr;
			}
			liferouts.erase( b++ );
		}
	}

	return nullptr;

find_result_label:

	for(auto i : liferouts)
	{
		i.r->free();
	}
	return cr;
}





// main
int main( int argc, char *argv[] )
{
	// read input
	Field f;
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> f.n;
		f.d = new char[f.n*f.n];
		for(auto *b = f.d, *e = f.d+f.n*f.n; b != e;)
		{
			fin.get(*b);
			if( *b != '\n' && *b != ' ' && *b != '\t' )
				++b;
		}
	}

	// write
	RouteNode *route = find_route(f);
		// create field
	memset(f.d, '.', sizeof(*f.d)*f.n*f.n);

	do
	{
		f.at( route->x, route->y ) = '#';
		route = route->prev;
	}
	while(route);

		// print field
	{
		ofstream fout(OUTPUT_FILE_NAME);
		for(int y = 0; y < f.n; ++y)
		{
			for(int x = 0; x < f.n; ++x)
			{
				fout << f.at(x, y);
			}
			fout << endl;
		}
	}

	return 0;
}





// end
