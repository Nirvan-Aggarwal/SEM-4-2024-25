import numpy as np

# Creating a 2D numpy array
Arr = np.array([[1, 4, 5, 8, 9], [2, 3, 6, 7, 10]])

# Printing the array
print("Array:\n", Arr)

print("==========")

# Calculating the sum of elements along columns (axis=0)
print("Sum of elements (along columns):", np.sum(Arr, axis=0))

# Finding the minimum value along columns (axis=0)
print("Minimum value (along columns):", np.min(Arr, axis=0))

# Finding the maximum value along rows (axis=1)
print("Maximum value (along rows):", np.max(Arr, axis=1))

# Calculating the mean of the array along rows (axis=1)
print("Mean of Array (along rows):", np.mean(Arr, axis=1))
