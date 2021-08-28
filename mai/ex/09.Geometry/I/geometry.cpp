#include <cmath>







// TYPES
typedef struct
{
	double x, y;
} Point, Vector;


/*
 * Представляет из себя прямую, заданную 
 * уравнением: a*x + b*y = c
 */
typedef struct
{
	double a, b, c;
} Straight;







// OBJECTS
/*
 * Используется для сравнения на равенство и
 * неравество с учётом погрешности в вычислениях:
 * 	a == b	-> fabs(a - b) < ALPHA
 * 	a != b  -> fabs(a - b) >= ALPHA
 *
 * 	a < b	-> a - b < -ALPHA
 * 	a > b	-> b - a < -ALPHA
 *
 * 	a <= b	-> a - b < ALPHA
 * 	a >= b	-> b - a < ALPHA
 */
constexpr double const ALPHA = 0.00001;







// ПРОСТЕЙШЕЕ
inline double distance(Point a, Point b)
{
	return sqrt(
		(b.x - a.x) * (b.x - a.x) +
		(b.y - a.y) * (b.y - a.y)
	);
}


inline Vector tovector(Point b, Point e)
{
	return { e.x - b.x, e.y - b.y };
}


inline Vector operator-(Point e, Point b)
{
	return { e.x - b.x, e.y - b.y };
}


inline double length(Vector v)
{
	return sqrt( v.x*v.x + v.y*v.y );
}







// УГЛЫ
/*
 * 1.cos — вычисляет косинус угола между векторами:
 * от 0-я до 180-ти градусов; показывает насколько
 * угол широк
 *
 * 2.anglew — вычисляет угол по косинусу
 *
 * 3.sin — вычисляет синус угла между векторами,
 * учитывая направление; оно положительно, если
 * против часовой стрелки, иначе — отрицательно
 *
 * 4.angled — вычисляет угол по синусу от -90 до 90,
 * учитывая направление
 */
inline double cos(Vector a, Vector b)
{
	return 
		(double)(a.x*b.x + a.y*b.y) /
		( length(a) * length(b) );
}


inline double anglew(Vector a, Vector b)
{
	return acos(cos(a, b));
}



inline double sin(Vector a, Vector b)
{
	return
		(double)(a.x*b.y - a.y*b.x) /
		( length(a) * length(b) );
}


inline double angled(Vector a, Vector b)
{
	return asin(sin(a, b));
}







// ПЛОЩАДИ
/*
 * Вычисляет площадь треугольника по
 * заданным сторонам или точкам вершин,
 * используя формулу Герона; вычисляет
 * площадь простого (не пересекающего
 * себя) многоугольника по заданным
 * вершинам
 */
double square(double a, double b, double c)
{
	double const p = (a + b + c) / 2.0;
	return sqrt(
		p * (p - a) * (p - b) * (p - c)
	);
}

inline double square(Point a, Point b, Point c)
{
	return square(
		distance(a, b),
		distance(b, c),
		distance(c, a)
	);
}

double square(Point const *vers, int n)
{
	double sum = 0.0;
	for(int i = 0; i < n; ++i)
	{
		sum +=
			( vers[i].y + vers[ (i+1)%n ].y ) / 2.0 *
			( vers[ (i+1)%n ].x - vers[i].x );
	}
	return fabs(sum);
}







// ПРЯМЫЕ
/*
 * Находит прямую, проходящую через
 * обе точки; предполагается, что
 * точки различны
 */
Straight tostraight(Point p, Point pp)
{
	Straight s;
	if( fabs(p.y - pp.y) < ALPHA )
	{
		s.b = 1.0;
		s.a = (double)(pp.y - p.y) / (p.x - pp.x);
	}
	else
	{
		s.a = 1.0;
		s.b = (double)(p.x - pp.x) / (pp.y - p.y);
	}
	s.c = p.x + s.b*p.y;
	return s;
}



/*
 * Находит точку пересечения прямых;
 * если такой не существует (т.е. если
 * прямые параллельны), возвращает
 * точку { NAN, NAN }; чтобы проверить,
 * является ли double NAN выполните
 * проверку: NAN == NAN — она всегда
 * ложна
 */
inline Point cross(Straight s, Straight ss)
{
	if( fabs(s.a*ss.b - ss.a*s.b) < ALPHA )
		return { NAN, NAN };
	return {
		-(double)( s.b*ss.c - ss.b*s.c ) /
			(s.a*ss.b - ss.a*s.b),
		(double)( s.a*ss.c - ss.a*s.c ) /
			(s.a*ss.b - ss.a*s.b)
	};
}



/*
 * Проверяет, принадлежит ли точка
 * прямой, отрезку
 */
inline bool isbelong(Point p, Straight s)
{
	return fabs(s.a*p.x + s.b*p.y - s.c) < ALPHA;
}


inline bool isbelong(Point p, Point a, Point b)
{
	return
		// x1 <= x <= x2
		std::min(a.x, b.x) - p.x < ALPHA &&
		p.x - std::max(a.x, b.x) < ALPHA &&

		// y1 <= y <= y2
		std::min(a.y, b.y) - p.y < ALPHA && 
		p.y - std::max(a.y, b.y) < ALPHA &&

		// on a straight
		isbelong(p, tostraight(a, b));
}



/*
 * Строит прямую, параллельную/перпендикулярную
 * данной и проходяющую через данную точку
 */
inline Straight parallel(Straight s, Point p)
{
	return { s.a, s.b, s.a*p.x + s.b*p.y };
}


inline Straight perpend(Straight s, Point p)
{
	return 
		fabs(s.a) < ALPHA ? Straight{ 1.0, 0.0, p.x } :
		fabs(s.b) < ALPHA ? Straight{ 0.0, 1.0, p.y } :
		Straight{
			1.0, -(double)s.a/s.b, 
			p.x - (double)s.a/s.b*p.y
		};
}







// ОКРУЖНОСТИ
/*
 * Определяет, сколько общих точек
 * имеют окружности
 */
int iscross(Point c1, double r1, Point c2, double r2)
{
	double const sql =
		(c2.x - c1.x) * (c2.x - c1.x) +
		(c2.y - c1.y) * (c2.y - c1.y);

	if( fabs( sql - (r1 + r2)*(r1 + r2) ) < ALPHA )
		return 1;
	if(
		sql - (r1 + r2)*(r1 + r2) < ALPHA &&
		(r1 - r2)*(r1 - r2) - sql < ALPHA
	)
		return 2;
	return 0;
}







// end
