"""
    * lists that contain area code and relevant cities that belongs to that code
    * First element in each list contain the area code
"""
code305 = ["305", "miami dade country", "florida keys"]
code321 = ["321", "orlando"]
code353 = ["353", "gainesville", "ocala", "inverness", "spring hill", "dunnellon", "central florida"]
code386 = ["386", "daytona beach", "lake city", "live oak", "crescent city"]
code448 = ["448", "pensacola", "tallahassee", "panama city"]
code561 = ["561", "west palm beach", "boca raton", "boynton beach", "delray beach", "belle glade"]
code754o954 = ["754", "fort lauderdale", "hollywood", "coral springs"]
code772 = ["772", "vero beach", "port saint lucie", "fort pierce", "sebastian", "stuart"]
code904 = ["904", "jacksonville", "st. augustine", "starke", "green cove springs"]

# list to hold all cities and area code of city in florida region
citiesAndCodes = [code305, code321, code353, code386, code448, code561, code754o954, code772, code904]


# Function to print the menu and get input from the user
def menu():
    print("--------------Menu----------------")
    print("1. Get the area code for a city")
    print("2. Get all cities by area code")
    print("3. Get all cities and area code in florida region")
    print("0. Exit")
    return int(input("Enter your option: "))


# Function to print the area code and the relevant cities to that code
def display_cities(list):
    print("Area code : " + list[0])
    for count in range(1, len(list)):
        print(list[count].upper())
    print()


value = menu()
isFound = False

while value != 0:
    if value == 1:
        cityName = input("Enter the name of the city: ")

        for code in citiesAndCodes:
            if cityName.lower() in code:
                isFound = True
                print("The area code of " + cityName + ": " + code[0])

        if not isFound:
            print("Given name is incorrect or not belongs to Florida region")

    elif value == 2:
        areaCode = input("Enter the area code: ")
        isFound = False
        for code in citiesAndCodes:
            if areaCode == code[0]:
                isFound = True
                display_cities(code)

        if not isFound:
            print("Invalid Area code!")

    elif value == 3:
        for code in citiesAndCodes:
            display_cities(code)

    else:
        print("Invalid Input!")
    print()
    isFound = False
    value = menu()
