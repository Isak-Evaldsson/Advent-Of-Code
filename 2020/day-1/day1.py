# Reading
inputList = [int(x.rstrip('\n')) for x in open("input.txt", "r")]

# Problem

# part 1
cartesian = [(a,b) for a in inputList for b in inputList if a != b]

for (a, b) in cartesian:
    if a + b == 2020:
        print(a*b)
        break

# part 2
cartesian3 = [(a,b,c) for a in inputList for b in inputList for c in inputList if a != b and b != c]

for (a, b, c) in cartesian3:
    if a + b + c == 2020:
        print(a*b*c)
        break    