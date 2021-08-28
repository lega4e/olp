
strlist = open("INPUT.TXT", 'r').read().split();

x1 = float(strlist[0]);
y1 = float(strlist[1]);
x2 = float(strlist[2]);
y2 = float(strlist[3]);
x3 = float(strlist[4]);
y3 = float(strlist[5]);


len1 = ( (x2-x1)**2 + (y2-y1)**2 )**0.5;
len2 = ( (x3-x2)**2 + (y3-y2)**2 )**0.5;
len3 = ( (x1-x3)**2 + (y1-y3)**2 )**0.5;

p = ( len1 + len2 + len3 ) / 2.0;
s = (p*(p-len1)*(p-len2)*(p-len3))**0.5;

open("OUTPUT.TXT", 'w').write( str(s) );


