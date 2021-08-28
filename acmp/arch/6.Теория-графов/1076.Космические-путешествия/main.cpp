#include <cstdio>
#include <cstring>


using namespace std;





// structs
struct Link 
{
	int a, b;

	bool operator==(Link const &link) const
	{
		return (a == link.a && b == link.b) ||
			(a == link.b && b == link.a);
	}
	bool operator!=(Link const &link) const
	{
		return !operator==(link);
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;
Link *links;

int result;




// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i", &n);
	--n;
	links = n ? new Link[n] : nullptr;
	for(auto *b = links, *e = links+n; b != e; ++b)
	{
		fscanf(file, "%i%i", &b->a, &b->b);
		--b->a;
		--b->b;
	}
	fclose(file);
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

void calculate()
{
	result = 0;
	if(n < 2)
		return;

	int const counterlen = n+1;
	int *counter = new int[counterlen];
	memset(counter, 0, sizeof *counter * counterlen);



	// counter
	for(auto *b = links, *e = links+n; b != e; ++b)
	{
		++counter[b->a];
		++counter[b->b];
	}
	
	
	
	// result
	for(auto *b = counter, *e = counter+counterlen; b != e; ++b)
	{
		if(*b > 1)
			++result;
	}

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
