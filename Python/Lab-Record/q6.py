line = input("Enter the string: ")

ch = list(line)

flag = True  # Initialize flag as True

for i in range(0, len(ch)):
    if ch[i] != ch[len(ch) - i - 1]:  # Check if characters are not the same
        flag = False  # Set flag to False if mismatch found
        break

if flag:  # If flag remains True, it's a palindrome
    print("The string is a Palindrome")
else:
    print("The string is not a Palindrome")
