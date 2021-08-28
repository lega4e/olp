#include <cstdio>
#include <map>

using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n, k;

int ablen;
int *a, *b;

int result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i", &n, &k);
	fclose(file);

	ablen = n-k+1;
	if(ablen <= 0)
	{
		ablen = 0;
		a = b = nullptr;
		return;
	}
	a = new int[ablen];
	b = new int[ablen];
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i", result);
	fflush(file);
	fclose(file);
	return;
}

void calculate_ab()
{
	if(ablen == 0)
		return;
	a[0] = 1;
	b[0] = 1;

	for(int i = 1; i < ablen; ++i)
	{
		a[i] = (i-1) * b[i-1];
		b[i] = a[i-1] + (i-1)*b[i-1];
	}

	return;
}

/*
 * int calculate_s(int n, int k)
 * {
 *         if(k == 1)
 *                 return n;
 *         if(n == k || k == 0)
 *                 return 1;
 * 
 *         auto key = make_pair(n, k);
 *         auto it = exs.find(key);
 *         if(it != exs.end())
 *         {
 *                 return it->second;
 *         }
 * 
 *         int result = 0;
 *         for(int i = 0; i < n-k+1; ++i)
 *         {
 *                 result += calculate_s(n-i-1, k-1);
 *         }
 * 
 *         exs[key] = result;
 *         return result;
 * }
 */

int fac(int n)
{
	for(int i = n-1; i > 1; --i)
		n *= i;
	return n;
}

int calculate_s(int n, int k)
{
	if(k > n)
		return 0;
	if(k == n || k == 0)
		return 1;
	return
		fac(n) / 
		( fac(k) * fac(n-k) );
}

void calculate()
{
	calculate_ab();
	result = k > n ? 0 : a[n-k] * calculate_s(n, k);
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
