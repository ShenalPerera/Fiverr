# Get the start odometer value  as user input
start_odometer = eval(input("Enter the meter reading: "))
user_inputs = input("Enter the odometer reading <space> amount of gas used : ")

leg_gas = []
leg = 1

# Keep the total miles and gas
total_miles = 0
total_gas = 0

# keep the values as couple
while user_inputs.strip() != "":  # check the blank line

    # Cast them into float data type
    odometer = float((user_inputs.split())[0])
    gas = float((user_inputs.split())[1])

    leg_gas.append([odometer - start_odometer, gas])

    # Calculate the total miles and gas
    total_miles = total_miles + (odometer - start_odometer)
    total_gas = total_gas + gas

    # get the input as space seperated
    user_inputs = input("Enter the odometer reading <space> amount of gas used : ")
    start_odometer = odometer

for couple in leg_gas:
    # print the leg details
    print(f"Leg {leg} : {couple[0] / couple[1]} MPG")
    leg = leg + 1

print(f"\nTotal is {total_miles / total_gas} MPG")
