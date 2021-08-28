#include <iostream>

#define MOD 1000000007


using namespace std;





// types
typedef long long llong;

struct Cut
{
	int l, r;
	llong val;

	Cut *left, *right;



	// methods
	Cut &init(llong i, llong vval)
	{
		l = r = i;
		val = vval;
		left = right = nullptr;
		return *this;
	}

	Cut &init(Cut *lleft, Cut *rright)
	{
		left = lleft;
		right = rright;
		l = left->l;
		r = right->r;
		val = left->val * right->val % MOD;
		return *this;
	}


	llong get(int ll, int rr)
	{
		if(ll == l && rr == r)
			return val;

		llong res = 1;
		if(ll <= left->r)
		{
			res *= left->get(
				max( left->l, ll ),
				min( left->r, rr )
			);
		}
		if(rr >= right->l)
		{
			res *= right->get(
				max( right->l, ll ),
				min( right->r, rr )
			);
		}

		return res % MOD;
	}
};





// main
int main( int argc, char *argv[] )
{
	int n, tests;
	Cut **cuts;
	
	

	// input, prepare
	scanf("%i%i", &n, &tests);

	cuts = new Cut*[n];
	llong val;
	for(int i = 0; i < n; ++i)
	{
		scanf("%lli", &val);
		cuts[i] = new Cut;
		cuts[i]->init(i, val);
	}

	Cut *acut;
	while(n > 1)
	{
		for(int i = 0; i < n/2; ++i)
		{

			acut = new Cut;
			acut->init( cuts[2*i], cuts[2*i+1] );
			cuts[i] = acut;
		}

		if(n%2)
		{
			cuts[n/2] = cuts[n-1];
		}

		n = n - n/2;
	}
	
	
	
	// solve
	int l, r;
	for(int test = 0; test < tests; ++test)
	{
		scanf("%i%i", &l, &r);
		--l, --r;
		printf("%lli\n", cuts[0]->get(l, r));
	}



	return 0;
}





// end
