#include <cstdio>
#include <set>
#include <vector>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;

vector< pair<int, char> > cur;
set< vector< pair<int, char> > > vars;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i", &n);
	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%lu\n", vars.size());
	for(auto b = vars.begin(), e = vars.end(); b != e; ++b)
	{
		for(auto vb = b->begin(), ve = b->end(); vb != ve; ++vb)
		{
			switch(vb->second)
			{
			case 'D':
				fprintf(file, "D%i ", vb->first);
				break;
			case 'T':
				fprintf(file, "T%i ", vb->first);
				break;
			case 'B':
				fprintf(file, "Bull ");
				break;
			default:
				fprintf(file, "%i ", vb->first);
				break;
			}
		}
		fprintf(file, "\n");
	}
	fflush(file);
	fclose(file);

	return;
}

void push_variants(int n)
{
	if(n == 1)
		return;

	cur.push_back({1, 0});


	if(cur.size() == 3)
	{
		if(
			n % 2 == 0 &&
			( (n > 0 && n <= 40) || n == 50 )
		)
		{
			if(n == 50)
				cur.back().second = 'B';
			else
				cur.back() = { n/2, 'D' };
			vars.insert(cur);
		}
		cur.pop_back();
		return;
	}



	// first
	for(int i = 1; i < 21 && i < n; ++i)
	{
		cur.back().first = i;
		push_variants(n-i);
	}

	if(n > 26)
	{
		cur.back().first = 25;
		push_variants(n-25);
	}


	// second
	cur.back().second = 'D';
	for(int i = 2; i < 41; i += 2)
	{
		cur.back().first = i/2;
		if(i == n)
			vars.insert(cur);
		if(i > n)
			break;
		push_variants(n-i);
	}

	cur.back().second = 'B';
	if(n == 50)
		vars.insert(cur);
	else if(n > 51)
		push_variants(n-50);

	// tihrd
	cur.back().second = 'T';
	for(int i = 3; i < 61 && i < n; i += 3)
	{
		cur.back().first = i/3;
		push_variants(n-i);
	}



	cur.pop_back();
	return;
}

void calculate()
{
	push_variants(n);
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
