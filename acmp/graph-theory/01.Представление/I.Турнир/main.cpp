#include <iostream>

#include "../AdjacMatrix.cpp"


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	AdjacMatrix adjm;
	bool res;

	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		adjm.scan_riblist1(file, true);
		fclose(file);
	}

	res = true;
	for(int i = 0; i < adjm.n; ++i)
	{
		if( adjm[i][i] )
		{
			res = false;
			goto output_label;
		}

		for(int j = i+1; j < adjm.n; ++j)
		{
			if( adjm[i][j] + adjm[j][i] != 1 )
			{
				res = false;
				goto output_label;
			}
		}
	}



output_label:
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		if(res)
			fprintf(file, "YES\n");
		else
			fprintf(file, "NO\n");
	}
		



	return 0;
}





// end
