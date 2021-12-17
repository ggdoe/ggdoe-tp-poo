set grid
set xlabel "t"
set ylabel "f(t)"
plot "./data/edo-euler.data" with lines, "./data/edo-rk4.data" with lines
pause -1
