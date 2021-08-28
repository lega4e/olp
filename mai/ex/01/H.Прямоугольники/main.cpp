#include <iostream>


using namespace std;





// types
struct Point
{
	int x, y;
};

struct Rectangle
{
	Point a, b;

	Rectangle &normalize()
	{
		if(b.x < a.x)
			swap(a.x, b.x);
		if(b.y < a.y)
			swap(a.y, b.y);
		return *this;
	}
};





// functions
int intersects_rects(
	Rectangle const &f,
	Rectangle const &s
)
{
	int xinter =
		min(f.b.x, s.b.x) - max(f.a.x, s.a.x),
	    yinter =
		min(f.b.y, s.b.y) - max(f.a.y, s.a.y);

	return xinter <= 0 || yinter <= 0 ? 0 : xinter*yinter;
}





// main
int main( int argc, char *argv[] )
{
	Rectangle f, s;
	cin >> f.a.x >> f.a.y;
	cin >> f.b.x >> f.b.y;
	cin >> s.a.x >> s.a.y;
	cin >> s.b.x >> s.b.y;

	cout << intersects_rects(
		f.normalize(),
		s.normalize()
	) << endl;



	return 0;
}





// end
