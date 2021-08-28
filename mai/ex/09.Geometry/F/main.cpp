#include <cmath>
#include <iostream>







#include <cmath>







// TYPES
typedef long double ldouble;

typedef struct
{
	ldouble x, y;
} Point, Vector;


/*
 * Представляет из себя прямую, заданную 
 * уравнением: a*x + b*y + c = 0
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


inline Vector tovec(Point b, Point e)
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
	s.a = p.y - pp.y;
	s.b = pp.x - p.x;
	s.c = -(s.a*p.x + s.b*p.y);
	return s;
}

inline bool operator==(
	Straight const &lhs,
	Straight const &rhs
)
{
	return
		fabs(lhs.a - rhs.a) < ALPHA &&
		fabs(lhs.b - rhs.b) < ALPHA &&
		fabs(lhs.c - rhs.c) < ALPHA;
}

inline bool isparallel(
	Straight const &lhs,
	Straight const &rhs
)
{
	return
		fabs(lhs.a - rhs.a) < ALPHA &&
		fabs(lhs.b - rhs.b) < ALPHA;
}



inline Straight normalize(Straight const &s)
{
	ldouble const n = length(Vector{s.a, s.b});
	Straight ss{ s.a/n, s.b/n, s.c/n };
	if( ss.a < -ALPHA )
		ss.a = -ss.a,
		ss.b = -ss.b,
		ss.c = -ss.c;
	return ss;
}

inline void normalize(Straight *s)
{
	ldouble const n = length(Vector{s->a, s->b});
	*s = Straight{s->a/n, s->b/n, s->c/n};
	if( s->a < -ALPHA )
		s->a = -s->a,
		s->b = -s->b,
		s->c = -s->c;
	return;
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
		(ldouble)( s.b*ss.c - ss.b*s.c ) / temp,
		(ldouble)( -s.a*ss.c + ss.a*s.c ) / temp
	};
}



/*
 * Проверяет, принадлежит ли точка
 * прямой (1-ая функция), отрезку (2-ая)
 */
inline bool isbelong(Point p, Straight s)
{
	return fabs(s.a*p.x + s.b*p.y + s.c) < ALPHA;
}


bool isbelong(Point p, Point a, Point b)
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
	return { s.a, s.b, -(s.a*p.x + s.b*p.y) };
}


inline Straight perpend(Straight s, Point p)
{
	return { -s.b, s.a, -(-s.b*p.x + s.a*p.y) };
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

ldouble distance_segment_to_segment(
	Point a, Point b,
	Point m, Point n
)
{
	Straight s, ss;
	Point p;
	
	s = tostraight(a, b);
	ss = tostraight(m, n);

	p = cross(s, ss);
	if(p.x == p.x && isbelong(p, a, b) && isbelong(p, m, n))
	{
		return 0.0L;
	}
	else
	{
		ldouble res = distance_to_segment(a, m, n);
		res = std::min(res, distance_to_segment(b, m, n));
		res = std::min(res, distance_to_segment(m, a, b));
		res = std::min(res, distance_to_segment(n, a, b));
		return res;
	}
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
	return skew(tovec(a, b), tovec(a, c)) / 2.0L;
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


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int tests;
	
	
	
	// solve
	scanf("%i", &tests);

	Point a, b, m, n;
	for(int test = 0; test < tests; ++test)
	{
		scanf(
			"%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf",
			&a.x, &a.y,
			&b.x, &b.y,
			&m.x, &m.y,
			&n.x, &n.y
		);


		printf("%.9Lf\n", distance_segment_to_segment(a, b, m, n));
	}



	return 0;
}





// end
