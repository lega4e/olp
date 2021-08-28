#include <iostream>
#include <set>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	set<int> set;
	
	
	
	// input
	scanf("%i", &n);
	for(int i = 0, input; i < n; ++i)
		scanf("%i", &input),
		set.insert(input);



	// solve
	if((int)set.size() != n)
		goto fail_label;
	{
		int prev = *set.begin();
		for(auto b = next(set.begin()), e = set.end(); b != e; ++b)
			if(*b != prev+1)
				goto fail_label;
			else
				prev = *b;
	}
	
	
	
	// output
	printf("Deck looks good\n");
	return 0;

fail_label:
	printf("Scammed\n");
	return 0;
}





// end
