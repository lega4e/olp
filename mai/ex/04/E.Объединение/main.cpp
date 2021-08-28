#include <iostream>
#include <set>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	multiset<long long> set;
	
	
	
	// input
	scanf("%i", &n);

	long long input;
	for(int i = 0; i < n; ++i)
	{
		scanf("%lli", &input);
		set.insert(input);
	}

	long long con;
	for(int i = 0; i < n-1; ++i)
	{

		printf("%lli %lli\n", *set.begin(), *++set.begin());
		con = *set.begin() + *++set.begin();
		set.erase(set.begin());
		set.erase(set.begin());
		set.insert(con);
	}
	



	return 0;
}





// end
