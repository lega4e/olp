

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
	long long count = 0;
	int kbound = n;
	for(int i = n-3, j = n-2;;)
	{
		for(int k = j+1; k < kbound; ++k)
		{
			printf("%i %i %i : %i %i %i\n",
				i, j, k, arr[i], arr[j], arr[k]
			);
			if(arr[i]+arr[j] > arr[k])
				++count, printf("!");
			else
			{
				kbound = k;
				break;
			}
		}
		if(i && (j-1 == i || arr[i-1]+arr[j] <= arr[i]+arr[j-1]))
			--i;
		else
			--j;
		if(i < 0 || j < 1)
			break;
	}
	
	
	
	// output
	printf("%lli\n", count);
	



	return 0;
}





// end
