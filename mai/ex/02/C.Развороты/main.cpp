#include <algorithm>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	int *arr;

	cin >> n;
	arr = new int[n];

	for(auto *b = arr, *e = arr+n; b != e; ++b)
		scanf("%i", b);

	int a, b;
	while(cin >> a >> b && a != 0 && b != 0)
		reverse(arr+(a-1), arr+b);

	for(auto *b = arr, *e = arr+n; b != e; ++b)
		printf("%i ", *b);
	printf("\n");


	return 0;
}





// end
