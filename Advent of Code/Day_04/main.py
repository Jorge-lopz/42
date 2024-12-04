# --------------------------------------------------------------------------- #
#                                                                             #
#     main.py                                        ::::      ::::::::       #
#                                                  ++: :+:   :+:    :+:       #
#     PROJECT: Advent of Code                    #:+   +:+  +:+               #
#                                              +#++:++#++: +#+                #
#                                             +#+     +#+ +#+                 #
#     AUTHOR: Jorge Lopez Puebla             ##+     #+# #+#    #+#           #
#     LAST UPDATE: 04/12/2024               ###     ###  ########             #
#                                                                             #
# --------------------------------------------------------------------------- #

memory: [[str]]

with open('input.txt', 'r') as file:
    memory = [list(line.strip()) for line in file.readlines()]

# FIRST PART: Get the number of times 'XMAS' appears in any direction on the input text
target = 'XMAS'
result = 0
rows = len(grid)
cols = len(grid[0])

directions = [
    (0, 1),  # Right
    (0, -1),  # Left
    (1, 0),  # Down
    (-1, 0),  # Up
    (1, 1),  # Down-right
    (-1, -1),  # Up-left
    (1, -1),  # Down-left
    (-1, 1)  # Up-right
]

# Function to check for "XMAS" in a specific direction
def check_direction(x, y, dx, dy):
    for i in range(len(target)):
        nx, ny = x + i * dx, y + i * dy
        if nx < 0 or ny < 0 or nx >= rows or ny >= cols or memory[nx][ny] != target[i]:
            return False
    return True

# Search the grid
for x in range(rows):
    for y in range(cols):
        for dx, dy in directions:
            if check_direction(x, y, dx, dy):
                result += 1

print("\n\033[37mThe number of 'XMAS' is:\033[0m\033[1m", result)
