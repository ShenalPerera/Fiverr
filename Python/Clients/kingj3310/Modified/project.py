# import the libraries
import pandas as pd

student_major_file = input("Enter the File name of Student Major Lists : ")
student_gpa_file = input("Enter the file name of Student GPA list: ")
student_grad_file = input("Enter the file name of student graduation list: ")

try:
    # read StudentMajorsList.csv and Organize the data
    student_majors_df = pd.read_csv(student_major_file, delimiter=",", header=None)
    student_majors_df.columns = ["Student_ID", "Last_name", "First_name", "Major", "Disciplinary"]
    student_majors_df = student_majors_df.set_index('Student_ID')

    # read GPAList.csv and Organize the data
    student_gpa_df = pd.read_csv(student_gpa_file, delimiter=",", header=None)
    student_gpa_df.columns = ["Student_ID", "GPA"]
    student_gpa_df = student_gpa_df.set_index('Student_ID')

    # read GraduationDatesList.csv and Organize the data
    student_graduation_df = pd.read_csv(student_grad_file, delimiter=",", header=None)
    student_graduation_df.columns = ["Student_ID", "Date"]
    student_graduation_df = student_graduation_df.set_index('Student_ID')
except FileNotFoundError:
    print("Wrong file name try again !")
    exit(0)

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
full_roster_df.to_csv("FullRoster.csv", header=False, index=False)

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
    full_roster_df.to_csv( filename, header=False, index=False)

scholar_candidates = []
student_IDs = student_gpa_df[student_gpa_df['GPA'] > 3.8].index

for id in student_IDs:

    try:
        temp = [id, student_majors_df.loc[id, 'Last_name'], student_majors_df.loc[id, 'First_name'],
                student_majors_df.loc[id, 'Major'], student_gpa_df.loc[id, 'GPA']]
        scholar_candidates.append(temp)
    except KeyError:
        pass

scholar_candidates_df = pd.DataFrame(scholar_candidates, columns=["ID", "Lanme", "Fname", "Major", "GPA"])
scholar_candidates_df.sort_values(by=["GPA"], ascending=False, inplace=True)
scholar_candidates_df.to_csv("ScholarshipCandidates.csv", header=False, index=False)

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
discipline_df.to_csv("DisciplineStudents.csv", header=False, index=False,
                     columns=["ID", "Lanme", "Fname", "Original_Date"])
