#include <iostream>
#include <numeric>
#include <vector>


using namespace std;





// types
typedef long long llong;





// functions
template<typename T>
T next()
{
	T t;
	cin >> t;
	return t;
}

auto nxti = next<int>;
auto nxtll = next<llong>;


bool calculate_predicate(int i, int j, int n)
{
	for (int p = 0; p < n-1; ++p)
	{
		if (
			(i & (1 << p) && i & (1 << (p+1)) &&
			 j & (1 << p) && j & (1 << (p+1))) ||
			(!(i & (1 << p)) && !(i & (1 << (p+1))) &&
			 !(j & (1 << p)) && !(j & (1 << (p+1))))
		)
			return false;
	}
	return true;
}

void calculate_p(vector<bool> &p, int n)
{
	int const pow = 1 << n;
	p.resize(pow * pow);
	for (int i = 0; i < pow; ++i)
	for (int j = 0; j < pow; ++j)
		p[i*pow + j] = calculate_predicate(i, j, n);
}





// main
int main( int argc, char *argv[] )
{
	int n, m, pow;
	vector<bool>  p;
	vector<llong> prv, cur;

	n = nxti();
	m = nxti();
	if (n > m)
		swap(n, m);
	pow = 1 << n;

	calculate_p(p, n);
	prv.assign(pow, 1);

	for (int k = 1; k < m; ++k)
	{
		cur.assign(pow, 0);
		for (int i = 0; i < (int)cur.size(); ++i)
		for (int j = 0; j < (int)cur.size(); ++j)
			cur[i] += prv[j] * (p[i*pow + j] ? 1 : 0);
		swap(cur, prv);
	}

	cout << accumulate(prv.begin(), prv.end(), 0) << endl;

	return 0;
}





// end
