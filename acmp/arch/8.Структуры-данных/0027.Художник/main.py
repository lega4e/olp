#! /usr/bin/python3

inlist = [ int(i) for i in open("INPUT.TXT", "r").read().split() ];
field = [ [0]*inlist[0] ] * inlist[1];

for i in range(3, len(inlist), 4):
	fx = inlist[i]; fy = inlist[i+1];
	sx = inlist[i+2]; sy = inlist[i+3];
	print(fx, fy, sx, sy);
	for y in range(fy, sy):
		for x in range(fx, sx):
			print('set', y, x);
			field[y][x] = 1;

result = 0;
for y in range(len(field)):
	for x in range(len(field[y])):
		print('field['+str(y)+']['+str(x)+'] = '+str(field[y][x]));
		if field[y][x] == 0:
			result += 1;

print(result);
