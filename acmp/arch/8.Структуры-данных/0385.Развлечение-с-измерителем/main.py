import math





# main
inlist = [ int(i) for i in open("INPUT.TXT").read().split() ];
points = [ (inlist[i], inlist[i+1]) for i in range(1, inlist[0]*2+1, 2) ];

distance = set();
for i in range(len(points)):
	for j in range(i+1, len(points)):
		distance.add( math.hypot(
			points[j][0] - points[i][0],
			points[j][1] - points[i][1]
		) );


dislist = list(distance);
dislist.sort();

outfile = open("OUTPUT.TXT", 'w');
outfile.write( str( len(dislist) ) + '\n' );
for i in dislist:
	outfile.write( str(i) + '\n' );
