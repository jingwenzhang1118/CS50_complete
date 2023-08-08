from cs50 import get_string
from pyfiglet import Figlet
import csv
import random
import sys

figlet = Figlet()
font_names = figlet.getFonts()
num_fonts = len(font_names)


if len(sys.argv) == 1:
    input = get_string("Input: ")
    # randomly choose a font from the font list
    figlet.setFont(font=font_names[random.randrange(num_fonts)])
    print("Output: ")
    print(figlet.renderText(input))

# check if element is in a list, if (element in list)
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] =="--font") and sys.argv[2] in font_names:
    input = get_string("Input: ")
    figlet.setFont(font=sys.argv[2])
    print("Output: ")
    print(figlet.renderText(input))

else:
    print("Invalid Usage")
    sys.exit(1)


"""
# append data from a csv file to a list
font_names = []
with open("Book1.csv", "r") as file:
    for row in file:
        # remove the newline character from strings
        font_names.append(row.replace("\n", ""))
print(font_names)

font_names = ['3-d', '3x5', '5lineoblique', 'acrobatic', 'alligator', 'alligator2', 'alphabet', 'avatar', \
    'banner', 'banner3-D', 'banner3', 'banner4', 'barbwire', 'basic', 'bell', 'big', 'bigchief', 'binary', \
    'block', 'bubble', 'bulbhead', 'calgphy2', 'caligraphy', 'catwalk', 'chunky', 'coinstak', 'colossal', \
    'computer', 'contessa', 'contrast', 'cosmic', 'cosmike', 'cricket', 'cursive', 'cyberlarge', \
    'cybermedium', 'cybersmall', 'diamond', 'digital', 'doh', 'doom', 'dotmatrix', 'drpepper', \
    'eftichess', 'eftifont', 'eftipiti', 'eftirobot', 'eftitalic', 'eftiwall', 'eftiwater', \
    'epic', 'fender', 'fourtops', 'fuzzy', 'goofy', 'gothic', 'graffiti', 'hollywood', \
    'invita', 'isometric1', 'isometric2', 'isometric3', 'isometric4', 'italic', 'ivrit', 'jazmine', 'jerusalem', \
    'katakana', 'kban', 'larry3d', 'lcd', 'lean', 'letters', 'linux', 'lockergnome', 'madrid', 'marquee', 'maxfour', \
    'mike', 'mini', 'mirror', 'mnemonic', 'morse', 'moscow', 'nancyj-fancy', 'nancyj-underlined', 'nancyj', 'nipples', \
    'ntgreek', 'o8', 'ogre', 'pawp', 'peaks', 'pebbles', 'pepper', 'poison', 'puffy', 'pyramid', 'rectangles', 'relief', \
    'relief2', 'rev', 'roman', 'rot13', 'rounded', 'rowancap', 'rozzo', 'runic', 'runyc', 'sblood', 'script', 'serifcap', \
    'shadow', 'short', 'slant', 'slide', 'slscript', 'small', 'smisome1', 'smkeyboard', 'smscript', 'smshadow', 'smslant', \
    'smtengwar', 'speed', 'stampatello', 'standard', 'starwars', 'stellar', 'stop', 'straight', 'tanja', 'tengwar', 'term', \
    'thick', 'thin', 'threepoint', 'ticks', 'ticksslant', 'tinker-toy', 'tombstone', 'trek', 'tsalagi', 'twopoint', 'univers', \
    'usaflag', 'wavy', 'weird']

"""