
n = int( open("INPUT.TXT", "r").read() )

result = 0;
if n >= 5:
	result += 1 + (n-5)//10;
power = 10;
while n >= power*5:
	count = 1 + (n - power*5) // (power*10);
	residue = n % (power*10);
	if residue >= power*5 and residue < power*6:
		result += (count-1) * power + (n % power + 1);
	else:
		result += count * power;
	power *= 10;

open("OUTPUT.TXT", "w").write( str(result) );

