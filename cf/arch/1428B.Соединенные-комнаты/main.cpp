#include <iostream>
#include <vector>





// types
typedef long long llong;





// objects
int yes, left, right;
char ch[2];

bool letleft;
bool letright;





// functions
template<typename T>
T next()
{
	T t;
	std::cin >> t;
	return t;
}

auto nxti  = next<int>;
auto nxtll = next<llong>;
auto nxtc  = next<char>;

void check()
{
	if(ch[0] == '>' or ch[1] == '>')
		letleft = false;

	if(ch[0] == '<' or ch[1] == '<')
		letright = false;

	if(ch[0] == '-' or ch[1] == '-')
	{
		++yes;
		return;
	}

	if(ch[0] == '>' and ch[1] == '>')
	{
		++right;
		return;
	}

	if(ch[0] == '<' and ch[1] == '<')
	{
		++left;
		return;
	}

	return;
}





// main
int main( int argc, char *argv[] )
{
	int testc = nxti(), n;
	int result;
	char fch;


	for(int test = 0; test < testc; ++test)
	{
		yes = left = right = 0;
		letleft = letright = true;

		n = nxti();

		fch = nxtc();
		ch[0] = fch;

		for(int i = 1; i < n; ++i)
		{
			ch[1] = nxtc();
			check();
			ch[0] = ch[1];
		}

		ch[1] = fch;
		check();

		result = yes + (letleft ? left : 0) + (letright ? right : 0);
		printf("%i\n", result);
	}



	return 0;
}





// end
