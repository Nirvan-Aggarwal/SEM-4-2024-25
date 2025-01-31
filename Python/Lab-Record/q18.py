import pandas as pd

# List of tuples
data = [
    (1, 'John', 24),
    (2, 'Jane', 27),
    (3, 'Smith', 22),
    (4, 'Emily', 25)
]

# Column names
columns = ['ID', 'Name', 'Age']

# Creating the DataFrame
df = pd.DataFrame(data, columns=columns)

# Displaying the DataFrame
print("Pandas DataFrame:")
print(df)
