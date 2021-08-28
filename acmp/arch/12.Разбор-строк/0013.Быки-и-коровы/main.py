
l = open("INPUT.TXT", "r").read().split();
a = l[0];
b = l[1];

x = 0;
y = 0;

for i in range( len(a) ):
	if a[i] == b[i]:
		y += 1;
	elif a[i] in b:
		x += 1;

open("OUTPUT.TXT", "w").write(
	str(y) + " " + str(x)
);


