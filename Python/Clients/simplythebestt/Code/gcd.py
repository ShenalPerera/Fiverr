terminate = False

# Do computation until user want to terminate
while not terminate:
    n = int(input("Enter the number (n): "))
    m = int(input("Enter the number (m): "))

    # handle the negative and zeros
    if n <= 0 or m <= 0:
        print("n,m should be positive integers")
        continue

    # swap the values if n is less than m
    if n < m:
        temp = n
        n = m
        m = temp

    # store the numbers to show to users
    num1 = n
    num2 = m

    # Euclid's Algorithm
    while m != 0:
        temp = m
        m = n % m
        n = temp

    # print the result to the user
    print(f"GCD({num1},{num2}) is {n}")

    answer = input("Do you want to another computation: ")
    answer = answer.lower()

    if answer == "n" or answer == "no":
        terminate = True
    elif answer == 'y' or answer == "yes":
        terminate = False
    else:
        print("Invalid input!")
        break
