#include <iostream>
#include <cmath>
#include <vector>

using namespace std;





// types
typedef long long llong;





// functions
/*
 * Алгоритм Евклида по нахождению НОД;
 * расширенный алгоритм Евклида, который находит
 * также корни диофантова уравнения
 * 	a*x + b*y = gcd(a, b);
 * с помощью расширенного алгоритма Евклида
 * можно найти обратный по простому модулю элемент,
 * нужный, чтобы делить под модулем (это будет x);
 * а также НОК
 */
llong gcd(llong a, llong b)
{
	while(a)
	{
		b %= a;
		swap(a, b);
	}
	return b;
}

llong exgcd(llong a, llong b, llong &x, llong &y)
{
	if(a == 0)
	{
		x = 0, y = 1;
		return b;
	}

	llong xx, yy, g;
	g = exgcd(b%a, a, xx, yy);
	x = yy - xx*(b/a);
	y = xx;
	return g;
}

inline llong lcm(llong a, llong b)
{
	return a/gcd(a, b)*b;
}



/*
 * Математический модуль числа;
 * разделить число под простым модулем
 */
inline llong mod(llong a, llong b)
{
	return (b + a%b) % b;
}

inline llong div(llong a, llong b, llong m)
{
	llong nul;
	exgcd(b, m, b, nul);
	return mod(a*b, m);
}



/*
 * Решето Эратосфена, которое находит все 
 * простые числа (они помечаются нулями),
 * меньшие n; а также по количеству простых
 * чисел (вычисляется всегда чуть больше)
 */
void sieve(llong n, vector<llong> &sie)
{
	sie.assign(n, 0);
	sie[0] = sie[1] = 1; // вычёркиваем 0 и 1
	for(llong i = 2; i*i < n; ++i)
	{
		if(sie[i])
			continue;
		for(llong j = i*i; j < n; j += i)
			sie[j] = i; // записываем первый делить числа
	}
}

void sieve_by_count(llong count, vector<llong> &sie)
{
	sieve(
		count * ceil(log(count)) * 6 / 5 + 5,
		sie
	);
	return;
}





// end


#ifndef LIS_STRING_HPP
#define LIS_STRING_HPP

#include <sstream>
#include <string>





namespace lis
{





// CUT ZERO
inline std::string cutzero(std::string const &s)
{
	auto pos = s.find_last_not_of('0');
	if(pos == s.npos)
		return s;
	return s[pos] == '.' ?
		s.substr( 0, pos+2 ) :
		s.substr( 0, pos+1 );
}

inline void cutzero(std::string *s)
{
	auto pos = s->find_last_not_of('0');
	if(pos == s->npos)
		return;
	(*s)[pos] == '.' ?
		s->erase(pos+2) :
		s->erase(pos+1);
	return;
}




inline void cutspace(std::string *s)
{
	auto b = s->find_first_not_of(" \t\n");
	if(b == std::string::npos)
	{
		*s = "";
		return;
	}
	*s = s->substr(
		b, s->find_last_not_of(" \t\n") - b + 1
	);
	return;
}

inline std::string cutspace(std::string const &s)
{
	auto b = s.find_first_not_of(" \t\n");
	if(b == std::string::npos)
		return "";
	return s.substr(
		b, s.find_last_not_of(" \t\n") - b + 1
	);
}

inline std::vector<std::string> split(std::string const &s, char d)
{
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> res;

	while(std::getline(ss, item, d))
	{
		res.push_back(std::move(item));
	}

	return res;
}

template<typename Iterator>
std::string join(Iterator b, Iterator e, std::string const &between)
{
	if(b == e)
		return "";

	std::string res = *b;
	while(++b != e)
	{
		res += between;
		res += *b;
	}

	return res;
}





// FILLS
int count_symbols(std::string const &s);
void fills(std::string *s, int n);
std::string fills(std::string const &s, int n);
std::string fills(std::string &&s, int n);



inline void fills(std::wstring *s, int n)
{
	if((int)s->size() >= n)
		return;
	s->reserve(n);
	std::fill_n( std::back_inserter(*s), n-s->size(), L' ' );
	return;
}

inline std::wstring fills(std::wstring const &s, int n)
{
	if((int)s.size() >= n)
		return s;
	std::wstring cp = s;
	cp.reserve(n);
	std::fill_n( std::back_inserter(cp), n-cp.size(), L' ' );
	return cp;
}

inline std::wstring fills(std::wstring &&s, int n)
{
	if((int)s.size() >= n)
		return s;
	s.reserve(n);
	std::fill_n( std::back_inserter(s), n-s.size(), L' ' );
	return s;
}





// OTHER
void genkeys(
	std::vector<std::string> const &names,
	std::vector<std::string> &keys,
	bool letcase = false
);

std::string format(const char *fmt, ...);



/*
 * Вычленяет объекты из строки
 *   i — int
 *   l - long
 *   u - unsigned int
 *   f - float
 *   d - double
 *   s,w - std::string
 *   a — кладёт всю оставшуюся строку в std::string
 *
 * тип вычленяемого объекта и их порядок получается из fmt;
 * fmt может выглядеть так: "iifs" — тогда сначала считается
 * int, затем ещё раз int, далее float и в конце std::string.
 * Всё это записывается в dat. Для вычленения используется
 * stringstream::operator>>(...)
 */
bool scan(
	std::string const &enter,
	char const *fmt,
	void **dat
);

inline bool scan(
	std::string const &enter,
	char const *fmt,
	std::vector<void *> dat
)
{
	return scan(enter, fmt, dat.data());
}





}





inline std::string operator*(int c, std::string const &s)
{
	std::string res;
	res.resize(s.size()*c);
	for(int i = 0; i < (int)res.size(); ++i)
		res[i] = s[i % s.size()];
	return res;
}

inline std::string operator*(std::string const &s, int c)
{
	return c*s;
}





#endif


// #pragma GCC optimize 5


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int testc;
	string s, t;
	llong szlcm;

	cin >> testc;
	for(int test = 0; test < testc; ++test)
	{
		cin >> s >> t;
		szlcm = lcm(s.size(), t.size());
		if(szlcm / s.size() * s == szlcm / t.size() * t)
			cout << szlcm / s.size() * s << endl;
		else
			cout << -1 << endl;
	}



	return 0;
}





// end
