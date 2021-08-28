#include <fstream>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
bool test(int x, int y, int a)
{
	int buf;
	int arr[4] = { x, y, x, y };

	--arr[3];
	for(int i = 0; i < 3; ++i)
	{
		buf = arr[i]%a;
		if(buf > 1)
			goto first_fail_label;
		if(!buf)
			--arr[i+1];
	}
	if(arr[3] % a == 0)
		return true;


first_fail_label:
	arr[0] = x;
	arr[1] = y;
	arr[2] = x;
	arr[3] = y;

	--arr[0];
	for(int i = 0; i < 3; ++i)
	{
		buf = arr[i]%a;
		if(buf > 1)
			return false;
		if(!buf)
			--arr[i+1];
	}
	return arr[3] % a == 0;
}





// main
int main( int argc, char *argv[] )
{
	int testc;
	int x, y, a;
	
	ifstream fin(INPUT_FILE_NAME);
	ofstream fout(OUTPUT_FILE_NAME);
	fin >> testc;
	for(int i = 0; i < testc; ++i)
	{
		fin >> x >> y >> a;
		fout << ( test(x, y, a) ? 1 : 0 );
	}
	fout << flush;
	fin.close();
	fout.close();

	return 0;
}





// end
