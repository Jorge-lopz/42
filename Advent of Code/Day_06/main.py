# --------------------------------------------------------------------------- #
#                                                                             #
#     main.py                                        ::::      ::::::::       #
#                                                  ++: :+:   :+:    :+:       #
#     PROJECT: Advent of Code                    #:+   +:+  +:+               #
#                                              +#++:++#++: +#+                #
#                                             +#+     +#+ +#+                 #
#     AUTHOR: Jorge Lopez Puebla             ##+     #+# #+#    #+#           #
#     LAST UPDATE: 06/12/2024               ###     ###  ########             #
#                                                                             #
# --------------------------------------------------------------------------- #

memory: [[str]] = []

# Read input file
with open('input.txt', 'r') as file:
    for line in file.readlines():
        memory.append([char for char in line])

# FIRST PART: Get the number of unique cells the guard will visit
GUARD_CHARS = ['^', '>', 'v', '<']

def get_guard():
    for row, line in enumerate(memory):
        for col, char in enumerate(line):
            if char in GUARD_CHARS:
                return [row, col]

guard: [int, int] = get_guard()
orientation = memory[guard[0]][guard[1]]

while 0 <= guard[0] < len(memory) and 0 <= guard[1] < len(memory[0]):
    memory[guard[0]][guard[1]] = 'X'
    match orientation:
        case '^':
            if memory[guard[0] - 1][guard[1]] in 'X.':
                guard[0] -= 1
            else:
                orientation = '>'
        case '>':
            if memory[guard[0]][guard[1] + 1] in 'X.':
                guard[1] += 1
            else:
                orientation = 'v'
        case 'v':
            if memory[guard[0] + 1][guard[1]] in 'X.':
                guard[0] += 1
            else:
                orientation = '<'
        case '<':
            if memory[guard[0]][guard[1] - 1] in 'X.':
                guard[1] -= 1
            else:
                orientation = '^'

unique_cells = sum(line.count('X') for line in memory)

print("\n\033[0m\033[37mThe number of unique cells the guard will visit is:\033[0m\033[1m", unique_cells)

# SECOND PART: 1933
