# imports
import math

# Reading
forest = [list(x.rstrip('\n')) for x in open("./input.txt", "r")] 

# Solution
def slope(right, down):
    nbrOfTrees = 0
    x = 0

    for y in range(down, len(forest), down):
        x = x + right

        if forest[y][x % len(forest[0])] == '#':
            nbrOfTrees += 1

    return nbrOfTrees

# Caluculating result
cases = [(1, 1), (3, 1), (5, 1), (7, 1), (1, 2)]
slopes = map(lambda pair: slope(*pair), cases)
print(math.prod(slopes))