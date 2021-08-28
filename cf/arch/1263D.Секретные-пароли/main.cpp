#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// functions
template<typename T>
T next()
{
	T t;
	cin >> t;
	return t;
}

auto nxti = next<int>;
auto nxtll = next<llong>;





// main
int main( int argc, char *argv[] )
{
	int chs[26] = { 0 };
	int gc = 0, cc, recolored = 0;

	auto recolor = [&](int from, int to)->void {
		for(int &ch : chs)
		{
			if(ch == from)
				ch = to;
		}
		return;
	};

	string inp;
	int n = nxti();
	for(int i = 0; i < n; ++i)
	{
		inp = next<string>();

		for(auto b = inp.begin(), e = inp.end(); b != e; ++b)
		{
			if( chs[*b-'a'] )
			{
				cc = chs[*b-'a'];
				goto join_label;
			}
		}

		++gc;
		for(auto b = inp.begin(), e = inp.end(); b != e; ++b)
			chs[*b-'a'] = gc;
		continue;

	join_label:
		for(auto b = inp.begin(), e = inp.end(); b != e; ++b)
		{
			if(!chs[*b-'a'])
				chs[*b-'a'] = cc;
			else if(chs[*b-'a'] != cc)
				recolor(chs[*b-'a'], cc),
				++recolored;
		}
	}

	printf("%i\n", gc - recolored);


	return 0;
}





// end
