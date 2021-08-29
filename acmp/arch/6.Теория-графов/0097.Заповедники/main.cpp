#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;

struct rect_t
{
	int x, y;
	int w, h;
};

bool operator&(rect_t const &lhs, rect_t const &rhs)
{
	return (max(lhs.x + lhs.w, rhs.x + rhs.w) - min(lhs.x, rhs.x) <= lhs.w + rhs.w &&
			max(lhs.y + lhs.h, rhs.y + rhs.h) - min(lhs.y, rhs.y) <= lhs.h + rhs.h);
	/*
	 * return ((lhs.x < rhs.x ?
	 *             rhs.x <= lhs.x + lhs.w :
	 *             lhs.x <= rhs.x + rhs.w) &&
	 *         (lhs.y < rhs.y ?
	 *              rhs.y <= lhs.y + lhs.h :
	 *             lhs.y <= rhs.y + rhs.h) &&
	 *         !(rhs.x == lhs.x + lhs.w &&
	 *          rhs.y == lhs.y + lhs.h) &&
	 *         !(rhs.x == lhs.x + lhs.w &&
	 *          rhs.y + rhs.h == lhs.y));
	 */
}

istream &read_rect(istream &is, rect_t &r)
{
	int x, y, xx, yy;
	is >> x >> y >> xx >> yy;
	r.x = min(x, xx);
	r.y = min(y, yy);
	r.w = abs(xx - x);
	r.h = abs(yy - y);
	return is;
}

istream &read_rect_r(istream &is, rect_t &r)
{
	int R;
	read_rect(is, r) >> R;

	if (R < 0 && (r.w <= R || r.h <= R))
		r.w = r.h = 0;
	else
	{
		r.x -= R;
		r.y -= R;
		r.w += R*2;
		r.h += R*2;
	}

	return is;
}





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





// main
int main()
{
	/*
	 * rect_t r;
	 * for (int i = 0; i < 4; ++i)
	 * {
	 *     read_rect_r(cin, r);
	 *     printf("%i %i %i %i\n", r.x, r.y, r.w, r.h);
	 * }
	 * return 0;
	 */

	int n = nxti();
	vector<rect_t> rects(n);
	vector<int>    comp(n, -1);
	int            compc = 0;

	for (int i = 0; i < n; ++i)
		read_rect_r(cin, rects[i]);

	int tmp;
	for (int i = 0; i < (int)rects.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (!(rects[i] & rects[j]) || comp[i] == comp[j])
				continue;

			if (comp[i] < 0)
			{
				comp[i] = comp[j];
				continue;
			}

			tmp = comp[j];
			for (int k = 0; k < i; ++k)
				if (comp[k] == tmp)
					comp[k] = comp[i];
		}

		if (comp[i] < 0)
			comp[i] = compc++;
	}

	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	cout << comp.size() << endl;

	return 0;
}





// end
