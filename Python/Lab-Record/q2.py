def sum(x, y):

    return x + y

def diff(x, y):

    return x - y

def prod(x, y):

    return x * y

def div(x, y):

    return x/y

print("\nWhich operation you would like to perform??")

print("1.Addition")

print("2.Subtraction")

print("3.Multiplication")

print("4.Division")

choice=input("\nEnter choice:")

a=int(input("\nEnter number-1:"))

b=int(input("Enter number-2:"))

if choice == '1':

    print(a, "+",b, "=",sum(a,b))

elif choice == '2':

    print(a,"-",b, "=",diff(a,b))

elif choice == '3':

    print(a,"*",b,"=",prod(a,b))

elif choice == '4':

    print(a,"/",b,"=",div(a,b))