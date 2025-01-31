import pandas as pd

# 2-dimensional list
data = [
    [1, 'Alice', 85],
    [2, 'Bob', 90],
    [3, 'Charlie', 78],
    [4, 'David', 92]
]

# Column names
columns = ['ID', 'Name', 'Score']

# Creating a DataFrame
df = pd.DataFrame(data, columns=columns)

# Displaying the DataFrame
print("Pandas DataFrame:")
print(df)
