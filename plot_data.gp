set grid
set pointintervalbox 0
set xlabel "t"
set ylabel "f(t)"
plot "./data/slv-euler.data" with lines, "./data/slv-rk4.data" with lines
pause -1
