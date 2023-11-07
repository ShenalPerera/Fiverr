# %%writefile HW1Q1.py
##
# This program implements the 3 logic functions: and, or, not without using the (and, or, not) operators.
#
#

# YOUR CODE HERE
input1 = 0
input2 = 0

result = 0
# get th user input
logic_function = input("Enter logic function name (and, or, not):")

# check the input is valid (not, or or not)
if logic_function == "and" or logic_function == "or" or logic_function == "not":

    # if valid inputget the iput for the first A consdition
    input1 = input("Enter value of condition A:")

    # check the validity
    if input1 == "0" or input1 == "1":
        # cast input to integer value
        input1 = int(input1)

        # handle the "not" case
        if logic_function == "not":
            # perform the not function and prin the message
            result = ~input1 + 2
            print("\"not\" logic function result = ", end="")
            print(result)

        # if and or or handle case
        else:
            input2 = input("Enter value of condition B:")

            # validate the second input
            if input2 == "0" or input2 == "1":
                input2 = int(input2)

                # handle the or gate
                if logic_function == "or":
                    # perform the or operation
                    result = input1 | input2

                else:
                    # perform the and operation
                    result = input1 & input2

                # print the result
                print(f"\"{logic_function}\" logic function result = {result}")

            # print the error function if the second input is not valid
            else:
                print("either B is not a digit, has more than one digit, or is out of the 0,1 range")

    # print the error message if first input is not valid
    else:
        print("either A is not a digit, has more than one digit, or is out of the 0,1 range")
# print the error message if gate is invalid
else:
    print(Error: Unknown logic function)
