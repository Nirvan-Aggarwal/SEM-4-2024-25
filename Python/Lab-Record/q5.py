def fact(n):
    if n == 1 or n == 0:  # Base case: factorial of 0 or 1 is 1
        return 1
    else:
        return n * fact(n - 1)  # Recursive call

num = 6
print("The factorial of", num, "is:", fact(num))