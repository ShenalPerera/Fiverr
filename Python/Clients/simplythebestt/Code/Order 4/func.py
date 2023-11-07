# Function to squares
def squareEach(nums):
    # Go through the nums list
    for index in range(len(nums)):
        nums[index] = nums[index] * nums[index]  # update the nums list such as each position square its own

    return nums  # return the list


# function definition for sumList
def sumList(nums):
    total = 0  # initialize the sum to 0

    for number in nums:  # loop through the numbers
        total = total + number  # update the total cumulative

    return total


# function definition for toNumbers
def toNumbers(strList):
    # loop through by index of the list
    for index in range(len(strList)):
        strList[index] = int(strList[index])  # convert string to int and update ots own position


# The program

# get the file name from the user
fileName = input("Please enter the file name: ")

with open(fileName, "r") as file:
    # read the all lines
    lines = file.readlines()
    # create a strList from the split function from given lines (1st line)
    strNumberList = (lines[0]).split()
    toNumbers(strNumberList)  # using the function toNumbers get the integer numbers list
    squareEach(strNumberList)  # update the list with its own square number

    # print the sum of squares of given list
    print(f"Sum of the squares of the values in the list is {sumList(strNumberList)}")