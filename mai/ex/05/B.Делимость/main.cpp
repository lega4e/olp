#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int cur = 0;
	char ch;

	while(true)
	{
		while(cur < 97)
		{
			if(scanf("%c", &ch) == EOF || !isdigit(ch))
				goto end_label;
			
			cur *= 10;
			cur += ch-'0';
		}
		cur %= 97;
	}



end_label:
	if(cur)
		printf("NO\n");
	else
		printf("YES\n");



	return 0;
}





// end
