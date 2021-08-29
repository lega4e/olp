#include <bits/stdc++.h>

main()
{
	int a, b, v, r, i;
	std::cin >> a >> b;

	for (v = a, i = 4; i--;)
		r = ceil((v - (a - 1.)) / b),
		v = r*a + v - r*b;

	std::cout << v;
}
