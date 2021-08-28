

# read input
s = open("INPUT.TXT").read().split();

toklen = int(s[0]);
tokens = list();

for i in range(0, toklen):
	tokens.append( int(s[i+1]) );

n = int(s[toklen+1]);


# calculate
variants = list();
variants.append(1);

for i in range(1, n+1):
	variants.append(0);
	for j in range(0, toklen):
		if tokens[j] > i:
			break;
		variants[i] += variants[ i-tokens[j] ];

print( variants[ len(variants)-1 ] );
