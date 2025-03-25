import numpy as np
a=np.array([[1,2],[3,4]])
print (a)
print(a.ndim)#dimension of array
print(a.shape)#shape of array
print(a.itemsize)#size of each element in bytes
print(a.dtype)#data type of array
print(a.size)#size of array
print(a.reshape(4,1))#reshaping the array
b=a.copy()#copying the array
print(np.concatenate((a,b)))#concatenating the array
