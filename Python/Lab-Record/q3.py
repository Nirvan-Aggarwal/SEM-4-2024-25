n = int(input("Enter value of n: "))
s = 0
tmp = n

while tmp > 0:
    dgt = tmp % 10
    s += (dgt * dgt * dgt)
    tmp //= 10
if n == s:
    print(n, "is an Armstrong number")
else:
    print(n, "is not an Armstrong number")