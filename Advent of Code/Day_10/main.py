# --------------------------------------------------------------------------- #
#                                                                             #
#     main.py                                        ::::      ::::::::       #
#                                                  ++: :+:   :+:    :+:       #
#     PROJECT: Advent of Code                    #:+   +:+  +:+               #
#                                              +#++:++#++: +#+                #
#                                             +#+     +#+ +#+                 #
#     AUTHOR: Jorge Lopez Puebla             ##+     #+# #+#    #+#           #
#     LAST UPDATE: 10/12/2024               ###     ###  ########             #
#                                                                             #
# --------------------------------------------------------------------------- #

# SRC: https://adventofcode.com/2024/day/10

memory: [[int]]

with open('input.txt', 'r') as file:
    memory = [[int(char) for char in line.strip()] for line in file.readlines()]

# FIRST PART: Get the sum of scores (number of trail ending 9s) of every trailhead (0)
score = 0

directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]  # Right Left Down Up

def get_trail_ends(next: int, row: int, col: int):
    global trail_ends
    for direction in directions:
        pos = [row + direction[0], col + direction[1]]
        match memory[pos[0]][pos[1]]:
            case 9:
                trail_ends.add([pos[0], pos[1]])
            case next:
                get_trail_ends(next + 1, pos[0], pos[1])
    return trail_ends

for row in range(len(memory)):
    for col in range(len(memory[row])):
        if memory[row][col] == 0:
            trail_ends = set()
            score += len(get_trail_ends(1, row, col))
