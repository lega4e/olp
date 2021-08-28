#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





// structs
typedef struct Point
{
	int x, y;
} Vector;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

constexpr double const ALPHA = 0.000000001;





// functions
inline Vector operator-(Point const &lhs, Point const &rhs)
{
	return Vector{lhs.x-rhs.x, lhs.y-rhs.y};
}

inline double angle(Vector const &lhs, Vector const &rhs)
{
	return acos(
		( lhs.x*rhs.x + lhs.y*rhs.y ) /
		( hypot(lhs.x, lhs.y) * hypot(rhs.x, rhs.y) )
	);
}




// main
int main( int argc, char *argv[] )
{
	Point a, b, c;
	ifstream(INPUT_FILE_NAME) >>
		a.x >> a.y >>
		b.x >> b.y >>
		c.x >> c.y;

	if(
		M_PI/2.0f - angle(b-a, c-a) > -ALPHA &&
		M_PI/2.0f - angle(a-b, c-b) > -ALPHA
	)
		cout << "ON" << endl;
	else
		cout << "NOT ON" << endl;

	return 0;
}





// end
