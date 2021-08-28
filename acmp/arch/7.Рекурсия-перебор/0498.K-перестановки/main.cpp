#include <cmath>
#include <cstdio>
#include <utility>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n, k;
int *arr;
int result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i", &n, &k);
	fclose(file);

	arr = new int[n];
	for(int i = 0; i < n; ++i)
	{
		arr[i] = i;
	}
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i", result);
	fflush(file);
	fclose(file);
}

int calculate(int cur)
{
	if(cur == n-1)
		return 1;

	int result = 0;
	for(int i = cur+1; i < n; ++i)
	{
		if( abs(arr[i] - arr[cur]) <= k )
		{
			swap(arr[cur+1], arr[i]);
			result += calculate(cur+1);
			swap(arr[cur+1], arr[i]);
		}
	}

	return result;
}

void calculate_all()
{
	result = 0;
	for(int i = 0; i < n; ++i)
	{
		swap(arr[0], arr[i]);
		result += calculate(0);
		swap(arr[0], arr[i]);
	}
	return;
}




// main
int main( int argc, char *argv[] )
{
	input();
	calculate_all();
	output();

	return 0;
}





// end
