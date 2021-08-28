#include <iostream>
#include <vector>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	vector<int> locmin, locmax;

	int n;
	double amin, amax;
	int imin, imax;
	double prev, cur, next;

	cin >> n;
	cin >> cur;
	amin = amax = cur;
	imin = imax = 1;
	if(n == 1)
	{
		locmin.push_back(1);
		locmax.push_back(1);
		goto answer;
	}

	cin >> next;
	if(cur < next)
		locmin.push_back(1);
	else if(cur > next)
		locmax.push_back(1);

	for(int i = 1; i < n-1; ++i)
	{
		prev = cur;
		cur = next;
		cin >> next;

		if(cur > amax)
			amax = cur, imax = i+1;
		if(cur < amin)
			amin = cur, imin = i+1;

		if(cur < prev && cur < next)
			locmin.push_back(i+1);
		else if(cur > prev && cur > next)
			locmax.push_back(i+1);
	}


	if(next < cur)
		locmin.push_back(n);
	else if(next > cur)
		locmax.push_back(n);
	if(next > amax)
		imax = n;
	if(next < amin)
		imin = n;


answer:
	cout << locmin.size() << ' ';
	for(int i : locmin)
		cout << i << ' ';
	cout << endl;

	cout << locmax.size() << ' ';
	for(int i : locmax)
		cout << i << ' ';
	cout << endl;

	cout << imin << ' ' << imax << endl;



	return 0;
}





// end
