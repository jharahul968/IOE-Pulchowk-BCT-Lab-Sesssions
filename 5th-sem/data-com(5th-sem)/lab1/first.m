x=[2,5;4,6];
y=[1,5;6,-2];
for (i=1:1:2)
  for (j=1:1:2)
    z(i,j)=x(i,j)+y(i,j);
  endfor
endfor
disp(z);
k=1;
l=1;
while (k<=2)
  while (l<=2)
    zz(k,l)=x(k,l)+y(k,l);
  endwhile
endwhile
disp(zz);

