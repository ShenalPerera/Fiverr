import math

# get the user input for the norm
norm = input("Enter desired norm name (infinity, 1-norm, 2-norm): ")

# check the given value for norm is valid
if norm == "infinity" or norm == "1-norm" or norm == "2-norm":
    result = 0
    # get the user input for the x1,y1,x2 and y2 from the user
    x1 = float(input("Enter value of coordinate value x1: "))
    y1 = float(input("Enter value of coordinate value y2: "))
    x2 = float(input("Enter value of coordinate value x2: "))
    y2 = float(input("Enter value of coordinate value y2: "))

    # handle the 1 - norm distance case
    if norm == "1-norm":
        # get the value using addition of the absolutes differences
        result = abs(x1 - x2) + abs(y1 - y2)
    # handle the 2 - norm distance case
    elif norm == "2-norm":
        # calculate the 2 - norm distance
        result = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
    else:
        result = max(abs(x1 - x2), abs(y1 - y2))

    print(f"{norm} distance value = {result:.2f}")

    # if the norm is no valid given the error message
else:
    print("Error: unknown norm")
