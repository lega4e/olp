#pragma GCC optimize 5

#include <cmath>
#include <iostream>
#include <vector>


using namespace std;





// types
template<typename Cut>
struct Tree
{
	vector<Cut> cuts;

	void init(char const *s, int n)
	{
		cuts.resize( (int) pow( 2, ceil(log2(n)) + 1 ) - 1 );
		cuts[0].init(*this, s, 0, n-1);
		return;
	}

	auto operator()(int l, int r)
	{
		return cuts[0].get(*this, l, r);
	}

	Cut &operator()(Cut const *cut, int i)
	{
		return child(cut, i);
	}

	Cut &child(Cut const * cut, int i)
	{
		return cuts[(cut - cuts.data())*2 + 1 + i];
	}

	Cut &parent(int n)
	{
		return cuts[(n - 1) / 2];
	}
};



struct Value
{
	int min, max;
	int exit;

	Value operator+(Value const &rhs) const
	{
		Value cut;
		cut.min = std::min(min, exit + rhs.min);
		cut.max = std::max(max, exit + rhs.max);
		cut.exit = exit + rhs.exit;
		return cut;
	}
};

struct Cut
{
	Value val;
	int l, r;

	void init(Tree<Cut> &tree, char const *s, int ll, int rr)
	{
		l = ll;
		r = rr;
		if(l == r)
		{
			val = s[l] == '-' ? Value { -1, 0, -1 } : Value { 0,  1, 1  };
			return;
		}

		tree(this, 0).init(tree, s, l, (l+r)/2);
		tree(this, 1).init(tree, s, (l+r)/2+1, r);

		val = tree(this, 0).val + tree(this, 1).val;
		return;
	}

	Value get(Tree<Cut> &tree, int ll, int rr)
	{
		if(ll == l and rr == r)
			return val;

		if(rr <= (l+r)/2)
			return tree(this, 0).get(tree, ll, rr);

		if(ll >= (l+r)/2+1)
			return tree(this, 1).get(tree, ll, rr);

		return
			tree(this, 0).get(tree, ll, (l+r)/2) +
			tree(this, 1).get(tree, (l+r)/2+1, rr);
	}
};






// main
int main( int argc, char *argv[] )
{
	int testc;
	int n, m;
	string s;
	int l, r;
	Tree<Cut> tree;

	cin >> testc;
	Value beg;
	for(int test = 0; test < testc; ++test)
	{
		cin >> n >> m >> s;
		tree.init(s.data(), s.size());

		for(int i = 0; i < m; ++i)
		{
			cin >> l >> r;
			--l;
			--r;

			beg = { 0, 0, 0 };
			if(l != 0)
				beg = beg + tree(0, l-1);
			if(r != (int)s.size()-1)
				beg = beg + tree(r+1, s.size()-1);

			cout << (beg.max - beg.min + 1) << endl;
		}
	}



	return 0;
}





// end
