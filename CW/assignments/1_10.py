input = input("Введите число в двоичной форме: ")

number = int(input, 2)

if (number % 15 == 0):
    print(number, "делится на 15")
else:
    print(number, "не делится на 15")
