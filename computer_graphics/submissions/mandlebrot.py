import numpy as np
import matplotlib.pyplot as plt

def calc(c, z):
   j=0
   for i in range(500):
      z = z**2 + c
      j += 1        
      if(abs(z) > 4):break
   return j

def mandelbrot(x, y):
   m = np.zeros((len(x), len(y)))
   for i in range(len(x)):
      for j in range(len(y)):
         c = complex(x[i], y[j])
         z = complex(0, 0)
         count = calc(c, z)
         m[i, j] = count    
   return m

x = np.linspace(-2, 1, 1000)
y = np.linspace(-1, 1,1000)
m = mandelbrot(x, y)
plt.imshow(m.T, cmap = "RdGy")
plt.axis("off")
plt.show()
