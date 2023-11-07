# import the libraries
from matplotlib import pyplot as plt

# Dict to keep the scores
scores_labels = [str(i) for i in range(0, 11)]  # create the labels

# dict to keep score and its count
scores = {}
# initialize the frequency to 0
for scores_label in scores_labels:
    scores[scores_label] = 0

# open the file in read mode
with open("histogram.txt", "r") as file:
    # loop through each line
    for val in file:
        # catch errors when input is not matching type
        try:
            value = val.strip()  # remove newline characters and converts it into int data type
            scores[value] += 1  # increase the count when occurrence found
        except ValueError:  # skip the line when it is not an integer
            continue

plt.bar(scores.keys(), scores.values())  # plot the histogram
plt.title("HISTOGRAM OF THE SCORES")
plt.xlabel("Scores of the quiz")
plt.ylabel("Count")
plt.show()
