#include <algorithm>
#include <iostream>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	/*
	 * массивы всех значений и вероятностей;
	 * их длинна
	 */
	int n;
	int *vals, *probs;
	
	
	
	// input
	/*
	 * считываем
	 */
	scanf("%i", &n);
	vals = new int[n];
	probs = new int[n];

	for(auto *b = vals, *e = vals+n; b != e; ++b)
		scanf("%i", b);

	for(auto *b = probs, *e = probs+n; b != e; ++b)
		scanf("%i", b);
	
	
	
	// solve
	/*
	 * сортируем в порядке возрастания, чтобы
	 * сопоставить меньшие значения с меньшей
	 * вероятностью выпадения и соответственно
	 * большие значения сопоставить с большей
	 * вероятностью выпадения
	 */
	sort(vals, vals+n);
	sort(probs, probs+n);

	/*
	 * будем одновременно находить и сумму
	 * произведений и сумму всех вероятностей;
	 * заметим, что эти суммы помещаются в 
	 * long long
	 */
	llong sum = 0;
	llong probssum = 0;
	for(int i = 0; i < n; ++i)
		sum += (llong)vals[i]*probs[i],
		probssum += probs[i];

	/*
	 * не забываем перести в double, т.к.
	 * число скорее всего получится дробным, а
	 * нам нужна точность до шестого знака;
	 */
	double res = (double)sum/(double)probssum;
	
	
	
	// output
	printf("%.7f\n", res);



	return 0;
}





// end
