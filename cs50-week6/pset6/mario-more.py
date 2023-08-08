from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n in range(1, 9):
        break

for i in range(n):
    print(" " * (n - i - 1), end='')
    print("#" * (i + 1), end='')
    print("  ", end='')
    print("#" * (i + 1))