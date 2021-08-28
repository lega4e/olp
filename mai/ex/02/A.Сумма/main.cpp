#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	cin >> n;

	long long sum = 0;
	int input;
	for(int i = 0; i < n; ++i)
		scanf("%d", &input), sum += input;

	cout << sum << endl;




	return 0;
}





// end
