# --------------------------------------------------------------------------- #
#                                                                             #
#     main.py                                        ::::      ::::::::       #
#                                                  ++: :+:   :+:    :+:       #
#     PROJECT: Advent of Code                    #:+   +:+  +:+               #
#                                              +#++:++#++: +#+                #
#                                             +#+     +#+ +#+                 #
#     AUTHOR: Jorge Lopez Puebla             ##+     #+# #+#    #+#           #
#     LAST UPDATE: 01/12/2024               ###     ###  ########             #
#                                                                             #
# --------------------------------------------------------------------------- #

left_col: [int] = []
right_col: [int] = []
result: int = 0

with open('input.txt', 'r') as file:
    for line in file.read().split('\n'):
        left_col.append(int(line.split('   ')[0]))
        right_col.append(int(line.split('   ')[1]))

left_col.sort()
right_col.sort()

# Sum the differences between the smallest number on the left and right (removing already paired numbers)
while left_col and right_col:
    result += abs(left_col.pop(0) - right_col.pop(0))

print(result)
