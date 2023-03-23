import numpy as np
import matplotlib.pyplot as plt

def mandelbrot(c, z):
   iterations = 500
   count = 0
   for a in range(iterations):
      z = z**2 + c
      count += 1        
      if(abs(z) > 4):
         break
   return count

def mandelbrot_set(x, y):
   m = np.zeros((len(x), len(y)))
   for i in range(len(x)):
      for j in range(len(y)):
         c = complex(x[i], y[j])
         z = complex(0, 0)
         count = mandelbrot(c, z)
         m[i, j] = count    
   return m

x = np.linspace(-2, 1, 1000)
y = np.linspace(-1, 1,1000)
m = mandelbrot_set(x, y)
plt.imshow(m.T, cmap = "magma")
plt.axis("off")
plt.show()
