# --------------------------------------------------------------------------- #
#                                                                             #
#     main.py                                        ::::      ::::::::       #
#                                                  ++: :+:   :+:    :+:       #
#     PROJECT: Advent of Code                    #:+   +:+  +:+               #
#                                              +#++:++#++: +#+                #
#                                             +#+     +#+ +#+                 #
#     AUTHOR: Jorge Lopez Puebla             ##+     #+# #+#    #+#           #
#     LAST UPDATE: 09/12/2024               ###     ###  ########             #
#                                                                             #
# --------------------------------------------------------------------------- #

disk = []

# Read input file
with open('input.txt', 'r') as file:
    memory = list(map(int, file.read().strip()))

def get_disk():
    global disk
    j = 0
    disk = []

    for i, num in enumerate(memory):
        if i % 2 == 0:
            disk.extend([str(j)] * num)  # Extend list with repeated numbers
            j += 1
        else:
            disk.extend(['.'] * num)  # Extend list with dots

def get_checksum(disk: list):
    return sum(int(char) * i if char != '.' else 0 for i, char in enumerate(disk))

"""
# FIRST PART: Sort the disk visual representation to leave all the free space at the end and compress the 'files'
get_disk()

first_dot_index = disk.index('.')
last_non_dot_index = len(disk) - 1

while first_dot_index < last_non_dot_index:
    # Swap the first '.' with the last non-dot character
    disk[first_dot_index], disk[last_non_dot_index] = disk[last_non_dot_index], '.'
    first_dot_index = disk.index('.')
    last_non_dot_index -= 1

print('\n\033[37mThe checksum is:\033[0m\033[1m', get_checksum(disk))
"""
# SECOND PART: Similar to the first part but only moving whole files together
get_disk()
# 15846256445880 too high
#
file_sizes = {i: memory[i * 2 + 1] for i in range(len(memory) // 2)}
print(file_sizes)

for file in reversed(file_sizes.keys()):
    for i in range(len(disk)):
        i_temp = 0
        while i + i_temp < disk.index(str(file)) and disk[i + i_temp] == '.':
            i_temp += 1
        if i_temp == 0:
            continue
        if file_sizes.get(file) * len(str(file)) <= i_temp:
            disk = [char for char in ''.join(disk).replace(str(file), '.' * len(str(file)))]
            disk[i:i + i_temp] = [str(file)] * file_sizes.get(file) + ['.'] * (i_temp - file_sizes.get(file))
            break

print('\n\033[0m\033[37mThe checksum (without fragmentation) is:\033[0m\033[1m', get_checksum(disk))
