# Reading
lines = [x.rstrip('\n') for x in open("./input.txt", "r")]

# part 1 
valid = 0

for line in lines:
    (span, char, password) = line.split()
    (min, max) = map(lambda x: int(x), span.split('-'))
    nbrOfChar = password.count(char[0])

    if min <= nbrOfChar <= max:
        valid += 1

print("part 1 awnser:", valid)

# part 2
valid = 0

for line in lines:
    (indexes, char, password) = line.split()
    (first, second) = map(lambda x: int(x) - 1, indexes.split('-'))

    if (password[first] == char[0]) ^ (password[second] == char[0]):
        valid += 1

print("part 2 awnser:", valid)