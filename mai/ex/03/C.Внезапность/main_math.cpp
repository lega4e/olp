#include <cmath>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	long long n, a, b;

	cin >> n >> a >> b;
	long long time = min(a, b);
	--n;

	long long const m1 = (b*n) / (a+b);
	long long const m2 = (long long)ceil( (double)b*n/(a+b) ); 

	time += min(
		max( m1*a, (n-m1)*b ),
		max( m2*a, (n-m2)*b )
	);
	printf("%lli\n", time);





	return 0;
}





// end
