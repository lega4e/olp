/*
 * autor:   clever
 * date:    Oct 13 22:41:48 2019
 */

#include <algorithm>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef struct
	{
		int pos;
		char dir;
	} Bubble;

	int n, l;
	Bubble *bubbles;
	
	
	
	// input
	cin >> n >> l;
	bubbles = new Bubble[n];
	for(auto *b = bubbles, *e = bubbles+n; b != e; ++b)
		cin >> b->pos >> b->dir;
	
	
	
	// solve
	Bubble *lbub = nullptr;
	Bubble *rbub = nullptr;
	for(auto *b = bubbles, *e = bubbles+n; b != e; ++b)
	{
		if(b->dir == 'L')
		{
			if(!lbub || b->pos > lbub->pos)
				lbub = b;
		}
		else
		{
			if(!rbub || b->pos < rbub->pos)
				rbub = b;
		}
	}

	int solution;
	if(lbub)
	{
		if(rbub)
			solution = max(
				lbub->pos,
				l - rbub->pos
			);
		else
			solution = lbub->pos;
	}
	else if(rbub)
		solution = l - rbub->pos;
	else
		solution = -1;
	
	
	
	// output
	cout << solution << endl;



	return 0;
}





// end
