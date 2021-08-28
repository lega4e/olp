#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	int *arr;
	int x;


	// input
	cin >> n;
	arr = new int[n];
	for(auto *b = arr, *e = arr+n; b != e; ++b)
		cin >> *b;
	cin >> x;


	// search
	int l = -1, r = n, m;
	while(r-l > 1)
	{
		m = (l+r)/2;
		if(!(arr[m] < x))
			r = m;
		else
			l = m;
	}


	// output
	cout << l << ' ' << r << endl;


	return 0;
}





// end
