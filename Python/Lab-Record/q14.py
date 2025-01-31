import numpy as np

# Creating numpy arrays
arr1 = np.array([5, 8, 4, 6, 3, 7, 2, 9, 1, 0])
arr2 = np.array([12, 15])

# Printing the original array
print("Original Array: ", arr1)

# Printing the shape of the array
print("Shape of array: ", arr1.shape)

# Indexing: Accessing the 4th element (index 4)
print("Indexing: ", arr1[4])

# Slicing: Extracting elements from index 6 to 8
print("Slicing: ", arr1[6:9])

# Reshaping the array into 2 rows and 5 columns
print("Reshaping: \n", arr1.reshape(2, 5))

# Concatenating arr1 and arr2
print("Concatenation: ", np.concatenate([arr1, arr2]))

# Splitting the array into three parts
x1, x2, x3 = np.split(arr1, [3, 6])
print("Splitting: ", x1, x2, x3)
