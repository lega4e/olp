#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	int n, a, b;
	llong time;



	// first
	cin >> n >> a >> b;
	time = min(a, b);
	--n;
	
	
	
	// second
	{
		llong l = -1, r = n*min(a, b)+1, m, val;
		while(r-l > 1)
		{
			m = (l+r)/2;
			val = m/a + m/b;
			if(n <= val)
				r = m;
			else
				l = m;
		}

		time += r;
	}
	
	
	
	// output
	cout << time << endl;



	return 0;
}





// end
