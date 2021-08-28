#include <algorithm>
#include <cstdio>
#include <vector>


using namespace std;






// structs
struct Link
{
	int b, e;

	int distance(int *arr) const
	{
		return arr[e]-arr[b];
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";






// functions




// main
int main( int argc, char *argv[] )
{
	int n;
	int *arr;
	vector<Link> links;



	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		arr = new int[n];
		for(auto *b = arr, *e = arr+n; b != e; ++b)
		{
			fscanf(file, "%i", b);
		}
		fclose(file);
	}
	sort(arr, arr+n);


	// calculate
	if(n > 1)
		links.push_back({0, 1});
	if(n > 2)
		links.push_back({1, 2});
	for(int i = 3; i < n; ++i)
	{
		if( links[ links.size()-2 ].e == i-2 )
		{
			links.pop_back();
		}
		else
		{
			if( 
				links[ links.size()-2 ].distance(arr) <
				links.back().distance(arr)
			)
			{
				links.pop_back();
				links.push_back({i-3, i-2});
			}
		}
		links.push_back({i-1, i});
	}

	int res = 0;
	for(auto b = links.begin(), e = links.end(); b != e; ++b)
	{
		printf("<%i, %i>: %i\n", arr[b->b], arr[b->e], b->distance(arr));
		res += b->distance(arr);
	}


	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", res);
		fflush(file);
		fclose(file);
	}




	return 0;
}





// end
