#include <cmath>
#include <iostream>


using namespace std;





// function
/*
 * функция, которая находит расстояние между
 * двумя точками в целочисленных координатах
 */
double distance(int x, int y, int xx, int yy)
{
	return sqrt( 
		(xx-x)*(xx-x) +
		(yy-y)*(yy-y)
	);
}





// main
int main( int argc, char *argv[] )
{
	/*
	 * стуктура состояния, которая
	 * содержит уже пройденное расстояние
	 * и точку, в которой находится лазер
	 */
	typedef struct
	{
		double dis;
		int x, y;
	} Stage;


	int n;
	/*
	 * состояния: первое, в котором лазер
	 * проходит из начала в конец отрезка и
	 * останавливается в точке конца отрезка;
	 * второе, в котором лазер проходит из
	 * конца в начало и останавливается в
	 * начале отрезка; и третье — временное,
	 * чтобы сохранить промежуточный вариант
	 * между вычислениями состояний текущего
	 * шага и следующего
	 */
	Stage fst, sst, tempst;
	int x, y, xx, yy;
	
	



	// input
	/*
	 * считываем кол-во отрезков
	 */
	scanf("%i", &n);



		// first case
	/*
	 * считываем первый отрезок (он всегда есть),
	 * устанавливаем состояния
	 */
	scanf(
		"%i%i%i%i",
		&x, &y, &xx, &yy
	);
	fst.dis = sst.dis = distance(x, y, xx, yy);
	/*
	 * координаты на конце
	 */
	fst.x = xx, fst.y = yy;
	/*
	 * координаты на начале
	 */
	sst.x = x, sst.y = y;



		// other cases
	for(int i = 1; i < n; ++i)
	{
		scanf(
			"%i%i%i%i",
			&x, &y, &xx, &yy
		);

		// first stage (end is e)
		/*
		 * сначала попробуем текущий отрезок пройти
		 * от начала до конца — тогда выберем такое
		 * предыдущее состояние, чтобы пройденное
		 * расстояние было наименьшим
		 */
		if(
			sst.dis + distance(sst.x, sst.y, x, y) <
			fst.dis + distance(fst.x, fst.y, x, y)
		)
		{
			/*
			 * выбираем соответствующий вариант; сохраняем
			 * во временную переменную, т.к. fst нам ещё
			 * нужен для вычисления второго состояния
			 */
			tempst.dis = sst.dis +
				distance(sst.x, sst.y, x, y) +
				distance(x, y, xx, yy);
			tempst.x = xx, tempst.y = yy;
		}
		else
		{
			tempst.dis = fst.dis +
				distance(fst.x, fst.y, x, y) +
				distance(x, y, xx, yy);
			tempst.x = xx, tempst.y = yy;
		}



		// second stage (end is b)
		/*
		 * второе состояние, когда мы проходим из
		 * конца в начало; действуем соответственно
		 */
		if(
			sst.dis + distance(sst.x, sst.y, xx, yy) <
			fst.dis + distance(fst.x, fst.y, xx, yy)
		)
		{
			sst.dis = sst.dis +
				distance(sst.x, sst.y, xx, yy) +
				distance(xx, yy, x, y);
			sst.x = x, sst.y = y;
		}
		else
		{
			sst.dis = fst.dis +
				distance(fst.x, fst.y, xx, yy) +
				distance(xx, yy, x, y);
			sst.x = x, sst.y = y;
		}



		/*
		 * не забываем установить fst 
		 */
		fst = tempst;
	}
	
	
	
	// output
	/*
	 * Выводим наилучший из вариантов
	 */
	printf("%.7f\n", min(fst.dis, sst.dis));



	return 0;
}





// end
