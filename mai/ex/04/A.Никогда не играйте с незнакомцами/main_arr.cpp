#include <algorithm>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	int *arr;
	
	
	
	// input
	scanf("%i", &n);
	arr = new int[n];
	for(auto *b = arr, *e = arr+n; b != e; ++b)
		scanf("%i", b);
	
	
	
	// solve
	sort(arr, arr+n);
	int first = arr[0];
	for(int i = 1; i < n; ++i)
		if(arr[i] != first+i)
			goto fail_label;



	// output
	printf("Deck looks good\n");
	return 0;


fail_label:
	printf("Scammed\n");
	return 0;
}





// end
