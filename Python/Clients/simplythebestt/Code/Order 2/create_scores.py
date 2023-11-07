import random

with open("histogram.txt", "w") as file:
    for i in range(0, 1000):
        file.write(str(random.randint(0, 10))+"\n")
