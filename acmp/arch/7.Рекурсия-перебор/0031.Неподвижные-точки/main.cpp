#include <cstdio>
#include <utility>


using namespace std;





// types
typedef unsigned long long ullong;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n, k;
int *arr;
ullong result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i", &n, &k);
	fclose(file);

	if(n-k > 0)
	{
		arr = new int[n-k];
		for(int i = 0; i < n-k; ++i)
		{
			arr[i] = i;
		}
	}
	else
		arr = nullptr;
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%llu", result);
	fflush(file);
	fclose(file);
	return;
}

void print_arr()
{
	for(int i = 0; i < n-k; ++i)
	{
		printf("%i ", arr[i]);
	}
	printf("\n");
	return;
}

ullong calculate_a(int n, int pos)
{
	// printf("calc a -> n: %i, pos %i\n", n, pos);
	// print_arr();

	if(n == 0)
		return 1;
	if(pos == n-1)
		return arr[pos] != pos ? 1 : 0;

	ullong result = 0;
	for(int i = pos; i < n; ++i)
	{
		if(pos != arr[i])
		{
			swap(arr[pos], arr[i]);
			result += calculate_a(n, pos+1);
			swap(arr[pos], arr[i]);
		}
	}

	return result;
}

ullong calculate_s(int n, int i)
{
	if(i == 0)
		return 1;
	if(i == 1)
		return n;

	ullong result = 0;
	for(int k = 0; k < n-i+1; ++k)
	{
		result += calculate_s(n-k-1, i-1);
	}

	return result;
}

void calculate()
{
	ullong s = calculate_s(n, k);
	ullong a = calculate_a(n-k, 0);
	// printf("s: %llu, a: %llu\n", s, a);
	result = a*s;
	return;
}





// main
int main( int argc, char *argv[] )
{
	input();
	calculate();
	output();
	

	return 0;
}





// end
