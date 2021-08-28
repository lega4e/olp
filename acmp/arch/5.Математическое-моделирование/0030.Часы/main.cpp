#include <cstdio>
#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";


int h, m, s;
int hend, mend, send;

int digits[10] = { 0 };




// functions
void next_second();
void next_minute();
void next_hour();
void write_digits();


void next_second()
{
	if( ++s == 60 )
	{
		s = 0;
		next_minute();
	}
	return;
}


void next_minute()
{
	if( ++m == 60 )
	{
		m = 0;
		next_hour();
	}
	return;
}


void next_hour()
{
	++h;
	return;
}



void write_digits()
{
	++digits[ s % 10 ];
	++digits[ s / 10 ];

	++digits[ m % 10 ];
	++digits[ m / 10 ];

	++digits[ h % 10 ];
	++digits[ h / 10 ];

	return;
}


void process()
{
	while(
		s != send ||
		m != mend ||
		h != hend
	)
	{
		write_digits();
		next_second();
	}
	write_digits();

	return;
}






// main
int main( int argc, char *argv[] )
{
	{
		h = m = s = hend = mend = send = 0;

		ifstream fin(INPUT_FILE_NAME);
		char ch;

		// begin
			// hours
		fin.get(ch);
		h += ( ch - '0' )*10;
		fin.get(ch);
		h += ( ch - '0' );
		fin.get(ch); // get ':'

			// minutes
		fin.get(ch);
		m += ( ch - '0' )*10;
		fin.get(ch);
		m += ( ch - '0' );
		fin.get(ch); // get ':'

			// seconds
		fin.get(ch);
		s += ( ch - '0' )*10;
		fin.get(ch);
		s += ( ch - '0' );
		fin.get(ch); // get '\n'


		// end
			// hours
		fin.get(ch);
		hend += ( ch - '0' )*10;
		fin.get(ch);
		hend += ( ch - '0' );
		fin.get(ch); // get ':'

			// minutes
		fin.get(ch);
		mend += ( ch - '0' )*10;
		fin.get(ch);
		mend += ( ch - '0' );
		fin.get(ch); // get ':'

			// seconds
		fin.get(ch);
		send += ( ch - '0' )*10;
		fin.get(ch);
		send += ( ch - '0' );

	}

	process();
	
	// output
	{
		ofstream fout(OUTPUT_FILE_NAME);
		for(auto *b = digits, *e = digits+10; b != e; ++b)
		{
			fout << *b << '\n';
		}
		fout << flush;
	}
	

	return 0;
}





// end
