import pandas as pd

# Creating a DataFrame
book_sale_2008_list = pd.DataFrame(
    [(45, 80, 75, 40), (65, 50, 65, 75), (56, 23, 76, 88), 
     (56, 76, 49, 65), (77, 88, 65, 54), (77, 49, 75, 85)],
    columns=["SSC", "Intermediate", "Degree", "B. Tech"],
    index=["hyderabad", "kakinada", "ananthapur", "nalgonda", "mahaboobnagar", "nizamabad"]
)

# Printing the column names
print(book_sale_2008_list.columns.values)
