#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	int comc;
	int *arr;
	
	
	
	// read array
	ifstream fin(INPUT_FILE_NAME);
	fin >> n;
	arr = new int[n];
	for(auto *b = arr, *e = arr+n; b != e; ++b)
	{
		fin >> *b;
	}
	fin >> comc;
	
	
	
	// execute
	ofstream fout(OUTPUT_FILE_NAME);
	string command;
	int farg, sarg, targ;
	for(int i = 0; i < comc; ++i)
	{
		fin >> command;
		if(command == "get")
		{
			fin >> farg;
			fout << arr[farg-1] << "\n";
		}
		else if(command == "update")
		{
			fin >> farg >> sarg >> targ;
			for(int j = farg-1; j < sarg; ++j)
			{
				arr[j] = targ;
			}
		}
		else if(command == "add")
		{
			fin >> farg >> sarg >> targ;
			for(int j = farg-1; j < sarg; ++j)
			{
				arr[j] += targ;
			}
		}
		else if(command == "rsq")
		{
			fin >> farg >> sarg;
			targ = 0;
			for(int j = farg-1; j < sarg; ++j)
				targ += arr[j];
			fout << targ << "\n";
		}
		else if(command == "rmq")
		{
			fin >> farg >> sarg;
			targ = arr[farg-1];
			for(int j = farg; j < sarg; ++j)
			{
				if(arr[j] < targ)
					targ = arr[j];
			}
			fout << targ << "\n";
		}

	}
	fout << flush;

	fin.close();
	fout.close();

	return 0;
}





// end
