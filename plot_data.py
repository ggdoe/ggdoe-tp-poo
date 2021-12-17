# py plot_data.py edo-euler.data edo-rk4.data
# py plot_data.py euler.data rk4.data exact.data
import sys
import matplotlib.pyplot as plt
import numpy as np

if len(sys.argv) <= 1:
    print("Usage : data are in ./data/")
    print("Usage : plot_data.py data1.ex data2.ex ...")
    print("Exemple : py plot_data.py edo-euler.data edo-rk4.data")
    sys.exit(1)

fig = plt.figure()
ax = plt.subplot(111)

plt.xlabel("t")
plt.ylabel("f(t)")

sys.argv.pop(0) # on retire l'executable de la liste des args

for filename in sys.argv:
    print("load : " + filename)
    array = np.loadtxt("./data/" + filename)
    t = array[:,0]
    x = array[:,1]
    ax.plot(t, x, label=filename);

plt.title("Plot data - Resolver EDO")
ax.legend()
plt.show()


