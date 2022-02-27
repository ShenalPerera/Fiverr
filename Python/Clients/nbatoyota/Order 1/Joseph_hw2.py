import math

# Get the user input and cast them to floats
x1 = float(input("For P1, Please enter the x-coordinate: "))
y1 = float(input("For P1, Please enter the y-coordinate: "))
x2 = float(input("For P2, Please enter the x-coordinate: "))
y2 = float(input("For P2, Please enter the y-coordinate: "))

# calculate the distance using sqrt function and pow function
distance = math.sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))

# calculate the area using abs function
area = abs(x2 - x1) * abs(y2 - y1)

# print the results
print(end="\n\n")

print(f"The two points are: P1 = ({x1:.2f}, {y1:.2f}), and P2 = ({x2:.2f}, {y2:.2f}).")
print(f"The distance between the two points P1 and P2 is {distance:.5f}.")
print(f"The area of the rectangle bounded by P1 and P2 is {area:.5f}", end=".")
