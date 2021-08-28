#include <iostream>
#include <random>

#include <quix/Field.hpp>


using namespace std;
using namespace quix;





// objects
Field<char> f, sf;

constexpr PointI const OFFSET[8] = {
	{ 1, 2 },
	{ 1, -2 },
	{ -1, 2 },
	{ -1, -2 },
	{ 2, 1 },
	{ 2, -1 },
	{ -2, 1 },
	{ -2, -1 }
};





// functions
int is(PointI a, PointI b)
{
	f.zeroize();
	sf.zeroize();

	if(a == b)
		return 0;
	f[a] = 'r';
	f[b] = 'g';

	// solve
	int count = 0;
	while(true)
	{
		 ++count;
		 if(count == 1000)
		 	return -1;
		 
		 for(PointI p{0, 0}, cur; p.y < 8; ++p.y)
		 for(p.x = 0; p.x < 8; ++p.x)
		 {
		 	if(!f[p])
		 		continue;
		 	
		 	for(auto off : OFFSET)
		 	{
		 		cur = p+off;
		 		if(!sf.isValid(cur))
		 			continue;
		 		
		 		if(sf[cur] && sf[cur] != f[p])
					return count;
		 		
		 		sf[cur] = f[p];
		 	}
		 }
		 
		 swap(f, sf);
		 sf.clear();
	}
}





// main
int main( int argc, char *argv[] )
{
	default_random_engine dre;
	uniform_int_distribution<int> dis(0, 7);

	f.init(8, 8);
	sf.init(8, 8);

	PointI a, b;
	int res;
	for(int i = 0; i < 1000; ++i)
	{
		a.x = dis(dre);
		a.y = dis(dre);
		b.x = dis(dre);
		b.y = dis(dre);

		res = is(a, b);
		cout << a << " & " << b << ": " << res << '\n';
	}
	 
	 
	 
	 
	return 0;
}





// end
