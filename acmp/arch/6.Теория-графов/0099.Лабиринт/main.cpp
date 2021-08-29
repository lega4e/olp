#include <iostream>
#include <vector>
#include <queue>


using namespace std;





// types
typedef long long llong;

struct vertex_t
{
	int         c;
	vector<int> a;
};





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


pair<int, int> read_map(vector<vertex_t> &adjl, int h, int m, int n)
{
	auto c2i = [=](int x, int y, int i) {
		return i*m*n + y*n + x;
	};

	string line;
	adjl.assign(h*m*n, vertex_t { 'o', {} });
	int beg, end;
	for (int i = 0; i < h; ++i)
	{
		for (int y = 0; y < m; ++y)
		{
			cin >> line;
			if ((int)line.size() != n)
				throw "line.size() != n";
			for (int x = 0; x < n; ++x)
			{
				adjl[c2i(x, y, i)].c = line[x];

				if (line[x] == 'o')
					continue;

				if (line[x] == '1')
					beg = c2i(x, y, i);
				else if (line[x] == '2')
					end = c2i(x, y, i);

				if (x > 0 && adjl[c2i(x-1, y, i)].c != 'o')
					adjl[c2i(x, y, i)].a.push_back(c2i(x-1, y, i)),
					adjl[c2i(x-1, y, i)].a.push_back(c2i(x, y, i));

				if (y > 0 && adjl[c2i(x, y-1, i)].c != 'o')
					adjl[c2i(x, y, i)].a.push_back(c2i(x, y-1, i)),
					adjl[c2i(x, y-1, i)].a.push_back(c2i(x, y, i));

				if (i > 0 && adjl[c2i(x, y, i-1)].c != 'o')
					adjl[c2i(x, y, i-1)].a.push_back(c2i(x, y, i));
			}
		}
	}

	return { beg, end };
}

int bfs(vector<vertex_t> &adjl, int beg, int end)
{
	for (auto &v : adjl)
		v.c = -1;

	queue<int> que;
	que.push(beg);
	adjl[beg].c = 0;
	int v;

	while (!que.empty())
	{
		v = que.front();
		que.pop();

		if (v == end)
			return adjl[v].c;

		for (int adji : adjl[v].a)
		{
			if (adjl[adji].c >= 0)
				continue;
			que.push(adji);
			adjl[adji].c = adjl[v].c + 1;
		}
	}

	return -1;
}





// main
int main(void)
{
	vector<vertex_t> adjl;
	int  const h          = nxti();
	int  const m          = nxti();
	int  const n          = nxti();
	auto const [beg, end] = read_map(adjl, h, m, n);

	/*
	 * printf("%i -> %i\n", beg, end);
	 * for (int i = 0; i < (int)adjl.size(); ++i)
	 * {
	 *     if (adjl[i].a.empty())
	 *         continue;
	 *     printf("%i) ", i);
	 *     for (int j = 0; j < (int)adjl[i].a.size(); ++j)
	 *         printf(j == 0 ? "%i" : ", %i", adjl[i].a[j]);
	 *     printf("\n");
	 * }
	 */
	cout << bfs(adjl, beg, end) * 5 << endl;


	return 0;
}





// end
