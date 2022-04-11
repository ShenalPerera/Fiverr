# import the libraries
import pandas as pd

# read StudentMajorsList.csv and Organize the data
student_majors_df = pd.read_csv("./inputs/StudentsMajorsList.csv", delimiter=",", header=None)
student_majors_df.columns = ["Student_ID", "Last_name", "First_name", "Major", "Disciplinary"]
student_majors_df = student_majors_df.set_index('Student_ID')

# read GPAList.csv and Organize the data
student_gpa_df = pd.read_csv("./inputs/GPAList.csv", delimiter=",", header=None)
student_gpa_df.columns = ["Student_ID", "GPA"]
student_gpa_df = student_gpa_df.set_index('Student_ID')

# read GraduationDatesList.csv and Organize the data
student_graduation_df = pd.read_csv("./inputs/GraduationDatesList.csv", delimiter=",", header=None)
student_graduation_df.columns = ["Student_ID", "Date"]
student_graduation_df = student_graduation_df.set_index('Student_ID')

# Write the inventory reports into FullRoster.csv file
full_roster = []
student_IDs = student_majors_df.index

for id in student_IDs:
    try:
        temp = [id, student_majors_df.loc[id, 'Major'], student_majors_df.loc[id, 'First_name'],
                student_majors_df.loc[id, 'Last_name'], student_gpa_df.loc[id, 'GPA'],
                student_graduation_df.loc[id, 'Date'], student_majors_df.loc[id, 'Disciplinary']]
        full_roster.append(temp)
    except KeyError:
        pass
full_roster_df = pd.DataFrame(full_roster, columns=["ID", "Major", "Fname", "Lname", "GPA", "Date", "Disciplinary"])
full_roster_df.sort_values(by=["Lname"], ascending=True, inplace=True)
full_roster_df.to_csv("./outputs/FullRoster.csv", header=False, index=False)

# Create different csv files for each majors
headers = ["Student_ID", "Lname", "Fname", "Gdate", "Disciplinary"]
majors = student_majors_df["Major"].unique()

for major in majors:
    temp_list = []
    student_IDs = student_majors_df[student_majors_df['Major'] == major].index

    for id in student_IDs:
        try:
            temp = [id, student_majors_df.loc[id, 'Last_name'], student_majors_df.loc[id, 'First_name'],
                    student_graduation_df.loc[id, 'Date'], student_majors_df.loc[id, 'Disciplinary']]
            temp_list.append(temp)
        except KeyError:
            pass
    filename = str(major).replace(" ", "") + ".csv"
    full_roster_df = pd.DataFrame(temp_list, columns=["ID", "Lname", "Fname", "Date", "Disciplinary"])
    full_roster_df.sort_values(by=["ID"], ascending=True, inplace=True)
    full_roster_df.to_csv("./outputs/" + filename, header=False, index=False)

# Write disciplinary csv file
discipline = []
student_IDs = student_majors_df[student_majors_df['Disciplinary'] == 'Y'].index

for id in student_IDs:

    try:
        date = str(student_graduation_df.loc[id, 'Date']).replace("/", "_").replace("-", "_").split("_")
        temp = [id, student_majors_df.loc[id, 'Last_name'], student_majors_df.loc[id, 'First_name'], date[0], date[1],
                date[2], student_graduation_df.loc[id, 'Date']]
        discipline.append(temp)

    except KeyError:
        pass

discipline_df = pd.DataFrame(discipline, columns=["ID", "Lanme", "Fname", "Date", "Month", "Year", "Original_Date"])
discipline_df.sort_values(by=["Year", "Month", "Date"], ascending=True, inplace=True)
discipline_df.to_csv("./outputs/DisciplineStudents.csv", header=False, index=False,
                     columns=["ID", "Lanme", "Fname", "Original_Date"])
