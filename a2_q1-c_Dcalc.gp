f(x) = 2*D_x*x
fit [0.7:1] f(x) "msd.dat" u ($0*0.01):1 via D_x
f(x) = 2*D_y*x
fit [0.7:1] f(x) "msd.dat" u ($0*0.01):2 via D_y
f(x) = 2*D_z*x
fit [0.7:1] f(x) "msd.dat" u ($0*0.01):3 via D_z

D_tot = D_x + D_y + D_z
print D_tot
