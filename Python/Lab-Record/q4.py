first = int(input("Enter first number: "))
last = int(input("Enter last number: "))

print("Prime numbers between", first, "and", last, "are:")

for n in range(first, last + 1):
    if n > 1: 
        for i in range(2, n):
            if (n % i) == 0:
                break
        else:
            print(n)