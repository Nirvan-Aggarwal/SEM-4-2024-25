import numpy as np

arr_att = np.array([[15, 36, 90], [18, 12, 17]])

print(arr_att.ndim)       # Number of dimensions of the array
print(arr_att.shape)      # Shape of the array (rows, columns)
print(arr_att.size)       # Total number of elements in the array
print(arr_att.dtype)      # Data type of the elements in the array
print(arr_att.itemsize)   # Size in bytes of each element in the array
print(arr_att.data)       # Memory address where the array is stored
