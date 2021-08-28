#include <cstdio>
#include <cstring>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	int *power;

	bool result; 
	

	
	// input & calculate power
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		power = n ? new int[n] : nullptr;
		memset(power, 0, sizeof *power * n);

		int buf;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				fscanf(file, "%i", &buf);
				if(buf)
					++power[i];
			}
		}
		fclose(file);
	}
	
	
	
	// calculate
	{
		result = true;
		for(auto *b = power+1, *e = power+n; b < e; ++b)
		{
			if(*b != *power)
			{
				result = false;
				break;
			}
		}
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		if(result)
			fprintf(file, "YES");
		else
			fprintf(file, "NO");
		fflush(file);
		fclose(file);
	}

	

	return 0;
}





// end
