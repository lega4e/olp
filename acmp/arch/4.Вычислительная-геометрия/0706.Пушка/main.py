import math;

l = [ int(s) for s in open("INPUT.TXT").read().split() ];
r = l[0];
x = l[1];
y = l[2];

result = math.sqrt( x ** 2 + (2*r-y) ** 2 );

print(result);

