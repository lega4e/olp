#include <iostream>


using namespace std;





// types
/*
 * Чтобы каждый раз не писать long long
 */
typedef long long llong;



// objects
/*
 * Константа, по которой мы должны брать модуль
 */
constexpr llong MOD = 1000000007;



// functions
/*
 * Нам необходим математический модуль, а не тот,
 * что предоставляет на C++ в виде оператора %
 */
inline llong mod(llong a, llong b)
{
	return (b + a%b) % b;
}

/*
 * Расширенный алгоритм Евклида; будем использовать
 * для нахождения обратного по модулю элемента
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
 * Вычисление факториала по модулю
 */
llong factorial(llong n)
{
	llong res = 1;
	while(n > 1)
	{
		res = res * n % MOD;
		--n;
	}
	return res;
}





// main
int main( int argc, char *argv[] )
{
	/*
	 * Объявляем массив, где будем хранить количество
	 * повторений каждй из букв; инициализируем нулями;
	 * (всегда 26 элементов, т.к. входная строка может
	 * состоять только из строчных латинских букв)
	 */
	llong chs[26] = { 0 };

	// количество букв всего
	llong total = 0;
	
	
	
	// input
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	 * считываем, пока не будет достигнут конец файла
	 * (или произойдёт какая-нибудь ошибка считывания)
	 */
	for(char ch = cin.get(); cin && islower(ch); ch = cin.get())
		++chs[ch-'a'], ++total;
	
	
	
	// solve
	llong result;
	{
		/*
		 * находим количество разных аннаграм, если бы
		 * все буквы были различны
		 */
		result = factorial(total);

		/*
		 * в den будет храниться кол-во разных перестановок,
		 * где перемещаются только одинаковые буквы
		 */
		llong den = 1;
		for(int i = 0; i < 26; ++i)
		{
			/*
			 * будем считать только для тех букв, 
			 * которые повторяются не меньше двух раз
			 */
			if(chs[i] < 2)
				continue;
			/*
			 * не забываем брать модуль, ведь
			 * возможно переполнение
			 */
			den = den * factorial(chs[i]) % MOD;
		}

		/*
		 * с помощью расширенного алгоритма Евклида
		 * находим обратный по модулю MOD элемент,
		 * который запишется в invel; умножением
		 * на обратный элемент мы делим кол-во всех
		 * перестановок на кол-во таких, когда 
		 * перемещаются одинаковые буквы, и таким
		 * образом получаем кол-во всех неповторяющихся
		 * перестановок
		 */
		llong invel, null;
		exgcd(den, MOD, invel, null);
		result = mod(result * invel, MOD);
	}
	
	
	
	// output
	/*
	 * выводим результат
	 */
	printf("%lli\n", result);



	return 0;
}





// end
