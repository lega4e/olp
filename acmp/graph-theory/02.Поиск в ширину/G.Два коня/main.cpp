#include <iostream>
#include <fstream>

#include <quix/Field.hpp>


using namespace std;
using namespace quix;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
    static constexpr PointI const OFFSET[8] = {
        { 1, 2 },
        { 1, -2 },
        { -1, 2 },
        { -1, -2 },
        { 2, 1 },
        { 2, -1 },
        { -2, 1 },
        { -2, -1 }
    };
 
    struct Unit
    {
        int red, green;
    };
 
    int count = 0;
    Field<int> f, sf;
    f.init(8, 8).zeroize();
    sf.init(8, 8).zeroize();
     
     
     
    // input
    {
        string inp;
        PointI p;
        ifstream fin(INPUT_FILE_NAME);
 
        fin >> inp;
        p.x = inp[0] - 'a';
        p.y = inp[1] - '1';
        f[p] = 'r';
 
        fin >> inp;
        p.x = inp[0] - 'a';
        p.y = inp[1] - '1';
        if(f[p])
            goto output_label;
        f[p] = 'g';
    }
     
     
     
    // solve
    while(true)
    {
        ++count;
	if(count == 1000)
	{
		count = -1;
		goto output_label;
	}
 
        for(PointI p{0, 0}, cur; p.y < 8; ++p.y)
        for(p.x = 0; p.x < 8; ++p.x)
        {
            if(!f[p])
                continue;
 
            for(auto off : OFFSET)
            {
                cur = p+off;
                if(!sf.isValid(cur))
                    continue;
 
                if(sf[cur] && sf[cur] != f[p])
                    goto output_label;
 
                sf[cur] = f[p];
            }
        }
 
        swap(f, sf);
        sf.clear();
    }
     
     
     
output_label:
    // output
    ofstream(OUTPUT_FILE_NAME) << count;
 
 
 
    return 0;
}





// end
