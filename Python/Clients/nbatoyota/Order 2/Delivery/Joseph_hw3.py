thermostat_state = int(input("Set the Thermostat to (1-AC, 2-Heating, 0-None): "))
low_temp = int(input("Low temperature for heating (F): "))
high_temp = int(input("High temperature for AC (F): "))

is_AC_on = int(input("Is the AC on (1-yes, 0-No): "))
is_heater_on = int(input("Is the Heater on (1-yes, 0-No): "))

current_temp = int(input("Current temperature (F): "))

if is_AC_on == 1:
    print(f"[Setting={thermostat_state} AC=ON Heater=OFF Low={low_temp} High={high_temp} Temp={current_temp}]")
elif is_heater_on == 1:
    print(f"[Setting={thermostat_state} AC=OFF Heater=ON Low={low_temp} High={high_temp} Temp={current_temp}]")
else:
    print(f"[Setting={thermostat_state} AC=OFF Heater=OFF Low={low_temp} High={high_temp} Temp={current_temp}]")

if thermostat_state == 1:
    if current_temp > high_temp:
        if is_AC_on == 0:
            is_AC_on = 1
            is_heater_on = 0
            print("*** Turn on the AC")

    if current_temp < high_temp:
        if is_AC_on == 1:
            is_AC_on = 0
            print("*** Turn off the AC")
        else:
            print("Temperature below the high setting")

if thermostat_state == 2:
    if current_temp < low_temp:
        if is_heater_on == 0:
            is_heater_on = 1
            is_AC_on = 0
            print("*** Turn on the heater")
    if current_temp > low_temp:
        if is_heater_on == 1:
            is_AC_on = 0
            print("*** Turn off the heater")
        else:
            print("Temperature above the high setting")

if is_AC_on == 1:
    print(f"[Setting={thermostat_state} AC=ON Heater=OFF Low={low_temp} High={high_temp} Temp={current_temp}]")
elif is_heater_on == 1:
    print(f"[Setting={thermostat_state} AC=OFF Heater=ON Low={low_temp} High={high_temp} Temp={current_temp}]")
else:
    print(f"[Setting={thermostat_state} AC=OFF Heater=OFF Low={low_temp} High={high_temp} Temp={current_temp}]")
