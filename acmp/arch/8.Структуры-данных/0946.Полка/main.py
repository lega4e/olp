

inlist = [ int(i) for i in open("INPUT.TXT").read().split()[1:] ];
stage = list();
outfile = open("OUTPUT.TXT", "w");

i = 0;
while i < len(inlist):
	action = inlist[i];
	if action == 1:
		stage.insert(0, inlist[i+1]);
		i += 1;
	elif action == 2:
		stage.append(inlist[i+1]);
		i += 1;
	elif action == 3:
		outfile.write( str(stage[0]) + ' ' );
		stage.pop(0);
	else:
		outfile.write( str(stage[-1]) + ' ' );
		stage.pop();
	i += 1;


