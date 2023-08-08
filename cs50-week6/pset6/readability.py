from cs50 import get_string
import re

input = get_string("Text: ")
print(f"Text: {input}")

# find all the letters
num_chars = len(re.findall(r'[a-zA-Z]', input))
# find the number of spaces
num_words = len(re.findall(r'\s', input)) + 1
# find the number of sentences
num_sentences = len(re.findall('\.|\?|\!', input))


index = round(0.0588 * (num_chars / num_words) * 100 - 0.296 * (num_sentences / num_words) * 100 - 15.8)
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
