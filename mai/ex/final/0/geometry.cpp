#include <cmath>







// TYPES
typedef long double ldouble;

typedef struct
{
	ldouble x, y;
} Point, Vector;


/*
 * Представляет из себя прямую, заданную 
 * уравнением: a*x + b*y = c
 */
typedef struct
{
	ldouble a, b, c;
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
constexpr ldouble const ALPHA = 0.000001;







// ПРОСТЕЙШЕЕ
inline ldouble distance(Point a, Point b)
{
	return hypot( b.x - a.x, b.y - a.y );
}


inline Vector tovector(Point b, Point e)
{
	return { e.x - b.x, e.y - b.y };
}


inline Vector operator-(Point e, Point b)
{
	return { e.x - b.x, e.y - b.y };
}


inline ldouble length(Vector v)
{
	return sqrt( v.x*v.x + v.y*v.y );
}







// ПРОИЗВЕДЕНИЯ ВЕКТОРОВ
inline ldouble scalar(Vector a, Vector b)
{
	return a.x*b.x + a.y*b.y;
}

inline ldouble skew(Vector a, Vector b)
{
	return a.x*b.y - a.y*b.x;
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
inline ldouble cos(Vector a, Vector b)
{
	return 
		(ldouble)(a.x*b.x + a.y*b.y) /
		( length(a) * length(b) );
}


inline ldouble anglew(Vector a, Vector b)
{
	return acos(cos(a, b));
}



inline ldouble sin(Vector a, Vector b)
{
	return
		(ldouble)(a.x*b.y - a.y*b.x) /
		( length(a) * length(b) );
}


inline ldouble angled(Vector a, Vector b)
{
	return asin(sin(a, b));
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
		s.a = (ldouble)(pp.y - p.y) / (p.x - pp.x);
	}
	else
	{
		s.a = 1.0;
		s.b = (ldouble)(p.x - pp.x) / (pp.y - p.y);
	}
	s.c = p.x + s.b*p.y;
	return s;
}



/*
 * Находит точку пересечения прямых;
 * если такой не существует (т.е. если
 * прямые параллельны), возвращает
 * точку { NAN, NAN }; чтобы проверить,
 * является ли ldouble NAN выполните
 * проверку: NAN == NAN — она всегда
 * ложна
 */
inline Point cross(Straight s, Straight ss)
{
	ldouble const temp = s.a*ss.b - ss.a*s.b;
	if( fabs(temp) < ALPHA )
		return { NAN, NAN };
	return {
		-(ldouble)( s.b*ss.c - ss.b*s.c ) / temp,
		(ldouble)( s.a*ss.c - ss.a*s.c ) / temp
	};
}



/*
 * Проверяет, принадлежит ли точка
 * прямой (1-ая функция), отрезку (2-ая)
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
			1.0, -(ldouble)s.a/s.b, 
			p.x - (ldouble)s.a/s.b*p.y
		};
}







// РАССТОЯНИЯ
inline ldouble distance_to_straight(Point p, Point a, Point b)
{
	return fabs(skew(b-a, p-a)) / distance(a, b);
}

ldouble distance_to_straight(Point p, Straight s)
{
	Straight perp = perpend(s, p);
	Point const crp = cross(s, perp);
	return distance(p, crp);
}

ldouble distance_to_segment(Point p, Point a, Point b)
{
	return
		scalar(b-a, p-a) < -ALPHA ? distance(a, p) :
		scalar(a-b, p-b) < -ALPHA ? distance(b, p) :
		distance_to_straight(p, a, b);
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
ldouble square(ldouble a, ldouble b, ldouble c)
{
	ldouble const p = (a + b + c) / 2.0;
	return sqrt(
		p * (p - a) * (p - b) * (p - c)
	);
}

inline ldouble square(Point a, Point b, Point c)
{
	return square(
		distance(a, b),
		distance(b, c),
		distance(c, a)
	);
}

ldouble square(Point const *vers, int n)
{
	ldouble sum = 0.0;
	for(int i = 0; i < n; ++i)
	{
		sum +=
			( vers[i].y + vers[ (i+1)%n ].y ) / 2.0 *
			( vers[ (i+1)%n ].x - vers[i].x );
	}
	return fabs(sum);
}







// ОКРУЖНОСТИ
/*
 * Определяет, сколько общих точек
 * имеют окружности
 */
int iscross(Point c1, ldouble r1, Point c2, ldouble r2)
{
	ldouble const sql =
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
