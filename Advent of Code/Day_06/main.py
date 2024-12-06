memory: [[str]] = []

# Read input file
with open('input.txt', 'r') as file:
    for line in file.readlines():
        memory.append([char for char in line.strip()])

# Constants
GUARD_CHARS = ['^', '>', 'v', '<']
DIRECTIONS = {'^': (-1, 0), '>': (0, 1), 'v': (1, 0), '<': (0, -1)}

# Find guard's starting position and orientation
def get_guard():
    for row, line in enumerate(memory):
        for col, char in enumerate(line):
            if char in GUARD_CHARS:
                return [row, col], char

guard, orientation = get_guard()

# Find all possible obstruction positions
def find_obstruction_positions(memory, guard):
    positions = []
    for row in range(len(memory)):
        for col in range(len(memory[0])):
            if memory[row][col] == '.' and [row, col] != guard:
                positions.append((row, col))
    return positions

# Simulate the guard's movement
def simulate_guard(memory, guard, orientation):
    visited = set()
    guard_pos = guard[:]
    memory_copy = [row[:] for row in memory]

    while True:
        state = (tuple(guard_pos), orientation)
        if state in visited:
            return True  # Loop detected
        visited.add(state)

        # Move guard based on orientation
        dx, dy = DIRECTIONS[orientation]
        next_pos = [guard_pos[0] + dx, guard_pos[1] + dy]

        # Check if the next position is valid
        if (
                0 <= next_pos[0] < len(memory_copy)
                and 0 <= next_pos[1] < len(memory_copy[0])
                and memory_copy[next_pos[0]][next_pos[1]] in 'X.'
        ):
            guard_pos = next_pos
        else:
            # Change orientation
            orientation = {'^': '>', '>': 'v', 'v': '<', '<': '^'}[orientation]

        # If guard moves outside bounds, stop simulation
        if not (0 <= guard_pos[0] < len(memory_copy) and 0 <= guard_pos[1] < len(memory_copy[0])):
            break

    return False  # No loop detected

# Main logic to find valid obstructions
def find_valid_obstructions(memory, guard, orientation):
    valid_positions = []
    possible_positions = find_obstruction_positions(memory, guard)

    for pos in possible_positions:
        # Place obstruction
        memory[pos[0]][pos[1]] = '#'
        if simulate_guard(memory, guard, orientation):
            valid_positions.append(pos)
        # Remove obstruction
        memory[pos[0]][pos[1]] = '.'

    return valid_positions

# Find and print results
valid_obstructions = find_valid_obstructions(memory, guard, orientation)
print("\nThe number of valid obstruction positions is:", len(valid_obstructions))
print("Positions are:", valid_obstructions)
