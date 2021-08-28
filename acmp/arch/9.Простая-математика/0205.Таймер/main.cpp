#include <iostream>
#include <cassert>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int hours, minutes, seconds;
	int inth, intm, ints;
	int days;
	
	
	
	// input
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> hours;
		assert(fin.get() == ':');
		fin >> minutes;
		assert(fin.get() == ':');
		fin >> seconds;

		inth = intm = ints = 0;
		fin >> inth;
		if(fin.get() == ':' && fin >> intm)
		{
			if(fin.get() == ':' && fin >> ints)
			{
				
			}
			else
			{
				ints = intm;
				intm = inth;
				inth = 0;
			}
		}
		else
		{
			ints = inth;
			inth = 0;
		}
	}
	
	
	
	// calculate
	seconds += ints;
	intm += seconds/60;
	seconds %= 60;

	minutes += intm;
	inth += minutes/60;
	minutes %= 60;

	hours += inth;
	days = hours/24;
	hours %= 24;
	
	
	
	// output
	{
		ofstream fout(OUTPUT_FILE_NAME);
		if(hours < 10)
			fout << '0';
		fout << hours << ':';
		if(minutes < 10)
			fout << '0';
		fout << minutes << ':';
		if(seconds < 10)
			fout << '0';
		fout << seconds;
		if(days)
			fout << "+" << days << " days";
		fout << flush;
	}



	return 0;
}





// end
