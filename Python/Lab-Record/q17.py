import pandas as pd
import numpy as np

# Dictionary with NumPy arrays and lists
data = {
    "Column1": np.array([1, 2, 3, 4]),  # NumPy array
    "Column2": [5, 6, 7, 8],            # List
    "Column3": np.array(['A', 'B', 'C', 'D'])  # NumPy array
}

# Creating DataFrame
df = pd.DataFrame(data)

# Display the DataFrame
print(df)
