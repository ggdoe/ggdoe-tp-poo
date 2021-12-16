import sys
import matplotlib.pyplot as plt
import numpy as np

if len(sys.argv) <= 1:
    print("Usage : data are in ./data/")
    print("Usage : plot_data.py data1.ex data2.ex ...")
    sys.exit(1)

plt.xlabel("t")
plt.ylabel("x")

sys.argv.pop(0) # on retire l'executable de la liste des args

for filename in sys.argv:
    print("load : "+filename)
    array = np.loadtxt("./data/" + filename)
    t = array[:,0]
    x = array[:,1]
    plt.plot(t, x);

plt.show()


