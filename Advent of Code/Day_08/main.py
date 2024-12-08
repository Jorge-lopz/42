# --------------------------------------------------------------------------- #
#                                                                             #
#     main.py                                        ::::      ::::::::       #
#                                                  ++: :+:   :+:    :+:       #
#     PROJECT: Advent of Code                    #:+   +:+  +:+               #
#                                              +#++:++#++: +#+                #
#                                             +#+     +#+ +#+                 #
#     AUTHOR: Jorge Lopez Puebla             ##+     #+# #+#    #+#           #
#     LAST UPDATE: 08/12/2024               ###     ###  ########             #
#                                                                             #
# --------------------------------------------------------------------------- #

memory: [[str]] = []
antennas: {str: [[int, int]]} = {}

# Read input file
with open('input.txt', 'r') as file:
    for row, line in enumerate(file.readlines()):
        line_chars = []
        for col, char in enumerate(line.strip()):
            line_chars.append(char)
            if char.isdigit() or char.isupper() or char.islower():
                antennas.setdefault(char, []).append([row, col])
        memory.append(line_chars)

# FIRST PART: Count the number of antinodes
antinodes: ([int, int]) = set()

for freq, positions in antennas.items():
    if len(positions) < 2:
        continue
    for antenna in positions:
        for other_antenna in positions:
            if antenna == other_antenna:
                continue
            dx, dy = other_antenna[0] - antenna[0], other_antenna[1] - antenna[1]
            for antinode in [[antenna[0] - dx, antenna[1] - dy], [other_antenna[0] + dx, other_antenna[1] + dy]]:
                if 0 <= antinode[0] < len(memory) and 0 <= antinode[1] < len(memory[0]):
                    antinodes.add(tuple(antinode))
                    # print(f"Antinode: {antinode} <- {antenna} {other_antenna}")

print("\n\033[37mThe number of unique antinodes is:\033[0m\033[1m", len(antinodes))

# SECOND PART
