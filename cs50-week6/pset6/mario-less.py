from cs50 import get_int

while True:
    n = get_int("Height: ")
    # range() the stop number is not inclusive
    if n in range(1, 9):
        break

for i in range(n):
    # print spaces before the hastags
    print(" " * (n - i - 1), end='')
    # print hastags
    print("#" * (i + 1), end='')
    print()
