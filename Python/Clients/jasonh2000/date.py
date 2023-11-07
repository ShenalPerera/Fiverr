import datetime, time

SECONDS_IN_YEAR = 365 * 60 * 60 *24
SECONDS_IN_DAY  = 60 * 60 * 24
SECONDS_IN_HOUR = 60 * 60
SECONDS_IN_MINUTE = 60

# get the user input from user for year,month and day
year = int(input("Please enter your birth year :"))
month = int(input("Please enter month of your birth : "))
day = int(input("Please enter day of your birth  : "))

#create time object using python inbuilt module
current_date = datetime.datetime.now()
current_date_f_number = time.mktime(current_date.timetuple())   # convert it into seconds

# convert birthday into the floating point number
birthday = datetime.datetime(year,month,day,0,0)
birthday_f_number = time.mktime(birthday.timetuple())

# calculate the difference in seconds
time_diff = current_date_f_number - birthday_f_number
time_diff = int(time_diff)

# calculate the years, month and days from dividing time difference
number_of_years = time_diff // SECONDS_IN_YEAR
time_diff = time_diff % SECONDS_IN_YEAR

number_of_days = time_diff // SECONDS_IN_DAY
time_diff = time_diff % SECONDS_IN_DAY

number_of_hours = time_diff // SECONDS_IN_HOUR
time_diff = time_diff % SECONDS_IN_HOUR

number_of_minutes = time_diff // SECONDS_IN_MINUTE
number_of_seconds = time_diff % SECONDS_IN_MINUTE

print(f"your birthday is {day}/{month}/{year} ({number_of_years} years, {number_of_days} days, {number_of_hours} hours, {number_of_minutes} minutes, and {number_of_seconds} ago.)")