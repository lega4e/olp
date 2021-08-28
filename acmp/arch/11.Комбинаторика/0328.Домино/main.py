
n = int( open("INPUT.TXT", "r").read() );
open("OUTPUT.TXT", "w").write( str(
	( (n + 1) ** 3 - (n + 1) ) // 2
));
