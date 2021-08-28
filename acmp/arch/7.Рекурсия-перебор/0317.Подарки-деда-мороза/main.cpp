#include <algorithm>
#include <cstdio>
#include <map>


using namespace std;





// types
typedef unsigned long long ullong;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

map<pair<int, int*>, ullong> ex;





// function
ullong calculate(int w, int *b, int *e)
{
	// end recurse
	if(w == 0)
		return 1;

	// calculated?
	auto key = make_pair(w, b);
	auto it = ex.find(key);
	if(it != ex.end())
		return it->second;

	// calculate
	ullong result = 0;
	while(b != e)
	{
		if(*b > w)
			break;
		result += calculate(w-*b, b, e);
		++b;
	}

	// add to calculated, return
	ex[key] = result;
	return result;
}





// main
int main( int argc, char *argv[] )
{
	constexpr unsigned int const N = 3;
	int vals[N];
	int w;
	ullong result;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i%i%i", vals, vals+1, vals+2, &w);
		fclose(file);
		sort(vals, vals+N);
	}
	
	
	
	// calculate
	result = calculate(w, vals, vals+N);
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%llu", result);
		fflush(file);
		fclose(file);
	}

	

	return 0;
}





// end
