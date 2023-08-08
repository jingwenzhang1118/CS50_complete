from cs50 import get_string

answer = get_string("Greeting: ")
# remove leading spaces, and return lower case
answer = answer.lstrip().lower()
if answer.startswith('hello'):
    print("$0")
elif answer.startswith('hello') == False and answer.startswith('h') == True:
    print("$20")
else:
    print("$100")