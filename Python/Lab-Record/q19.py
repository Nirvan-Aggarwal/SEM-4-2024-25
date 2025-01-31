import pandas as pd

# Creating a DataFrame
df = pd.DataFrame({
    'Name': ['Alice', 'Bob', 'Charlie', 'David'],
    'Age': [25, 30, 35, 40],
    'City': ['New York', 'Los Angeles', 'Chicago', 'Houston']
})

# Iterating using itertuples (preferred for performance)
for row in df.itertuples():
    print(f"Name: {row.Name}, Age: {row.Age}, City: {row.City}")
