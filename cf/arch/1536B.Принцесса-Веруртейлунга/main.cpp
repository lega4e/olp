#include <iostream>
#include <functional>

// #include <lis/iostream.hpp>


using namespace std;





// functions
template<typename T>
T read()
{
	T val;
	cin >> val;
	return val;
}

auto readi = read<int>;



/*
 * Класс, который производит перебов всех возможных значений
 * последовательности.
 *
 * В конструктор подаётся начальный и конечный итератор
 * последовательности, конечное значение перебора (внивание! задаётся
 * значение после последнего, которое должно быть включено в перебор,
 * т.е., если нужно перебрать весь алфавит, то в качестве конечного
 * значения задаётся не 'z', а 'z'+1) и, опционально, функция
 * инкремента, которая получает на вход итератор и должна передвинуть
 * позицию в нём на единицу вперёд; по умолчанию используется
 * оператор ++*b;
 */
template<typename Iterator, typename Value>
class Enumerator
{
public:
	typedef Iterator                    iter_t;
	typedef Value                       value_t;
	typedef std::function<void(iter_t)> incr_t;

	Enumerator(
		iter_t  b,
		iter_t  e,
		value_t endval
	): b(b), e(e), endval(endval) {}

	template<typename IncrementFunction>
	Enumerator(
		iter_t  b,
		iter_t  e,
		value_t endval,
		IncrementFunction  inc
	): b(b), e(e), endval(endval), increment(inc) {}


	/*
	 * Производит полный перебор и для каждого
	 * значения вызывает функцию f: при этом, если
	 * она возвращает true, перебор заканчивается
	 * и метод возращает true
	 */
	template<typename F>
	bool operator()(F f)
	{
		return enumerate(b, f);
	}

private:
	template<typename F>
	bool enumerate(Iterator beg, F f)
	{
		if (beg == e)
			return f();

		value_t oldval = *beg;
		while (*beg != endval)
		{
			if (enumerate(next(beg), f))
				return true;
			increment(beg);
		}

		*beg = oldval;
		return false;
	}

	iter_t  b, e;
	value_t endval;
	incr_t  increment = [](Iterator b)->void { ++*b; };
};





// main
int main( int argc, char *argv[] )
{
	/*
	 * vector<int> vecint = { 1, 1, 1 };
	 * Enumerator en(vecint.begin(), vecint.end(), 4);
	 * en( [&]() { cout << vecint << endl; return false; } );
	 */

	/*
	 * vector<int> vecint = { 1, 1, 1 };
	 * Enumerator en(
	 *     vecint.begin(), vecint.end(), 7,
	 *     [](vector<int>::iterator it)->void {
	 *         *it += 2;
	 *     }
	 * );
	 * en( [&]() { cout << vecint << endl; return false; } );
	 */

	/*
	 * return 0;
	 */

	int testc = readi();

	string s, e;
	for (int i = 0; i < testc; ++i)
	{
		readi();
		cin >> s;

		for (int j = 1; true; ++j)
		{
			e = string(j, 'a');
			Enumerator en(e.begin(), e.end(), 'z'+1);
			if (en([&]() { return s.find(e) == s.npos; }))
				break;
		}

		cout << e << endl;
	}


	return 0;
}





// end
