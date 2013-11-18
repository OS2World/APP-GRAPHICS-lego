set xdim=500
set ydim=500
set name=%1
lego <%name%.lego  >tmp
pnmscale  -xysize %xdim% %ydim% tmp >tmp2
ppmquant 255 tmp2 > tmp3
ppmtogif tmp3 >%name%.gif
