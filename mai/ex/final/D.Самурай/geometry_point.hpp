#ifndef QUIX_GEOMETRY_POINT_HPP
#define QUIX_GEOMETRY_POINT_HPP

#include <cmath>
#include <type_traits>
#include <utility>

#include <quix/Type.hpp>





/*
 * Обозначения
 *    P/V - экземпляр класса Point/Vector
 *    n — число
 *
 *
 *
 * ----- СОЗДАНИЕ, КОНВЕРТАЦИЯ
 * Методы
 *    * operator Point<U>()
 *    * operator std::pair<U, U>()
 *    * Point<T> to<T>()
 *    * std::pair<U, U> topair<U>()
 *
 * Свободные функции
 *    * tovec(Point b, Point e)
 *    * можно также использовать operator-
 *
 *
 *
 *
 *
 * ----- ОПЕРАТОРЫ
 *    * Немодифицирующие
 *        P * n, P / n, P + P, P - P
 *    * Модифицирующие
 *        P *= n, P /= n, P += p, P -= p
 *
 *    Немодифицирующие операторы возвращают точку широчайшего
 *    типа из тех, что имели операнды, т.е. decltype(T()*U())
 *
 *
 *
 *
 *
 * ----- СВОЙСТВА
 *    * dis(P, P)...расстояние от точки до точки
 *    * len(V)......длинна (модуль) вектора
 *    * hypsq(V)....длинна вектора в квадрате (не извлекается корень;
 *                  удобно, когда используются целые числа)
 *    * norm(V).....возвращает нормальный (перпендикулярный) вектор данному
 *    * unit(V).....возвращает единичный вектор от V
 *    * tounit(V)...меняет вектор V на единичный от него (работает корректно,
 *                  лишь когда тип координат — вещественные числа)
 *
 *    Все эти свойства также доступны в качестве методов класса;
 *    в этом случае первый аргумент опускается.
 *
 *    Функции, где могут возникнут нецелые значения (dis, len, unit)
 *    возвращают, как если бы тип координат был long double
 *
 *
 *
 *
 *
 * ----- УГЛЫ
 *    * cos(V, V)......косинус угла между векторами
 *    * sin(V, V)......синус угла между векторами
 *    * anglew(V, V)...угол (в радианах) от 0 до PI
 *    * angled(V, V)...угол (в радианах) от -PI/2 до PI/2;
 *                     учитывается направление: положительным считается
 *                     против часовой стрелки, по — отрицательным
 *
 *    Функции возвращают тип long double
 *    
 *
 *
 *
 *
 * ----- ПРОИЗВЕДЕНИЯ
 *    * scalar(V, V)...скалярное произведение; возвращает число
 *    * skew(V, V).....косое произведение; возвращает число 
 *
 *    Функции возвращают тип, какой был в V
 *
 *
 *
 *
 *
 * ----- ДРУГОЕ
 *    * operator<<.....выводит в поток '(x, y)'
 *    * makep(C).......создаёт из любого класса, у которого есть поля x, y
 *    * makep(x, y)....создаёт точку из x, y
 *    * makep(pair)....создаёт точку из std::pair<U, U>
 *    
 *    Во всех функциях makep возможно указать тип для Point
 *    через первый шаблонный параметр функции: makep<double>(...)
 *
 *
 *
 *
 *
 */





namespace quix
{





	
	
	
	

// -------------------- В ПОМОЩЬ --------------------
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

constexpr long double const ALPHA = 1e-6;










// -------- ТОЧКА/ВЕКТОР --------
template<typename T>
struct Point
{
	// types
	typedef T value_type;
	


	// data-members
	value_type x, y;
	
	
	


	// methods
	template<class P>
	Point &operator=(P const &p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}
	
	
	// conversion
	template<class P>
	inline operator P() const
	{
		P p;
		p.x = x;
		p.y = y;
		return p;
	}

	template<typename U>
	inline operator std::pair<U, U>() const
	{
		return std::pair<U, U>(x, y);
	}

	template<class P>
	inline P to() const
	{
		P p;
		p.x = x;
		p.y = y;
		return p;
	}

	template<typename U = value_type>
	inline std::pair<U, U> topair() const
	{
		return std::pair<U, U>{ x, y };
	}





	// geometry
	template<typename P>
	inline long double dis(P const &p) const
	{
		return std::hypot(p.x-x, p.y-y);
	}

	inline long double len() const
	{
		return std::hypot(x, y);
	}

	inline value_type hypsq() const
	{
		return x*x + y*y;
	}

	inline Point norm() const
	{
		return { -y, x };
	}

	inline Point<long double> unit() const
	{
		long double const temp = len();
		return { x/temp, y/temp };
	}

	inline Point &tounit()
	{
		long double const temp = len();
		x /= temp;
		y /= temp;
		return *this;
	}





	// print
	template<class Ostream>
	Ostream &print( Ostream &os ) const
	{
		os << "(" << x << ", " << y << ")";
		return os;
	}



};

template<typename T>
using Vector = Point<T>;









// --------- ОПЕРАТОРЫ ----------
	// Point and Number
template<typename T, typename U>
inline Point<decltype(T()*U())> operator*(
	Point<T> const &lhs,
	U rhs
)
{
	return {lhs.x*rhs, lhs.y*rhs};
}


template<typename T, typename U>
inline Point<decltype(T()/U())> operator/(
	Point<T> const &lhs,
	U rhs
)
{
	return { lhs.x/rhs, lhs.y/rhs };
}



	// Point and Point
template<typename T, typename U>
inline bool operator==(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}


template<typename T, typename U>
inline bool operator!=(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return lhs.x != rhs.x || lhs.y != rhs.y;
}


template<typename T, typename U>
inline Point<decltype(T()+U())> operator+(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return {lhs.x+rhs.x, lhs.y+rhs.y};
}


template<typename T, typename U>
inline Point<decltype(T()-U())> operator-(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return {lhs.x-rhs.x, lhs.y-rhs.y};
}







	// mod Point and Number
template<typename T, typename U>
inline Point<T> &operator*=(
	Point<T> &lhs,
	U rhs
)
{
	lhs.x *= rhs;
	lhs.y *= rhs;
	return lhs;
}


template<typename T, typename U>
inline Point<T> &operator/=(
	Point<T> &lhs,
	U rhs
)
{
	lhs.x /= rhs;
	lhs.y /= rhs;
	return lhs;
}



	// mod Point and Point
template<typename T, typename U>
inline Point<T> &operator+=(
	Point<T> &lhs,
	Point<U> const &rhs
)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}


template<typename T, typename U>
inline Point<T> &operator-=(
	Point<T> &lhs,
	Point<U> const &rhs
)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return lhs;
}










// --------- СВОЙСТВА ---------
template<typename T, typename U>
inline Vector<decltype(T()-U())> tovec(Point<T> b, Point<U> e)
{
	return e-b;
}


template<typename T, typename U>
inline long double dis(Point<T> a, Point<U> b)
{
	return a.dis(b);
}


template<typename T>
inline long double len(Vector<T> v)
{
	return v.len();
}


template<typename T>
inline T hypsq(Vector<T> a)
{
	return a.x*a.x + a.y*a.y;
}


template<typename T>
inline Vector<T> norm(Vector<T> vec)
{
	return vec.norm();
}

template<typename T>
inline Vector<T> unit(Vector<T> vec)
{
	return vec.unit();
}

template<typename T>
inline Vector<T> &tounit(Vector<T> &vec)
{
	return vec.tounit();
}










// ------------ УГЛЫ ------------
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
template<typename T, typename U>
inline long double cos(Vector<T> a, Vector<U> b)
{
	return 
		(long double)(a.x*b.x + a.y*b.y) /
		( len(a) * len(b) );
}


template<typename T, typename U>
inline long double anglew(Vector<T> a, Vector<U> b)
{
	return acos(cos(a, b));
}



template<typename T, typename U>
inline long double sin(Vector<T> a, Vector<U> b)
{
	return
		(long double)(a.x*b.y - a.y*b.x) /
		( len(a) * len(b) );
}


template<typename T, typename U>
inline long double angled(Vector<T> a, Vector<U> b)
{
	return asin(sin(a, b));
}










// -------- ПРОИЗВЕДЕНИЯ --------
template<typename T, typename U>
inline decltype(T()*U()) scalar(Vector<T> a, Vector<U> b)
{
	return a.x*b.x + a.y*b.y;
}

template<typename T, typename U>
inline decltype(T()*U()) skew(Vector<T> a, Vector<U> b)
{
	return a.x*b.y - a.y*b.x;
}










// ---------- ДРУГОЕ ------------
// print
template<class Ostream, typename T>
inline Ostream &operator<<(
	Ostream &os,
	Point<T> const &toprint 
)
{
	 return toprint.print(os);
}





// make 
template<typename T = void, class C>
inline auto makep(C const &from)
{
	Point< typename IF<
		std::is_same<T, void>::value,
		decltype(C::x), T
	>::value_type > p;

	p.x = from.x;
	p.y = from.y;

	return p;
}

template<typename T = void, typename U>
inline auto makep(U x, U y)
{
	Point< typename IF<
		std::is_same<T, void>::value,
		U, T
	>::value_type > p;

	p.x = x;
	p.y = y;

	return p;
}

template<typename T = void, typename U>
inline auto makep(std::pair<U, U> const &pair)
{
	Point< typename IF<
		std::is_same<T, void>::value,
		U, T
	>::value_type > p;

	p.x = pair.first;
	p.y = pair.second;

	return p;
}







// typedefs
typedef Point<char> PointC;
typedef Point<int> PointI;
typedef Point<long long> PointLL;
typedef Point<unsigned> PointU;
typedef Point<unsigned long long> PointULL;

typedef Point<float> PointF;
typedef Point<double> PointD;
typedef Point<long double> PointLD;







}





#endif
