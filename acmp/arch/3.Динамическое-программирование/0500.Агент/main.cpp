#include <algorithm>
#include <cstdio>


using namespace std;





// struct
struct Agent
{
	int age;
	int risk;

	Agent *prev;
	Agent *next;
};


bool operator<(Agent const &lhs, Agent const &rhs)
{
	return lhs.age < rhs.age;
}

inline void create_link(Agent *lhs, Agent *rhs)
{
	lhs->next = rhs;
	rhs->prev = lhs;
	return;
}

inline void destroy_link(Agent *lhs, Agent *rhs)
{
	lhs->next = nullptr;
	rhs->prev = nullptr;
	return;
}





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





void calculate(Agent *a)
{
	create_link(a-1, a);
	if(a[-2].prev)
	{
		destroy_link(a-2, a-1);
	}
	else if(a[-2].risk < a[-1].risk)
	{
		destroy_link(a-2, a-1);
		create_link(a-3, a-2);
	}

	return;
}


int calculate_summarize_risk(int n, Agent *a)
{
	auto e = a+n;
	int risk = 0;
	while(a < e)
	{
		a = a->next;
		risk += a->risk;
		if(!a->next)
			++a;
	}
	return risk;
}




int main( int argc, char *argv[] )
{
	int n;
	Agent *a;


	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		a = new Agent[n];
		for(auto *b = a, *e = a+n; b != e; ++b)
		{
			fscanf(file, "%i%i", &b->age, &b->risk);
			b->next = b->prev = nullptr;
		}
		fclose(file);
	}
	sort(a, a+n);



	// calculate
		// preparation
	create_link(a, a+1);
	if(n > 2)
		create_link(a+1, a+2);

		// main calc
	for(auto *b = a+3, *e = a+n; b < e; ++b)
	{
		calculate(b);
	}
	int const risk = calculate_summarize_risk(n, a);


	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", risk);
		fflush(file);
		fclose(file);
	}
	// {
		// auto b = a;
		// auto e = a+n;
		// while(b < e)
		// {
			// printf("%i->%i = %i;\n", b->age, b->next->age, b->next->risk);
			// b = b->next;
			// if(!b->next)
				// ++b;
		// }
		// fflush(stdout);
	// }



	return 0;
}





// end
