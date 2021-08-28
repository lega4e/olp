/*
 * autor:   clever
 * date:    Nov 30 16:25:35 2019
 */

#include <algorithm>
#include <vector>


using namespace std;





// types
typedef long long llong;





// functions
int mex_sorted(vector<int> const &vec)
{
	for(int i = 0; i < (int)vec.size(); ++i)
	{
		if(vec[i] != i)
			return i;
	}
	return vec.size();
}



int mex_with_sort(vector<int> &vec)
{
	sort( vec.begin(), vec.end() );
	if( vec.empty() || vec[0] )
		return 0;
	for(int i = 0; i < (int)vec.size(); ++i)
	{
		if(vec[i] != i)
			return i;
	}
	return vec.size();
}


int mex(vector<int> &vec)
{
	if(vec.empty())
		return 0;

	for(int i = 0; i < (int)vec.size(); ++i)
	{
		while(vec[i] != -1 && vec[i] != i)
		{
			if(vec[i] >= (int)vec.size() || vec[vec[i]] == vec[i])
				vec[i] = -1;
			else
				swap(vec[i], vec[vec[i]]);
		}
	}

	for(int i = 0; i < (int)vec.size(); ++i)
	{
		if(vec[i] != i)
			return i;
	}
	return vec.size();
}





// end
