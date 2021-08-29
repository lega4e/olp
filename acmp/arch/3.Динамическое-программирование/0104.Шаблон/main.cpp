#include <iostream>
#include <set>
#include <vector>


using namespace std;





// types
typedef long long llong;

bool checked[300][300] = { false };





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


bool ismatch(
	char const *tmplb, char const *tmple,
	char const *strb,  char const *stre
)
{
	if (checked[tmple - tmplb][stre - strb])
		return false;

	for (; tmplb != tmple && strb != stre; ++tmplb, ++strb)
	{
		if ((*tmplb == '?' && *strb >= 'A' && *strb <= 'Z') ||
			*tmplb == *strb)
		{
			continue;
		}

		if (*tmplb != '*')
			goto fail_label;

		while (tmplb != tmple && *tmplb == '*')
			++tmplb;
		for (;
			strb != next(stre) &&
			(strb == stre || (*strb >= 'A' && *strb <= 'Z'));
			++strb
		)
		{
			if (ismatch(tmplb, tmple, strb, stre))
				return true;
			else
				checked[tmple - tmplb][stre - strb] = true;
		}

		goto fail_label;
	}

	while (tmplb != tmple && *tmplb == '*')
		++tmplb;

	if (tmplb == tmple && strb == stre)
		return true;
fail_label:
	checked[tmple - tmplb][stre - strb] = true;
	return false;
}

bool istmpl(string const &s)
{
	for (char c : s)
		if (c == '*' || c == '?')
			return true;
	return false;
}





// main
int main()
{
	string tmpl, str;
	cin >> tmpl >> str;

	if (istmpl(str))
		swap(str, tmpl);

	printf(ismatch(
		tmpl.data(), tmpl.data() + tmpl.size(),
		str.data(),  str.data()  + str.size()
	) ? "YES\n" : "NO\n");

	return 0;
}





// end
