"""
    Author: shenal_33
    Date: 26/03/2022
"""

import pandas as pd

'''
    This script will read the csv file in the given directory and create a dataframe with th given values.
'''

# Read the csv file
df = pd.read_csv("Assessment Records Input.csv", delimiter=",")

# Uniques codes and postfixes for output column fields
codes = [11, 12, 20, 30, 31, 32, 40, 51, 52, 60, 70, 80]
postfix = ["LAN", "BLD"]

# current year
year = 2021
# Create the column names for the output data frame
columnNames = ["CLASS" + str(code) + word for code in codes for word in postfix]
columnNames.append("YEAR")

# get the unique roll numbers (without duplicates)
roll_number = df['dROLLNMBR'].unique()
out_df = pd.DataFrame(index=roll_number, columns=columnNames).fillna(0)
out_df.index.name = "ROLL"

out_df['YEAR'] = year

for index in range(len(roll_number)):
    temp_df = df.loc[df['dROLLNMBR'] == roll_number[index]]
    unique_assescd = temp_df['dASSESSCD'].unique()

    for assescd in unique_assescd:
        selected_df = df.loc[(df['dASSESSCD'] == assescd) & (df['dROLLNMBR'] == roll_number[index])]

        out_df.loc[roll_number[index], "CLASS" + str(assescd) + "LAN"] = selected_df['dASSESSVALLAND'].sum()
        out_df.loc[roll_number[index], "CLASS" + str(assescd) + "BLD"] = selected_df['dASSESSVALIMPR'].sum()

out_df.to_csv('output.csv')
