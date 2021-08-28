#include <algorithm>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	int m, n;
	int *a, *b;
	int l, r;
	
	
	
	// input
	/*
	 * считываем значения первой и второй кости, а также
	 * отрезок, в который сумма значений должна попасть
	 */
	scanf("%i%i", &m, &n);
	a = new int[m];
	b = new int[n];
	for(int i = 0; i < m; ++i)
		scanf("%i", a+i);
	for(int i = 0; i < n; ++i)
		scanf("%i", b+i);
	scanf("%i%i", &l, &r);



	// prepare
	/*
	 * будем сортировать наибольший массив, чтобы сэкономить
	 * время на линейном прохождении по оставшемуся, меньшему
	 * массиву
	 */
	if(n < m)
		swap(m, n),
		swap(a, b);
	sort(b, b+n);
	
	
	
	// solve
	// количество благопритяных исходов
	llong good = 0;
	{
		int *lower, *upper;
		for(int i = 0; i < m; ++i)
		{
			/*
			 * напомню, что lower_bound находит первый элемент,
			 * который больше или равен заданному, а upper_bound
			 * находит первый элемент, который строго больше
			 * заданного (если таковых нет, возвращается ссылка
			 * на элемент за концом заданного промежутка); таким
			 * образом мы находит полуинтервал [lower, upper),
			 * где lower указывает на первый входящий в отрезок
			 * [l, r] элемент, а upper — на первый элемент,
			 * который находится за (или равен) lower и не входит
			 * в отрезок [l, r]. Чтобы вычислить кол-во элементов
			 * в полуинтервале, достаточно вычесть начало из конца
			 */
			lower = lower_bound(b, b+n, l-a[i]);
			upper = upper_bound(b, b+n, r-a[i]);
			good += upper - lower;
		}
	}

	/*
	 * необходимо не забыть перевсти в double, иначе произойдёт
	 * целочисленное деление и резльтат будет равен нулю
	 */
	double const res = (double)good / ((llong)n*m);
	
	
	
	// output
	/*
	 * вывод с точностью до десятого знака
	 */
	cout.precision(10);
	cout << res << endl;



	return 0;
}





// end
