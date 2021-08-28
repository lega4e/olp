
l = open("INPUT.TXT").read().split();
a = int(l[0]);
b = int(l[1]);

open("OUTPUT.TXT", "w").write(
	str(b-1) + " " + str(a-1)
);
