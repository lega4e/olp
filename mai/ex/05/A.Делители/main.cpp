#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	llong n;
	cin >> n;
	
	
	
	// solve
	llong count = 1;
	for(llong i = 2; i*i <= n; ++i)
	{
		if(n % i == 0)
		{
			if(i*i == n)
				++count;
			else
				count += 2;
		}
	}
	if(n != 1)
		++count; // На само себя
	
	
	
	// output
	cout << count << endl;
	



	return 0;
}





// end
