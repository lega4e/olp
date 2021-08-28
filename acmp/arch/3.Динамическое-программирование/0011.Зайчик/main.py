


# read input
s = open("INPUT.TXT", 'r').read().split();
k = int(s[0]);
n = int(s[1]);

# make variants
variants = list();
variants.append(1);
variants.append(1);
varlen = 2;


for i in range(2, n+1):
	variants.append(0);
	for j in range( max(0, i-k), i ):
		variants[varlen] += variants[j];
	varlen += 1;


# output
open("OUTPUT.TXT", 'w').write( str(variants[varlen-1]) );


