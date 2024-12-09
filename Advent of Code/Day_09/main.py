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
# 15846256445880 too high
# 6373055193464 is right

"""
get_disk()
file_sizes = {i: memory[i * 2 + 1] for i in range(len(memory) // 2)}

for file in reversed(file_sizes.keys()):
    for i in range(disk.index(str(file))):
        i_temp = 0
        while i + i_temp < disk.index(str(file)) and disk[i + i_temp] == '.':
            i_temp += 1
        if i_temp == 0:
            continue
        if file_sizes.get(file) * len(str(file)) <= i_temp:
            disk = [char for char in ''.join(disk).replace(str(file), '.' * len(str(file)))]
            disk[i:i + i_temp] = [str(file)] * file_sizes.get(file) + ['.'] * (i_temp - file_sizes.get(file))
            break
"""

def compute_checksum(files):
    pos = checksum = 0
    for n in files:
        for _ in range(int(n.real)):
            if n.imag != 0:
                checksum += pos * (n.imag - 1)
            pos += 1
    return int(checksum)

disk = [memory[i - 2] + (1 - i % 2) * i * .5j for i in range(2, len(memory) + 2)]

l, r = 1, len(disk) - 1

while r > 0:
    l = 1

    # Find the next file from the right
    while disk[r].imag == 0:
        r -= 1

    # Find the first free space, where the entire file can fit
    while l < len(disk) and not (disk[l].imag == 0 and disk[l].real >= disk[r].real):
        l += 1

    if l < len(disk) and l < r:
        # Switch the file with the free space
        disk[l] -= disk[r].real
        disk[r - 1] += disk[r].real  # In this part, free space preservation is necessary!
        disk.insert(l, disk.pop(r))

    r -= 1

print(disk)

# print('\n\033[0m\033[37mThe checksum (without fragmentation) is:\033[0m\033[1m', get_checksum(disk))
print('\n\033[0m\033[37mThe checksum (without fragmentation) is:\033[0m\033[1m', compute_checksum(disk))
