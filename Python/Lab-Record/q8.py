List1 = []  # Creating an empty list

List2 = [5, 7, 1, 4, 9]  # Creating a list with elements

List3 = list(range(1, 5))  # Creating a list using the range method

print("List1:", List1)
print("List2:", List2)
print("List3:", List3)

List1.append(53)  # Appending 53 to List1
List1.append(10)  # Appending 10 to List1
List1.append(47)  # Appending 47 to List1

print("List1 after append:", List1)

List1.remove(10)  # Removing 10 from List1
print("List1 after remove:", List1)
