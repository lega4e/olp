#include <iostream>
#include <fstream>
#include <deque>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int opc;
	deque<int> stage;
	
	
	
	ifstream fin(INPUT_FILE_NAME);
	ofstream fout(OUTPUT_FILE_NAME);

	fin >> opc;
	int action;
	int index;

	while(opc)
	{
		fin >> action;
		switch(action)
		{
		case 1:
			fin >> index;
			stage.push_front(index);
			break;
		case 2:
			fin >> index;
			stage.push_back(index);
			break;
		case 3:
			fout << stage.front() << ' ';
			stage.pop_front();
			break;
		case 4:
			fout << stage.back() << ' ';
			stage.pop_back();
			break;
		}

		--opc;
	}
	

	return 0;
}





// end
