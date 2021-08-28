#include <iostream>
#include <iterator>
#include <vector>


using namespace std;





// functions
template<
	typename FIterator,
	typename SIterator,
	typename RIterator,
	typename Criterion
>
void merge(
	FIterator fb, FIterator fe,
	SIterator sb, SIterator se,
	RIterator res,
	Criterion crit
)
{
	while(fb != fe && sb != se)
	{
		switch(crit(*fb, *sb))
		{
		case 'f':
			*res = *fb;
			++fb;
			break;
		case 's':
			*res = *sb;
			++sb;
			break;
		case 'F':
			*res = *fb;
			++fb;
			++sb;
			break;
		case 'S':
			*res = *sb;
			++fb;
			++sb;
			break;
		default:
			throw std::logic_error("invalid criterion return value");
		}
		++res;
	}

	while(fb != fe)
		*res = *fb,
		++res,
		++fb;

	while(sb != se)
		*res = *sb,
		++res,
		++sb;

	return;
}





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	struct One
	{
		int c;
		llong w;
	};


	int n;
	llong wmax;
	llong *weights;
	int *coins;
	
	
	
	// input
	scanf("%i%lli", &n, &wmax);
	weights = new llong[n+1];
	coins = new int[n+1];

	for(int i = 1; i < n+1; ++i)
		scanf("%lli%i", weights+i, coins+i);
	
	
	
	// solve
	vector<One> cur, next, temp;
	cur.reserve(n*2);
	next.reserve(n*2);
	temp.reserve(n*2);
	cur.push_back( { 0, 0 } );
	cur.push_back( { coins[1], weights[1] } );

	for(int i = 2; i < n+1; ++i)
	{
		next.clear();

		for(auto b = cur.begin(), e = cur.end(); b != e; ++b)
		{
			if(b->w + weights[i] <= wmax)
				next.push_back( {
					b->c + coins[i],
					b->w + weights[i]
				} );
		}

		temp.clear();
		merge(
			cur.begin(), cur.end(),
			next.begin(), next.end(),
			back_inserter(temp),
			[](One lhs, One rhs)->char
			{
				if(lhs.c != rhs.c)
					return lhs.c < rhs.c ? 'f' : 's';
				return lhs.w < rhs.w ? 'F' : 'S';
			}
		);
		swap(cur, temp);
	}
	
	
	
	// output
	printf("%i\n", cur.back().c);



	return 0;
}





// end
