

n = int( open("INPUT.TXT", "r").read() )

result = 1;

for i in range(3):
	result *= n;
	n -= 1;
	if n == 0:
		break;

open("OUTPUT.TXT", "w").write( str( result ) );
