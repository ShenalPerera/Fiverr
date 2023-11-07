import sys
import time

from sorting import insertionsort
from sorting import quicksort
from sorting import mergesort
from sorting import mergesort_hybrid
from sorting import quicksort_hybrid

# uncomment if you want to run only this three
# FUNCTIONS = [mergesort, insertionsort, quicksort]
# FUNCTIONS_NAMES = ["mergesort", "insertionsort", "quicksort"]
FILENAMES = ["10", "100", "1000", "10000", "100000"]

# Uncomment after implemented hybrid approaches
FUNCTIONS = [mergesort_hybrid, quicksort_hybrid]
FUNCTIONS_NAMES = ["mergesort_hybrid", "quicksort_hybrid"]

sys.setrecursionlimit(100000)

for file_name in FILENAMES:
    with open('Testdata/' + file_name + "_random.txt", 'r', encoding='UTF-8') as file:
        original = list(map(int, file.readlines()))
        num_list = original.copy()

        print(f"Results for {file_name}_random.txt:")

        for function_, function_name in zip(FUNCTIONS, FUNCTIONS_NAMES):

            runtimes = []
            for i in range(5):
                num_list = original.copy()

                start_time = time.perf_counter()
                function_(num_list)
                end_time = time.perf_counter()
                runtime = end_time - start_time
                print(f"Run {i + 1} of {function_name} took {runtime:.7f} seconds")
                runtimes.append(runtime)

            average_runtime = sum(runtimes) / 5
            print(f"The average runtime of {function_name} is {average_runtime:.7f} seconds.\n")

            print("\n======================================================================\n")
