#include <iostream>
#include <queue>

#ifndef QUIX_FIELD_HPP
#define QUIX_FIELD_HPP

#include <cstring>
#include <iterator>
#include <type_traits>
#include <utility>

#ifndef QUIX_HELP_FUNCTION_HPP
#define QUIX_HELP_FUNCTION_HPP


#include <algorithm>
#include <string>
#include <vector>





namespace quix
{





// min, max element
template<typename T>
inline auto maxelement(T const &head)
{
	return head;
}

template<typename T, typename...Args>
inline auto maxelement(T const &head, Args const &...args)
{
	auto nextmax = maxelement(args...);
	return nextmax > head ? nextmax : head;
}

template<typename T>
inline auto minelement(T const &head)
{
	return head;
}

template<typename T, typename...Args>
inline auto minelement(T const &head, Args const &...args)
{
	auto nextmin = minelement(args...);
	return nextmin < head ? nextmin : head;
}





// strings
	// cutzero
inline std::string cutzero(std::string const &s)
{
	auto pos = s.find_last_not_of('0');
	if(pos == s.npos)
		return s;
	return s[pos] == '.' ?
		s.substr( 0, pos+2 ) :
		s.substr( 0, pos+1 );
}

inline void cutzero(std::string *s)
{
	auto pos = s->find_last_not_of('0');
	if(pos == s->npos)
		return;
	(*s)[pos] == '.' ?
		s->erase(pos+2) :
		s->erase(pos+1);
	return;
}



	// cut space
inline void cutspace(std::string *s)
{
	auto b = s->find_first_not_of(" \t\n");
	if(b == std::string::npos)
	{
		*s = "";
		return;
	}
	*s = s->substr(
		b, s->find_last_not_of(" \t\n") - b + 1
	);
	return;
}

inline std::string cutspace(std::string const &s)
{
	auto b = s.find_first_not_of(" \t\n");
	if(b == std::string::npos)
		return "";
	return s.substr(
		b, s.find_last_not_of(" \t\n") - b + 1
	);
}



	// fills
inline void fills(std::string *s, int n)
{
	if((int)s->size() >= n)
		return;
	s->reserve(n);
	std::fill_n( std::back_inserter(*s), n-s->size(), ' ' );
	return;
}

inline std::string fills(std::string const &s, int n)
{
	if((int)s.size() >= n)
		return s;
	std::string cp = s;
	cp.reserve(n);
	std::fill_n( std::back_inserter(cp), n-cp.size(), ' ' );
	return cp;
}

inline std::string fills(std::string &&s, int n)
{
	if((int)s.size() >= n)
		return s;
	s.reserve(n);
	std::fill_n( std::back_inserter(s), n-s.size(), ' ' );
	return s;
}



	// other
void genkeys(
	std::vector<std::string> const &names,
	std::vector<std::string> &keys,
	bool letcase = false
);



	// Взято с: https://habr.com/ru/post/318962
std::string format(const char *fmt, ...);



/*
 * Вычленяет объекты из строки
 *   i — int
 *   l - long
 *   u - unsigned int
 *   f - float
 *   d - double
 *   s,w - std::string
 *   a — кладёт всю оставшуюся строку в std::string
 * тип вычленяемого объекта и их порядок получается из fmt;
 * fmt может выглядеть так: "iifs" — тогда сначала считается
 * int, затем ещё раз int, далее float и в конце std::string.
 * Всё это записывается в dat. Для вычленения используется
 * stringstream::operator>>(...)
 */
bool scan(
	std::string const &enter,
	char const *fmt,
	void **dat
);

inline bool scan(
	std::string const &enter,
	char const *fmt,
	std::vector<void *> dat
)
{
	return scan(enter, fmt, dat.data());
}





// other
inline int tape(int i, int max)
{
	return i < 0 ?
		max-1 - (-i-1)%max :
		i % max;
}





}





#endif

#ifndef QUIX_IOSTREAM_FUNCTION_HPP
#define QUIX_IOSTREAM_FUNCTION_HPP

#include <array>
#include <list>
#include <tuple>





namespace quix
{







// print functions
	// defult
template<class Ostream, typename T>
inline Ostream &print(Ostream &os, T const &t)
{
	os << t;
	return os;
}



	// for pointer
template<class Ostream, typename T>
inline Ostream &print(Ostream &os, T* t)
{
	os << '&' << *t;
	return os;
}



	// for pair
template<class Ostream, typename T, typename U>
inline Ostream &print(
	Ostream &os, std::pair<T, U> const &pair,
	std::string const &term = ", "
)
{
	print(
		print(
			os << "< ", pair.first
		) << term,
		pair.second
	) << " >";
	return os;
}



	// for vector
template<class Ostream, typename T>
Ostream &print(
	Ostream &os, std::vector<T> const &vec,
	std::string const &term = ", "
)
{
	os << "< ";
	if(!vec.empty()) {
		print(os, vec.front());
		for(auto b = vec.begin()+1, e = vec.end(); b != e; ++b) {
			print(os << term, *b);
		}
	}
	os << " >";
	return os;
}



	// for list
template<class Ostream, typename T>
Ostream &print(
	Ostream &os, std::list<T> const &l,
	std::string const &term = ", "
)
{
	os << "[ ";
	if(!l.empty()) {
		print(os, l.front());
		for(auto b = std::next(l.begin()), e = l.end(); b != e; ++b) {
			print(os << term, *b);
		}
	}
	os << " ]";
	return os;
}



	// for c-array
/*
 * template<class Ostream, typename T>
 * Ostream &print(
 *         Ostream &os, T *a, int n,
 *         std::string const &term = ", "
 * )
 * {
 *         if(!n)
 *                 return os;
 * 
 *         os << a[0];
 *         for(auto *b = a+1, *e = a+n; b != e; ++b)
 *                 os << term << *b;
 * 
 *         return os;
 * }
 */



	// by iterator
template<class Ostream, typename Iterator>
Ostream &print(
	Ostream &os, Iterator b, Iterator e,
	std::string const &term = ", "
)
{
	if(b == e)
		return os;

	os << *b;
	while(++b != e)
		os << term << *b;
}




	// for array
template<class Ostream, typename T, size_t N>
Ostream &print(
	Ostream &os, std::array<T, N> const &arr,
	std::string const &term = ", "
)
{
	static_assert(N > 0);

	os << "( " << arr[0];
	for(size_t i = 1; i < N; ++i) {
		print(os << term, arr[i]);
	}
	os << " )";
	return os;
}



	// for array
template<class Ostream, typename T, typename SizeType = int>
Ostream &print(
	Ostream &os, T const *arr, SizeType len,
	std::string const &term = ", "
)
{
	if(!len)
		return os << "(  )";
	T const *end = arr+len;
	os << "( " << *arr;
	while(++arr != end)
		os << term << *arr;
	return os << " )";
}



	// for matrix
template<class Ostream, class Matrix>
Ostream &print_matrix(
	Ostream &os,
	Matrix const &m, unsigned int w, unsigned int h,
	std::string const &elterm = "\t",
	std::string const &lineterm = "\n"
)
{
	for(unsigned int i = 0; i < h; ++i) {
		for(unsigned int j = 0; j < w; ++j) {
			print(os, m[i][j]) << elterm;
		}
		os << lineterm;
	}
	return os;
}





	// for tuples
template<class Ostream, int n, int max, typename...Args>
struct PRINT_TUPLE
{
	static Ostream &print(
		Ostream &os, std::tuple<Args...> const &tuple
	)
	{
		os << std::get<n-1>(tuple) << ", ";
		return PRINT_TUPLE<Ostream, n+1, max, Args...>::print(os, tuple);
	}
};



template<class Ostream, int max, typename...Args>
struct PRINT_TUPLE<Ostream, max, max, Args...>
{
	static Ostream &print(
		Ostream &os, std::tuple<Args...> const &tuple
	)
	{
		return os << std::get<max-1>(tuple);
	}
};



template<class Ostream, typename...Args>
Ostream &print(
	Ostream &os, std::tuple<Args...> const &tuple
)
{
	os << "[ ";
	quix::PRINT_TUPLE<
		Ostream, 1, sizeof...(Args), Args...
	>::print(os, tuple);
	os << " ]";
	return os;
}







// snan functions
	// for vector
template<class Istream, typename T>
Istream &scan(
	Istream &is, std::vector<T> &vec
)
{
	T input;
	while(is >> input)
		vec.push_back(input);
	return is;
}



	// for array
template<class Istream, typename T>
Istream &scan(
	Istream &is, T *arr, int size = -1, int *n = nullptr
)
{
	int i = 0;
	for(; i != size && is >> *arr; ++i, ++arr);
	if(n) *n = i;
	return is;
}


template<class Istream, typename T>
Istream &scan(
	Istream &is, T *arr, T *arrend, int *n = nullptr
)
{
	int an = 0;
	while(arr != arrend && is >> *arr)
	{
		++arr;
		++an;
	}
	if(n) *n = an;
	return is;
}







// write/read functions
template<class Ostream>
inline Ostream &writestr( Ostream &os, std::string const &str )
{
	int size = str.size();
	os.write( (char const *)&size, sizeof size );
	os.write( str.c_str(), sizeof(char)*size );
	return os;
}


template<class Istream>
inline Istream &readstr( Istream &is, std::string &str )
{
	int size = 0;
	is.read( (char *)&size, sizeof size );
	str.resize( size );
	is.read( const_cast<char*>(str.data()), sizeof(char)*size );
	return is;
}







}







// operators
	// vector
template<class Ostream, typename T>
inline Ostream &operator<<(Ostream &os, std::vector<T> const &vec)
{
	return quix::print(os, vec);
}


template<class Istream, typename T>
inline Istream &operator>>(Istream &is, std::vector<T> &vec)
{
	return quix::scan(is, vec);
}






	// other
template<class Ostream, typename T>
inline Ostream &operator<<(Ostream &os, std::list<T> const &l)
{
	return quix::print(os, l);
}



template<class Ostream, typename T, typename U>
inline Ostream &operator<<(Ostream &os, std::pair<T, U> const &pair)
{
	return quix::print(os, pair);
}



template<class Ostream, typename T, size_t N>
inline Ostream &operator<<(Ostream &os, std::array<T, N> const &arr)
{
	return quix::print(os, arr);
}



template<class Ostream, typename...Args>
inline Ostream &operator<<(
	Ostream &os, std::tuple<Args...> const &tuple
)
{
	return quix::print(os, tuple);
}







#endif

#ifndef QUIX_POINT_HPP
#define QUIX_POINT_HPP

#include <cmath>

#ifndef QUIX_TYPE_HPP
#define QUIX_TYPE_HPP





namespace quix
{





// --------------- ПСЕВДОНИМЫ ТИПОВ -----------------
typedef long long llong;
typedef long double ldouble;










// ------------- МЕТОПРОГРАММИРОВАНИЕ ---------------
template<typename T> struct Type
{
	typedef T value;
};



template<bool Cond, typename T, typename U>
struct IF
{
	typedef T value_type;
};

template<typename T, typename U>
struct IF<false, T, U>
{
	typedef U value_type;
};










// ----------------- КАСКАДЫ ------------------------
/*
 * bcascade находит f(a, f(b, f(c, ...)))
 * ucascade вызывает f(a), f(b), f(c)...
 * dcascade находит f(f2(a), f(f2(b), f(f2(c), ...)))
 */
template<typename F, typename T, typename U>
inline auto bcascade(F f, T t, U u)
{
	return f(t, u);
}

template<typename F, typename T, typename...Args>
inline auto bcascade(F f, T t, Args...args)
{
	return f(t, bcascade(f, args...));
}


template<typename F, typename T>
inline void ucascade(F f, T t)
{
	f(t);
	return;
}

template<typename F, typename T, typename...Args>
inline void ucascade(F f, T t, Args...args)
{
	f(t);
	ucascade(f, args...);
	return;
}


template<typename F, typename F2, typename T, typename U>
inline T dcascade(F f, F2 f2, T t, U u)
{
	return f(f2(t), f2(u));
}

template<typename F, typename F2, typename T, typename...Args>
inline T dcascade(F f, F2 f2, T t, Args...args)
{
	return f( f2(t), f2(dcascade(f, f2, args...)) );
}





}










// end


#endif








namespace quix
{







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
	inline double length() const
	{
		return std::hypot(x, y);
	}

	inline double hypot() const
	{
		return std::hypot(x, y);
	}

	template<typename P>
	inline double dis(P const &p) const
	{
		return std::hypot(p.x-x, p.y-y);
	}



	// print
	template<class Ostream>
	Ostream &print( Ostream &os ) const
	{
		os << "(";
		quix::print(os, x) << ", ";
		quix::print(os, y) << ")";
		return os;
	}



};






// requaire operations
template<typename T, typename U>
inline bool operator==(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}


template<typename T, typename U>
inline bool operator<(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
}


template<typename T, typename U>
inline bool operator>(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return lhs.y != rhs.y ? lhs.y > rhs.y : lhs.x > rhs.x;
}


template<typename T, typename U>
inline bool operator<=(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return !(lhs > rhs);
}

template<typename T, typename U>
inline bool operator>=(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return !(lhs < rhs);
}





// calculate operators
	// Point and Number
template<typename T, typename U>
inline Point<decltype(T()+U())> operator+(
	Point<T> const &lhs,
	U rhs
)
{
	return {lhs.x+rhs, lhs.y+rhs};
}


template<typename T, typename U>
inline Point<decltype(T()-U())> operator-(
	Point<T> const &lhs,
	U rhs
)
{
	return {lhs.x-rhs, lhs.y-rhs};
}


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


template<typename T, typename U>
inline Point<decltype(T()*U())> operator*(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return {lhs.x*rhs.x, lhs.y*rhs.y};
}


template<typename T, typename U>
inline Point<decltype(T()/U())> operator/(
	Point<T> const &lhs,
	Point<U> const &rhs
)
{
	return {lhs.x/rhs.x, lhs.y/rhs.y};
}





	// mod Point and Number
template<typename T, typename U>
inline Point<T> &operator+=(
	Point<T> &lhs,
	U rhs
)
{
	lhs.x += rhs;
	lhs.y += rhs;
	return lhs;
}


template<typename T, typename U>
inline Point<T> &operator-=(
	Point<T> &lhs,
	U rhs
)
{
	lhs.x -= rhs;
	lhs.y -= rhs;
	return lhs;
}


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


template<typename T, typename U>
inline Point<T> &operator*=(
	Point<T> &lhs,
	Point<U> const &rhs
)
{
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;
	return lhs;
}


template<typename T, typename U>
inline Point<T> &operator/=(
	Point<T> &lhs,
	Point<U> const &rhs
)
{
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;
	return lhs;
}







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
typedef Point<unsigned> PointU;
typedef Point<float> PointF;
typedef Point<double> PointD;







}







#endif






namespace quix
{
	
	
	
	
	
template<typename ValueType>
struct Field
{
	// types
	typedef ValueType value_type;



		// iterator-class
private:
	struct Simple {};
	struct Const {};
	struct TapeAt {};

	template<class IsConst, class TapeMode>
	class Iterator: public std::iterator<
		std::bidirectional_iterator_tag,
		typename IF<
			std::is_same<IsConst, Const>::value,
			Field::value_type const,
			Field::value_type
		>::value_type
	>
	{
	public:
		// types
		typedef typename Iterator::value_type value_type;

		typedef typename IF<
			std::is_same<IsConst, Const>::value,
			Field const, Field
		>::value_type field_type;





		// copy
		template<class C, class TM>
		Iterator( Iterator<C, TM> const &tocp );

		template<class C, class TM>
		Iterator &operator=(Iterator<C, TM> const &rhs);



		// move
		Iterator &operator++();
		inline Iterator operator++(int);

		Iterator &operator--();
		inline Iterator operator--(int);

		Iterator &incy();
		Iterator &incy(int n);

		Iterator &reducey();
		Iterator &reducey(int n);




		// at
		inline value_type &operator*() const;
		inline value_type *operator->() const;
		
		inline value_type *base() const;
		inline PointI point() const;



		// get info
		template<class C, class TM>
		bool operator==(Iterator<C, TM> const &rhs) const;

		template<class C, class TM>
		inline bool operator!=(Iterator<C, TM> const &rhs) const;

		inline bool isedge() const;
		inline bool isend() const;

		// создаёт новый итератор, который можно потом изменять:
		// отправить, например, в функцию make_reverse_iterator;
		// из этого итератора может выйти. Но создаётся новый! В
		// цикле вызывать эту функцию для проверки дошёл ли до 
		// конца итератор - нельзя, используй для этого либо isend,
		// либо iterendc
		Iterator iterend() const;
		static inline Iterator const &citerend();
		


	private:
		friend class Field;

		static Iterator create_iterend();



		// methods
		Iterator();
		Iterator(
			field_type &field,
			int left = 0, int top = 0,
			int width = -1, int height = -1
		);

		inline void plusplus(Simple);
		inline void plusplus(TapeAt);

		inline void minusminus(Simple);
		inline void minusminus(TapeAt);



		// data-members
		int top, left, width, height, fw, fh;
		int x, y;
		value_type *d, *fd;




	};



public:
		// other
	typedef Iterator<Simple, Simple> iterator_type;
	typedef Iterator<Const, Simple> const_iterator_type;
	typedef Iterator<Simple, TapeAt> iterator_tape_type;
	typedef Iterator<Const, TapeAt> const_iterator_tape_type;
 	
	
	
	
	
	// static const members
	static constexpr int const OFFSET_COUNT = 8;
	static constexpr int const OFFSET[OFFSET_COUNT][2] = {
		{ -1, -1 }, { 0, -1 }, { 1, -1 }, //  Directions:
		                       { 1, 0  }, //  0  1  2
		                       { 1, 1  }, //  7  *  3
		            { 0, 1  },            //  6  5  4
		{ -1, 1  },                       // 
		{ -1, 0  },                       // 
	};
	




	// data-members
	int w = 0, h = 0;
	value_type *d = nullptr;
	
	
	
	
	
	// init, free
	inline Field &init();
	inline Field &init(int width, int height);
	inline Field &free();



	// clear & zeroize
	inline Field &clear();
	inline Field &clear(value_type const &value);

	inline Field &clearline(int line);
	inline Field &clearline(
		value_type const &value, int line
	);

	inline Field &clearlines(
		int bline, int nline
	);
	inline Field &clearlines(
		value_type const &value,
		int bline, int nline
	);

	inline Field &zeroize();
	inline Field &zeroize(int line);
	inline Field &zeroize(int bline, int nline);





	// check vlaid
		// simple
	inline bool isValid(int x, int y) const;

	template<class Point>
	inline bool isValid(Point const &p) const;



		// for near
	inline bool isValid(int x, int y, int dir) const;

	template<class Point>
	inline bool isValid(Point const &p, int dir) const;





	// correct
	inline void correct(int &x, int &y) const;

	template<class Point>
	inline void correct(Point &p) const;





	// get 
	inline void getxy(int i, int &x, int &y) const;
	inline PointI getxy(int i) const;

	inline void getxy(value_type const *p, int &x, int &y) const;
	inline PointI getxy(value_type const *p) const;

	inline int geti(int x, int y) const;

	template<class Point>
	inline int geti(Point const &p) const;



	// geometry
	inline PointF origin(int x, int y, float a) const;
	inline PointF origin(PointI const &p, float a) const;
	inline PointF origin(value_type const *p, float a) const;





	// at
		// simple
	inline value_type &at(int x, int y);
	inline value_type const &at(int x, int y) const;


		// for point
	template<class Point>
	inline value_type const &at(
		Point const &p
	) const;

	template<class Point>
	inline value_type &at(
		Point const &p
	);



		// tape at simple
	inline value_type &att(int x, int y);
	inline value_type const &att(int x, int y) const;


		// tape at for point
	template<class Point>
	inline value_type const &att(
		Point const &p
	) const;

	template<class Point>
	inline value_type &att(
		Point const &p
	);



		// near at simple
	inline value_type &near(int x, int y, int dir);
	inline value_type const &near(int x, int y, int dir) const;


		// near at for point
	template<class Point>
	inline value_type &near(Point const &p, int dir);

	template<class Point>
	inline value_type const &near(
		Point const &p, int dir
	) const;

		

		// near tape at simple
	inline value_type &neart(int x, int y, int dir);
	inline value_type const &neart(int x, int y, int dir) const;


		// near at for point
	template<class Point>
	inline value_type &neart(Point const &p, int dir);

	template<class Point>
	inline value_type const &neart(
		Point const &p, int dir
	) const;



		// operator at
	inline value_type const *operator[](char y) const;
	inline value_type *operator[](char y);

	inline value_type const *operator[](int y) const;
	inline value_type *operator[](int y);

	inline value_type const *operator[](long y) const;
	inline value_type *operator[](long y);

	inline value_type const *operator[](long long y) const;
	inline value_type *operator[](long long y);

	template<class Point>
	inline value_type const &operator[](Point const &p) const;

	template<class Point>
	inline value_type &operator[](Point const &p);





	// iterators
		// simple
	inline value_type *begin();
	inline value_type *end();

	inline value_type const *begin() const;
	inline value_type const *end() const;



		// for line
	inline value_type *begin(int line);
	inline value_type *end(int line);
	
	inline value_type const *begin(int line) const;
	inline value_type const *end(int line) const;



		// class-iterator 
			// simple
	inline iterator_type iterator(
		int left = 0, int top = 0,
		int width = -1, int height = -1
	);
	inline iterator_type const &iterend() const;

			// simple const
	inline const_iterator_type citerator(
		int left = 0, int top = 0,
		int width = -1, int height = -1
	) const;
	inline const_iterator_type const &citerend() const;


			// tape
	inline iterator_tape_type iteratort(
		int left = 0, int top = 0,
		int width = -1, int height = -1
	);
	inline iterator_tape_type const &iterendt() const;

			// tape const
	inline const_iterator_tape_type citeratort(
		int left = 0, int top = 0,
		int width = -1, int height = -1
	) const;
	inline const_iterator_tape_type const &citerendt() const;





	template<class Ostream>
	Ostream &print(
		Ostream &os,
		std::string const &elterm = "\t",
		std::string const &lnterm = "\n"
	) const;





};
	




// init, free;
template<typename ValueType>
inline Field<ValueType> &Field<ValueType>::init()
{
	d = new value_type[w*h];
	return *this;
}


template<typename ValueType>
inline Field<ValueType> &Field<ValueType>::init(
	int neww, int newh
)
{
	w = neww; h = newh;
	d = new value_type[w*h];
	return *this;
}


template<typename ValueType>
inline Field<ValueType> &Field<ValueType>::free()
{
	delete[] d;
	return *this;
}





// clear & zeroize
template<typename ValueType>
inline Field<ValueType> &Field<ValueType>::clear()
{
	clear(value_type());
	return *this;
}


template<typename ValueType>
inline Field<ValueType> &Field<ValueType>::clear(
	value_type const &value
)
{
	std::fill( begin(), end(), value );
	return *this;
}



template<typename ValueType>
inline Field<ValueType> &Field<ValueType>::zeroize()
{
	memset(d, 0, sizeof(value_type)*w*h);
	return *this;
}


template<typename ValueType>
inline Field<ValueType> &Field<ValueType>::zeroize(int line)
{
	memset(d+line*w, 0, sizeof(value_type)*w);
	return *this;
}


template<typename ValueType>
inline Field<ValueType> &Field<ValueType>::zeroize(
	int bline, int nline
)
{
	memset(d+bline*w, 0, sizeof(value_type)*w*nline);
	return *this;
}







// check vlaid
	// simple
template<typename ValueType>
inline bool Field<ValueType>::isValid(int x, int y) const
{
	return x >= 0 && x < w && y >= 0 && y < h;
}


template<typename ValueType> template<class Point>
inline bool Field<ValueType>::isValid(
	Point const &p
) const
{
	return p.x >= 0 && p.x < w && p.y >= 0 && p.y < h;
}



	// for near
template<typename ValueType>
inline bool Field<ValueType>::isValid(
	int x, int y, int dir
) const
{
	return isValid(
		x + OFFSET[dir][0],
		y + OFFSET[dir][1]
	);
}

template<typename ValueType> template<class Point>
inline bool Field<ValueType>::isValid(
	Point const &p, int dir
) const
{
	return isValid(
		p.x + OFFSET[dir][0],
		p.y + OFFSET[dir][1]
	);
}





// correct
template<typename ValueType>
inline void Field<ValueType>::correct(int &x, int &y) const
{
	x = x < 0 ?
		w-1 - (-x-1)%w :
		x % w;
	y = y < 0 ?
		h-1 - (-y-1)%h :
		y % h;
	return;
}

template<typename ValueType> template<class Point>
inline void Field<ValueType>::correct(Point &p) const
{
	p.x = p.x < 0 ?
		( int(p.x)%w == 0 ? 0 : int(p.x) - (int(p.x)/w - 1)*w ) :
		int(p.x) % w;
	p.y = p.y < 0 ?
		( int(p.y)%h == 0 ? 0 : int(p.y) - (int(p.y)/h - 1)*h ) :
		int(p.y) % h;
	return;
}





// get
template<typename ValueType>
inline void Field<ValueType>::getxy(
	int i, int &x, int &y
) const
{
	x = i%w;
	y = i/w;
	return;
}

template<typename ValueType>
inline PointI Field<ValueType>::getxy(
	int i
) const
{
	return { i%w, i/w };
}



template<typename ValueType>
inline void Field<ValueType>::getxy(
	typename Field<ValueType>::value_type const *p,
	int &x, int &y
) const
{
	x = (p-d)%w;
	y = (p-d)/w;
	return;
}

template<typename ValueType>
inline PointI Field<ValueType>::getxy(
	value_type const *p
) const
{
	return { (p-d) % w, (p-d) / w };
}



template<typename ValueType>
inline int Field<ValueType>::geti(
	int x, int y
) const
{
	return x + y*w;
}

template<typename ValueType> template<class Point>
inline int Field<ValueType>::geti(
	Point const &p
) const
{
	return p.x + p.y*w;
}







// geometry
template<typename ValueType>
inline PointF Field<ValueType>::origin(
	int x, int y, float a
) const
{
	return { x*a, y*a };
}

template<typename ValueType>
inline PointF Field<ValueType>::origin(
	PointI const &p, float a
) const
{
	return { p.x*a, p.y*a };
}

template<typename ValueType>
inline PointF Field<ValueType>::origin(
	value_type const *p, float a
) const
{
	return { (p-d)%w*a, (p-d)/w*a };
}







// at
	// simple
template<typename ValueType>
inline typename Field<ValueType>::value_type &
Field<ValueType>::at(int x, int y)
{
	return d[y*w+x];
}


template<typename ValueType>
inline typename Field<ValueType>::value_type const &
Field<ValueType>::at(int x, int y) const
{
	return d[y*w+x];
}



	// for point
template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type const &
Field<ValueType>::at(Point const &p) const
{
	return d[p.y*w+p.x];
}


template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type &
Field<ValueType>::at(
	Point const &p
)
{
	return d[p.y*w+p.x];
}





	// tape at simple
template<typename ValueType>
inline typename Field<ValueType>::value_type &
Field<ValueType>::att(int x, int y)
{
	correct(x, y);
	return d[y*w+x];
}

	
template<typename ValueType>
inline typename Field<ValueType>::value_type const &
Field<ValueType>::att(int x, int y) const
{
	correct(x, y);
	return d[y*w+x];
}



	// tape at for point
template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type const &
Field<ValueType>::att(
	Point const &p
) const
{
	return att(p.x, p.y);
}


template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type &
Field<ValueType>::att(
	Point const &p
)
{
	return att(p.x, p.y);
}



	// near at simple
template<typename ValueType>
inline typename Field<ValueType>::value_type
&Field<ValueType>::near(
	int x, int y, int dir
)
{
	return at( x + OFFSET[dir][0], y + OFFSET[dir][1] );
}


template<typename ValueType>
inline typename Field<ValueType>::value_type const
&Field<ValueType>::near(
	int x, int y, int dir
) const
{
	return at( x + OFFSET[dir][0], y + OFFSET[dir][1] );
}



	// near at for point
template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type
&Field<ValueType>::near(
	Point const &p, int dir
)
{
	return at( p.x + OFFSET[dir][0], p.y + OFFSET[dir][1] );
}


template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type const
&Field<ValueType>::near(
	Point const &p, int dir
) const
{
	return at( p.x + OFFSET[dir][0], p.y + OFFSET[dir][1] );
}

	



	// near tape at simple
template<typename ValueType>
inline typename Field<ValueType>::value_type
&Field<ValueType>::neart(
	int x, int y, int dir
)
{
	return att(
		x + OFFSET[dir][0],
		y + OFFSET[dir][1]
	);
}

template<typename ValueType>
inline typename Field<ValueType>::value_type const
&Field<ValueType>::neart(
	int x, int y, int dir
) const
{
	return att(
		x + OFFSET[dir][0],
		y + OFFSET[dir][1]
	);
}



	// near at for point
template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type
&Field<ValueType>::neart(
	Point const &p, int dir
)
{
	return att(
		p.x + OFFSET[dir][0],
		p.y + OFFSET[dir][1]
	);
}

template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type const
&Field<ValueType>::neart(
	Point const &p, int dir
) const
{
	return att(
		p.x + OFFSET[dir][0],
		p.y + OFFSET[dir][1]
	);
}





	// operator at
template<typename ValueType>
inline typename Field<ValueType>::value_type const *
Field<ValueType>::operator[](char n) const
{
	return d + n*w;
}


template<typename ValueType>
inline typename Field<ValueType>::value_type *
Field<ValueType>::operator[](char n)
 {
	return d + n*w;
}




template<typename ValueType>
inline typename Field<ValueType>::value_type const *
Field<ValueType>::operator[](int n) const
{
	return d + n*w;
}


template<typename ValueType>
inline typename Field<ValueType>::value_type *
Field<ValueType>::operator[](int n)
 {
	return d + n*w;
}




template<typename ValueType>
inline typename Field<ValueType>::value_type const *
Field<ValueType>::operator[](long n) const
{
	return d + n*w;
}


template<typename ValueType>
inline typename Field<ValueType>::value_type *
Field<ValueType>::operator[](long n)
 {
	return d + n*w;
}




template<typename ValueType>
inline typename Field<ValueType>::value_type const *
Field<ValueType>::operator[](long long n) const
{
	return d + n*w;
}


template<typename ValueType>
inline typename Field<ValueType>::value_type *
Field<ValueType>::operator[](long long n)
 {
	return d + n*w;
}




template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type const &
Field<ValueType>::operator[](Point const &p) const
{
	return at(p);
}


template<typename ValueType> template<class Point>
inline typename Field<ValueType>::value_type &
Field<ValueType>::operator[](Point const &p)
 {
	return at(p);
}







// iterators
	// simple
template<typename ValueType>
inline typename Field<ValueType>::value_type *
Field<ValueType>::begin()
{
	return d;
}


template<typename ValueType>
inline typename Field<ValueType>::value_type *
Field<ValueType>::end()
{
	return d + w*h;
}



	// simple const
template<typename ValueType>
inline typename Field<ValueType>::value_type const *
Field<ValueType>::begin() const
{
	return d;
}


template<typename ValueType>
inline typename Field<ValueType>::value_type const *
Field<ValueType>::end() const
{
	return d + w*h;
}





	// for line
template<typename ValueType>
inline typename Field<ValueType>::value_type *
Field<ValueType>::begin(int line)
{
	return d + line*w;
}


template<typename ValueType>
inline typename Field<ValueType>::value_type *
Field<ValueType>::end(int line)
{
	return d + (line+1)*w;
}



	// for line const
template<typename ValueType>
inline typename Field<ValueType>::value_type const *
Field<ValueType>::begin(int line) const
{
	return d + line*w;
}


template<typename ValueType>
inline typename Field<ValueType>::value_type const *
Field<ValueType>::end(int line) const
{
	return d + (line+1)*w;
}





	// class-iterator
		// simple
template<typename ValueType>
inline typename Field<ValueType>::iterator_type
Field<ValueType>::iterator(
	int left, int top,
	int width, int height
)
{
	return iterator_type(
		*this,
		left, top,
		width, height
	);
}

template<typename ValueType>
inline typename Field<ValueType>::iterator_type const &
Field<ValueType>::iterend() const
{
	return iterator_type::citerend();
}


		// simple const
template<typename ValueType>
inline typename Field<ValueType>::const_iterator_type
Field<ValueType>::citerator(
	int left, int top,
	int width, int height
) const
{
	return const_iterator_type(
		*this,
		left, top,
		width, height
	);
}

template<typename ValueType>
inline typename Field<ValueType>::const_iterator_type const &
Field<ValueType>::citerend() const
{
	return const_iterator_type::citerend();
}



		// tape
template<typename ValueType>
inline typename Field<ValueType>::iterator_tape_type
Field<ValueType>::iteratort(
	int left, int top,
	int width, int height
)
{
	return iterator_tape_type(
		*this,
		left, top,
		width, height
	);
}

template<typename ValueType>
inline typename Field<ValueType>::iterator_tape_type const &
Field<ValueType>::iterendt() const
{
	return iterator_tape_type::enditer();
}


		// tape const
template<typename ValueType>
inline typename Field<ValueType>::const_iterator_tape_type
Field<ValueType>::citeratort(
	int left, int top,
	int width, int height
) const
{
	return const_iterator_tape_type(
		*this,
		left, top,
		width, height
	);
}

template<typename ValueType>
inline typename Field<ValueType>::const_iterator_tape_type const &
Field<ValueType>::citerendt() const
{
	return const_iterator_tape_type::enditerc();
}





// print
template<typename ValueType> template<class Ostream>
Ostream &Field<ValueType>::print(
	Ostream &os,
	std::string const &elterm,
	std::string const &lnterm
) const
{
	for(int y = 0; y < h; ++y)
	{
		for(int x = 0; x < w; ++x)
		{
			quix::print(os, at(x, y)) << elterm;
		}
		os << lnterm;
	}
	return os;
}







// iterator-class
// copy
template<typename ValueType>
template<class IsConst, class TapeMode>
template<class C, class TM>
Field<ValueType>::Iterator<IsConst, TapeMode>::Iterator(
	Iterator<C, TM> const &tocp
):
	left(tocp.left), top(tocp.top),
	width(tocp.width), height(tocp.height),
	fw(tocp.fw), fh(tocp.fh),
	x(tocp.x), y(tocp.y),
	d(tocp.d), fd(tocp.fd) {}

template<typename ValueType>
template<class IsConst, class TapeMode>
template<class C, class TM>
Field<ValueType>::Iterator<IsConst, TapeMode> &
Field<ValueType>::Iterator<IsConst, TapeMode>::operator=(
	Iterator<C, TM> const &rhs
)
{
	left = rhs.left;
	top = rhs.top;
	width = rhs.width;
	height = rhs.height;
	fw = rhs.fw;
	fh = rhs.fh;
	x = rhs.x;
	y = rhs.y;
	d = rhs.d;
	fd = rhs.fd;
	return *this;
}





// move
template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode> &
Field<ValueType>::Iterator<IsConst, TapeMode>::operator++()
{
	plusplus(TapeMode());
	return *this;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode>::operator++(int)
{
	auto athis = *this;
	operator++();
	return athis;
}



template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode> &
Field<ValueType>::Iterator<IsConst, TapeMode>::operator--()
{

	minusminus(TapeMode());
	return *this;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
inline Field<ValueType>::Iterator<IsConst, TapeMode>
 Field<ValueType>::Iterator<IsConst, TapeMode>::operator--(int)
{
	auto cp = *this;
	operator--();
	return cp;
}



template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode> &
Field<ValueType>::Iterator<IsConst, TapeMode>::incy()
{
	++y;
	d += fw;
	return *this;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode> &
Field<ValueType>::Iterator<IsConst, TapeMode>::incy(int n)
{
	y += n;
	d += fw*n;
	return *this;
}



template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode> &
Field<ValueType>::Iterator<IsConst, TapeMode>::reducey()
{
	--y;
	d -= fw;
	return *this;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode> &
Field<ValueType>::Iterator<IsConst, TapeMode>::reducey(int n)
{
	y -= n;
	d -= fw*n;
	return *this;
}





// at
template<typename ValueType>
template<class IsConst, class TapeMode>
typename Field<ValueType>::template Iterator<IsConst, TapeMode>::value_type &
Field<ValueType>::Iterator<IsConst, TapeMode>::operator*() const
{
	return *d;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
typename Field<ValueType>::template Iterator<IsConst, TapeMode>::value_type *
Field<ValueType>::Iterator<IsConst, TapeMode>::operator->() const
{
	return d;
}



template<typename ValueType>
template<class IsConst, class TapeMode>
inline typename Field<ValueType>::template Iterator<IsConst, TapeMode>::value_type *
Field<ValueType>::Iterator<IsConst, TapeMode>::base() const
{
	return d;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
inline PointI Field<ValueType>::Iterator<IsConst, TapeMode>::point() const
{
	return { x, y };
}





// get info
	// compare
template<typename ValueType>
template<class IsConst, class TapeMode>
template<class C, class TM>
bool Field<ValueType>::Iterator<IsConst, TapeMode>::operator==(
	Field<ValueType>::Iterator<C, TM> const &rhs
) const
{
	if(d)
		return rhs.d ?
			x == rhs.x && y == rhs.y :
			isend();
	return rhs.d ?
 		rhs.isend() :
		true;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
template<class C, class TM>
inline bool Field<ValueType>::Iterator<IsConst, TapeMode>::operator!=(
	Field<ValueType>::Iterator<C, TM> const &rhs
) const
{
	return !operator==(rhs);
}



	// end
template<typename ValueType>
template<class IsConst, class TapeMode>
inline bool Field<ValueType>::Iterator<IsConst, TapeMode>::isedge() const
{
	return x == left || x == left+width-1 || y == top || y == top+height-1;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
inline bool Field<ValueType>::Iterator<IsConst, TapeMode>::isend() const
{
	return y == height+top;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode>::iterend() const
{
	auto e = *this;
	e.x = left;
	e.y = top+height;
	return e;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode> const &
Field<ValueType>::Iterator<IsConst, TapeMode>::citerend()
{
	static Iterator const singleton = create_iterend();
	return singleton;
}







// private
	// static
template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode>
Field<ValueType>::Iterator<IsConst, TapeMode>::create_iterend()
{
	Iterator iter;
	iter.d = nullptr;
	return iter;
}





	// constructor
template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::template Iterator<IsConst, TapeMode>::Iterator(): d(nullptr) {}

template<typename ValueType>
template<class IsConst, class TapeMode>
Field<ValueType>::template Iterator<IsConst, TapeMode>::Iterator(
	field_type &field,
	int left, int top,
	int width, int height
):
	left(left), top(top),
	width( width < 0 ? field.w-left : width ),
	height( height < 0 ? field.h-top : height ),
	fw(field.w), fh(field.h),
	x(left), y(top),
	d( &field.att(left, top) ), fd(field.d) {}



	// move
template<typename ValueType>
template<class IsConst, class TapeMode>
inline void Field<ValueType>::Iterator<IsConst, TapeMode>::plusplus(Simple)
{
	if(++x == width+left)
	{
		x = left;
		++y;
		d += fw-width+1;
	}
	else
		++d;
	return;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
inline void Field<ValueType>::Iterator<IsConst, TapeMode>::plusplus(TapeAt)
{
	if(++x == width+left)
	{
		x = left;
		++y;
	}
	d = fd + tape(x, fw) + tape(y, fh)*fw;

	return;
}



template<typename ValueType>
template<class IsConst, class TapeMode>
inline void Field<ValueType>::Iterator<IsConst, TapeMode>::minusminus(Simple)
{
	if(--x == left-1)
	{
		x = left+width-1;
		--y;
	}
	d = fd + x + y*fw;
	
	return;
}

template<typename ValueType>
template<class IsConst, class TapeMode>
inline void Field<ValueType>::Iterator<IsConst, TapeMode>::minusminus(TapeAt)
{
	if(--x == left-1)
	{
		x = left+width-1;
		--y;
	}
	d = fd + tape(x, fw) + tape(y, fh)*fw;
	
	return;
}







// end






}





template<class Ostream, typename ValueType>
Ostream &operator<<(Ostream &os, quix::Field<ValueType> const &toprint)
{
	toprint.print(os);
	return os;
}





#endif



using namespace std;
using namespace quix;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	static constexpr PointI const OFFSET[4] = {
		{ 1, 0 }, { -1, 0 },
		{ 0, 1 }, { 0, -1 }
	};

	struct Unit { char what; int group; };

	Field<Unit> f;
	vector<PointI> vec;
	int groupc;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &f.h, &f.w);
		f.init().zeroize();
		int inp;
		for(auto b = f.begin(), e = f.end(); b != e; ++b)
		{
			while( isspace(inp = fgetc(file)) );
			b->what = (char)inp;
			if(inp == '#')
				vec.push_back( f.getxy(b) );
		}
		fclose(file);
	}
	
	
	
	// solve
	groupc = 0;

	queue<PointI> que;
	PointI cur;
	int curgroup;
	for(auto b = vec.begin(), e = vec.end(); b != e; ++b)
	{
		if( f[*b].group )
			continue;

		curgroup = ++groupc;
		f[*b].group = curgroup;

		que = queue<PointI>();
		que.push(*b);
		while(!que.empty())
		{
			cur = que.front();

			for(auto off : OFFSET)
			{
				if(
					!f.isValid(cur+off) ||
					f[cur+off].what == '.' ||
					f[cur+off].group
				)
					continue;
				que.push(cur+off);
				f[cur+off].group = curgroup;
			}
			
			que.pop();
		}
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", groupc);
		fclose(file);
	}



	return 0;
}





// end

