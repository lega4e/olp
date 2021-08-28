#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int t, n;
	cin >> t;
	bool was;
	int c;
	for(int i = 0; i < t; ++i)
	{
		cin >> n;
		int *arr = new int[n];
		for(int j = 0; j < n; ++j)
			cin >> arr[j];


		was = true;
		c = 0;
		while(was)
		{
			was = false;
			for(int j = 0; j < n-1; ++j)
				if(arr[j] > arr[j+1])
				{
					swap(arr[j], arr[j+1]);
					++c;
					was = true;
				}
		}

		cout << c << endl;

		delete[] arr;
	}



	return 0;
}





// end
