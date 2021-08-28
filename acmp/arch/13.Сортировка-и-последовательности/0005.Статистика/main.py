
array = [ int(s) for s in open("INPUT.TXT").read().split()[1:] ];
outfile = open("OUTPUT.TXT", "w");

three = 0;
four = 0;

for i in array:
	if i % 2 == 1:
		three = three+1;
		outfile.write( str(i) + ' ' );
outfile.write('\n');

for i in array:
	if i % 2 == 0:
		four = four+1;
		outfile.write( str(i) + ' ' );
outfile.write('\n');

if four >= three:
	outfile.write('YES');
else:
	outfile.write('NO');

