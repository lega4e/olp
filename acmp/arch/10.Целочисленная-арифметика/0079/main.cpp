#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	vector<int> ans;
	vector<int>::iterator it;

	int formult;
	int result;
	int count;

	ifstream(INPUT_FILE_NAME) >> formult >> count;
	formult %= 10;
	result = formult;
	ans.push_back(result);
	--count;

	while(true)
	{
		result = result * formult % 10;
		if(!--count)
			break;
		it = find( ans.begin(), ans.end(), result );
		if(it != ans.end())
		{
			result = ans[ count % ans.size() ];
			break;
		}
		ans.push_back(result);
	}

	ofstream(OUTPUT_FILE_NAME) << result << flush;

	return 0;
}





// end
