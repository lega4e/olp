#include <iostream>


using namespace std;





// types
/*
 * Чтобы каждый раз не писать long long
 */
typedef long long llong;



// objects
/*
 * Объяляем глобальную константу
 */
constexpr llong const MOD = 1000000007;



// functions
/*
 * В C++ оператор % вычислет модуль (остаток) в математическом
 * смысле лишь для неотрицательных чисел; нам же понадобится
 * модуль отрицательных числе (обратный элемент может быть
 * отрицательным)
 */
llong mod(llong a, llong b)
{
	return (b + a%b) % b;
}

/*
 * Расширенный алгоритм Евклида: возвращает НОД,
 * записывает в x и y числа, при подстановке которых
 * в выражение a*x + b*x = gcd(a,b) получается верное
 * уравнение
 */
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

/*
 * Быстрое возведение в степень, которое имеет логарифмическую
 * сложность от степени, в которую необходимо возвести
 */
llong bin_pow(llong a, llong b)
{
	llong res = 1;
	while(b)
	{
		if(b % 2)
			res = res*a % MOD;
		a = a*a % MOD;
		b /= 2;
	}

	return res;
}





// main
int main( int argc, char *argv[] )
{
	int t; // количество тестов
	scanf("%i", &t); // считываем
	/*
	 * Я люблю стандартную библиотеку ввода-вывода Си,
	 * и поэтому чаще всего буду использовать её
	 */
	
	
	
	// solve
	/*
	 * Объявляем необходимые нам переменные:
	 */
	llong b, q, n, qn, res;
	llong x, y;
	for(int i = 0; i < t; ++i)
	{
		/*
		 * Считываем входные данные,
		 * обрабатываем исключительные случаи
		 */
		scanf("%lli%lli%lli", &b, &q, &n);
		if(q == 0)
		{
			printf("%lli\n", b);
			continue;
		}
		if(q == 1)
		{
			printf("%lli\n", b*n);
			continue;
		}


		// находим q в степени n
		qn = bin_pow(q, n);

		// находим обратный элемент (он записывается в x) для q-1
		exgcd(q-1, MOD, x, y);

		// вычисляем результат, не забывая каждй раз брать модуль
		res = mod( mod( b*(qn - 1), MOD ) * x, MOD );

		// вывод в stdout
		printf("%lli\n", res);

	}



	return 0;
}





// end
