# create dictionary of relevant month and its days (1-31,2-28,...,12-31)
dates = {1: 31, 2: 28, 3: 31, 4: 30, 5: 31, 6: 30, 7: 31, 8: 31, 9: 30, 10: 31, 11: 30, 12: 31}  # this is used to
# validate the date

# get the date from the user
userInput = input("Enter the date: ")

# Split the date into year, month and the date
month, day, year = userInput.split("/")  # split by the "/"

# Convert them into the integers
year = int(year)
month = int(month)
day = int(day)

# Validating the date
isLeap = False  # Flag to identify whether given date is leap year

'''
    If a year is divisible by 100, but not 400, then it is not a leap year. If a year is divisible by both 100 and 400, 
    then it is a leap year
'''

if year % 100 == 0 and year % 400 == 0:  # condition wrap into the if statement
    isLeap = True
    dates[2] = 29

# Validate the date using dates dictionary and the above flag
'''
    Given month must be 1 - 12 and date 1 - (depend on the month)
'''

# Hold the number count
dayNum = 0

if 1 <= month <= 12:
    if 1 <= day <= dates[month]:  # Second condition wrap into if statement
        dayNum = 31 * (month - 1) + day  # Normal arithmetic

        if month > 2:  # if the month is after february
            dayNum = dayNum - ((4 * month + 23) // 10)

        if month > 2 and isLeap:  # leap year and after february
            dayNum = dayNum + 1

        print(f"{month}/{day}/{year} is {dayNum} of the year {year}")
    else:
        print("Not a valid date")
else:
    print("Not a valid date")
