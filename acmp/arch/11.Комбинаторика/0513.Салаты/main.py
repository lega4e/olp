
def calculate_c(m, n):
	result = n;
	for i in range(n-m+1, n):
		result *= i;
	for i in range(2, m+1):
		result //= i;
	return result;



n = int( open("INPUT.TXT", "r").read() );

if n == 1:
	result = 0;
else:
	result = 1;
	for i in range(2, n):
		result += calculate_c(i, n);

open("OUTPUT.TXT", "w").write( str(result) );

