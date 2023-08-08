from cs50 import get_float

while True:
    change_owed = get_float("Change owed: ")
    if change_owed >= 0:
        break

change_owed = 100 * change_owed
# integer division operator, //
num_quarters = change_owed // 25
num_dimes = (change_owed - num_quarters * 25) // 10
num_nickels = (change_owed - num_quarters * 25 - num_dimes * 10) // 5
num_pennies = change_owed - num_quarters * 25 - num_dimes * 10 - num_nickels * 5

num_coins = int(num_quarters + num_dimes + num_nickels + num_pennies)
print(num_coins)
