#ifndef QUIX_GEOMETRY_STRAIGHT_HPP
#define QUIX_GEOMETRY_STRAIGHT_HPP

#include <cmath>
#include <type_traits>
#include <utility>

#include "geometry_point.hpp"





/*
 *  Функции, предоставляемые классом Straight:
 */





namespace quix
{










template<typename T> 
struct Straight
{
	// types
	typedef T value_type;



	// data-members
	value_type a, b, c;
	
	
	
	// methods
	value_type x(value_type y) const
	{
		return fabs(a) < ALPHA ? NAN : -(b*y + c)/a;
	}

	value_type y(value_type x) const
	{
		return fabs(b) < ALPHA ? NAN : -(a*y + c)/b;
	}





	// properties
	inline Vector<value_type> dir() const
	{
		return Vector<value_type>{-b, a};
	}

	inline Vector<value_type> norm() const
	{
		return Vector<value_type>{a, b};
	}
	
	
	
	template<typename U>
	inline Point<decltype(T()*U())> cross(
		Straight<U> const &ss
	) const
	{
		decltype(T()*U()) const temp = a*ss.b - ss.a*b;
		return fabs(temp) < ALPHA ? 
			Point<decltype(T()*U())>{ NAN, NAN } :
			Point<decltype(T()*U())>{
				( b*ss.c - ss.b*c ) / temp,
				( -a*ss.c + ss.a*c ) / temp
			};
	}



	template<typename U>
	inline Straight<decltype(T()*U())> parallel(
		Point<U> const &p
	) const
	{
		return { a, b, -(a*p.x + b*p.y) };
	}


	template<typename U>
	inline Straight<decltype(T()*U())> perpend(
		Point<U> const &p
	) const
	{
		return { -b, a, -(-b*p.x + a*p.y) };
	}
	
	
	
	template<typename U>
	inline bool isparallel(Straight<U> const &s) const
	{
		return fabs(a*s.b - s.a*b) < ALPHA;
	}

	template<typename U>
	inline bool isperpend(Straight<U> const &s) const
	{
		auto const n = norm();
		return fabs(n.a*s.b - s.a*n.b) < ALPHA;
	}
	
	
	
	inline Straight &normalize() // CHECK double
	{
		value_type const len = norm().len();
		if(c > ALPHA)
			len = -len;
		a /= len;
		b /= len;
		c /= len;
		return *this;
	}

	inline Straight normalized() const // CHECK double
	{
		ldouble const len = norm().len();
		if(c > ALPHA)
			len = -len;
		return { a/len, b/len, c/len };
	}
	
	
	
	
	
	// with other
	template<typename U>
	inline ldouble dis(Point<U> const &p) const
	{
		return dis( p, cross(*this, prepend(p)) );
	}

	template<typename U>
	inline ldouble dis(Straight<U> const &s) const
	{
		auto p = cross(s);
		return p.x == p.x ? 0.0L :
			dis( Point<decltype(T()*U())>(0, y(0)) );
	}





	template<typename U>
	inline bool isbelong(Point<U> const &p)
	{
		return fabs(a*p.x + b*p.y + c) < ALPHA;
	}
	
	
	
	
	
	// operator
	template<typename U>
	bool operator==(Straight<U> const &s) const // CHECK normalize
	{
		auto lhs = normalized();
		auto rhs = s.normalized();
		return
			fabs(lhs.a - rhs.a) < ALPHA &&
			fabs(lhs.b - rhs.b) < ALPHA &&
			fabs(lhs.c - rhs.c) < ALPHA;
	}





	// help
	template<class Ostream>
	Ostream &print( Ostream &os ) const
	{
		os << "(" << a << ", " << b << " : " << "0, " << -c/b << ")";
		return os;
	}
};

template<class Ostream, typename T>
inline Ostream &operator<<( Ostream &os, Straight<T> const &toprint )
{
	toprint.print(os);
	return os;
}










// --------- ПРОСТЕЙШЕЕ ---------
/*
 * Находит прямую, проходящую через
 * обе точки; предполагается, что
 * точки различны
 */
template<typename T, typename U>
Straight<decltype(T()*U())> tostrai(
	Point<T> p, Point<U> pp
)
{
	Straight<decltype(T()*U())> s;
	s.a = p.y - pp.y;
	s.b = pp.x - p.x;
	s.c = -(s.a*p.x + s.b*p.y);
	return s;
}

template<typename T, typename U>
Straight<decltype(T()*U())> vtostrai(
	Vector<T> v, Point<U> p
)
{
	Straight<decltype(T()*U())> s;
	s.a = -v.y;
	s.b = v.x;
	s.c = -(s.a*p.x + s.b*p.y);
	return s;
}





template<typename T>
inline Straight<T> normalized(Straight<T> const &s)
{
	return s.normalized();
}

template<typename T>
inline Straight<T> &normalize(Straight<T> *s)
{
	return s->normalize();
}









// ------------------- ПРОВЕРКИ ---------------------
/*
 * Проверяет, принадлежит ли точка
 * прямой (1-ая функция), отрезку (2-ая)
 */
template<typename T, typename U>
inline bool isbelong(Point<T> p, Straight<U> s)
{
	return s.isbelong(p);
}


template<typename T, typename U>
bool isbelongptoseg(Point<T> p, Point<U> a, Point<U> b)
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










// ----- ПАРАЛЛЕЛЬНОСТЬ/ПЕРЕПЕНДИКУЛЯРНОСТЬ -----
/*
 * Строит прямую, параллельную/перпендикулярную
 * данной и проходяющую через данную точку
 */
template<typename T, typename U>
inline bool isparallel(
	Straight<T> const &lhs,
	Straight<U> const &rhs
)
{
	return lhs.isparallel(rhs);
}

template<typename T, typename U>
inline bool isperpend(
	Straight<T> const &lhs,
	Straight<T> const &rhs
)
{
	return lhs.isperpend(rhs);
}



template<typename T, typename U>
inline Straight<decltype(T()*U())> parallel(
	Straight<T> s, Point<U> p
)
{
	return s.parallel(p);
}


template<typename T, typename U>
inline Straight<decltype(T()*U())> perpend(
	Straight<T> s, Point<U> p
)
{
	return s.perpend(p);
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
template<typename T, typename U>
inline Point<decltype(T()*U())> cross(
	Straight<T> s, Straight<U> ss
)
{
	return s.cross(ss);
}










// ------------------ РАССТОЯНИЯ --------------------
template<typename T, typename U>
inline ldouble disptostrai(Point<T> p, Point<U> a, Point<U> b)
{
	return fabs(skew(b-a, p-a)) / dis(a, b);
}

template<typename T, typename U>
inline ldouble dis(Straight<T> s, Point<U> p)
{
	return s.dis(p);
}

template<typename T, typename U>
inline ldouble dis(Point<U> p, Straight<T> s)
{
	return s.dis(p);
}



template<typename T, typename U>
inline ldouble disptoseg(Point<T> p, Point<U> a, Point<U> b)
{
	return
		scalar(b-a, p-a) < -ALPHA ? dis(a, p) :
		scalar(a-b, p-b) < -ALPHA ? dis(b, p) :
		disptostrai(p, a, b);
}

template<typename T, typename U>
ldouble dissegtoseg(
	Point<T> a, Point<T> b,
	Point<U> m, Point<U> n
)
{
	Straight<ldouble> s, ss;
	Point<ldouble> p;
	
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
		res = std::min(res, disptoseg(b, m, n));
		res = std::min(res, disptoseg(m, a, b));
		res = std::min(res, disptoseg(n, a, b));
		return res;
	}
}










}





#endif
