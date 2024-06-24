import random


random_numbers = [random.randint(100, 10001) for _ in range(900)]

# Write the random numbers into a text file
with open("data.txt", "w") as file:
    for number in random_numbers:
        file.write(str(number) + "\n")
