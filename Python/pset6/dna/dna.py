from csv import reader, DictReader
from sys import argv

# read the dna sequence from the file
with open(argv[2]) as dnafile:
    dnareader = reader(dnafile)
    for row in dnareader:
        dnalist = row

# store it in a string
dna = dnalist[0]
AGATC = 0
AATG = 0
TATC = 0
# create a dictionary with the sequences we intend to count
sequences = {
    "AGATC": 1,
    "AATG": 1,
    "TATC": 1
}

# iterate trough the dna sequence, when it finds repetitions of the values from sequence dictionary it counts them
for i in range(len(dna)):
    temp = 0

    if dna[i: i + 4] == "AATG":
        while dna[i - 4: i] == dna[i: i + 4]:
            temp += 1
            i += 4
            # it compares the value to the previous longest sequence and if it is longer it overrides it
            if temp > AATG:
                AATG = temp

    elif dna[i: i + 4] == "TATC":
        while dna[i - 4: i] == dna[i: i + 4]:
            temp += 1
            i += 4
            if temp > TATC:
                TATC = temp

    elif dna[i: i + 5] == "AGATC":
        while dna[i - 5: i] == dna[i: i + 5]:
            temp += 1
            i += 5
            if temp > AGATC:
                AGATC = temp

# store the longest sequences in the dictionary
sequences["AGATC"] += AGATC
sequences["AATG"] += AATG
sequences["TATC"] += TATC

# open and iterate trough the database of people treating each one like a dictionary so it can compare to the sequences one
with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        # compares the three sequences to every person and prints name before leaving the program if there is a match
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == 3:
            print(person['name'])
            exit()
    print("No match")
