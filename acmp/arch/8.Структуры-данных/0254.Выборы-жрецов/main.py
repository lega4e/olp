
inlist = [ int(i) for i in open("INPUT.TXT").read().split() ];
graphs = [ (i, False) for i in inlist[1:inlist[0]+1] ];


for i in range(inlist[0]+2, len(inlist), 2):
	for j in range(len(graphs)):
		if not graphs[j][1] and graphs[j][0] == inlist[i]:
			graphs[j] = (inlist[i+1], True);


outfile = open("OUTPUT.TXT", "w");
for i in graphs:
	outfile.write( str(i[0]) + ' ' );
outfile.close();
