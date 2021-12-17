set grid
set pointintervalbox 0
set xlabel "t"
set ylabel "f(t)"
plot "./data/exp-euler.data" with lines, "./data/exp-rk4.data" with lines
pause -1
