import numpy as np

# Creating a 1D numpy array
arr1 = np.array([23, 43, 56, 78])
print(arr1)
print(type(arr1))
print(arr1.dtype)  # Returns the type of elements in arr1

# Creating another 1D numpy array with float values
arr2 = np.array([8.5, 8.7, 2.5, 4.2])  
print(arr2)
print(arr2.dtype)  # Returns the datatype of elements in arr2

# Creating a 2D numpy array
arr3 = np.array([[78, 14, 56], [25, 36, 78]])
print(arr3)  # Printing the 2D array

# Creating another 2D numpy array with tuples
arr3_tuple = np.array(((14, 25, 47), (25, 62, 35)))
print(arr3_tuple)

# Creating a numpy array with a specified dtype
arr1_dtype = np.array([23, 43, 56, 78], dtype=np.float64)  # Converts 'int' to 'float'
print(arr1_dtype)
print(arr1_dtype.dtype)  # Checking the dtype
