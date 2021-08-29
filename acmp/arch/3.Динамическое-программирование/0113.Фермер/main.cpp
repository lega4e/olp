#include <bits/stdc++.h>

using namespace std;

main()
{
	int n, p[1001] = { 0 }, c[1001], m = 0, x;
	string l;

	for (cin >> n; n--; swap(p, c))
	{
		cin >> l;
		for (x = l.size(); x--;)
			m = max(m, c[x] = l[x] - 49 ? 0 : 1 + min(c[x+1], min(p[x+1], p[x])));
	}

	printf("%i\n", m*m);
}
