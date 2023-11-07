"""
This module contains implementations of four different sorting algorithms: quicksort,
insertion sort, mergesort, and two hybrid sorting algorithms that combine elements of
the first three algorithms. Each sorting function takes a list of integers as input and
modifies the list in place to sort it in ascending order. The quicksort algorithm uses
a stack to keep track of sub-lists that need to be sorted, while the insertion sort
algorithm works by iterating through the list and inserting each element into its
correct position in a growing sorted sequence. The mergesort algorithm recursively
divides the input list into smaller sub-lists and merges them back together in a
bottom-up fashion, while the hybrid sorting algorithms combine elements of these three
algorithms to optimize performance for certain types of inputs.
"""


def quicksort(lst: list) -> None:
    """
    Sorts the input list using the Quicksort algorithm.

    Args:
        lst: A list of comparable elements.

    Returns:
        None. The input list is sorted in place.
    """
    if len(lst) > 1:
        pivot = lst[len(lst) // 2]
        left = [x for x in lst if x < pivot]
        middle = [x for x in lst if x == pivot]
        right = [x for x in lst if x > pivot]

        quicksort(left)
        quicksort(right)

        lst[:] = left + middle + right


def insertionsort(lst: list) -> None:
    """
        Sorts a given list of numbers in ascending order using the insertion sort algorithm.

    Args:
        lst (list): A list of integers to be sorted.

    Returns:
        None. The original list is modified in-place.

    Description:
        This implementation of the insertion sort algorithm works by iterating through
        the list and inserting each element into its correct position in a growing
        sorted sequence. It starts with the second element in the list and compares it
        to the elements before it, swapping any that are out of order. It repeats this
        process for each subsequent element until the entire list is sorted. This
        algorithm has a worst-case time complexity of O(n^2), but performs well on small
        lists or partially sorted lists.
    """
    for i in range(1, len(lst)):
        key = lst[i]
        j = i - 1
        while j >= 0 and lst[j] > key:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = key


def merge(left, right):
    """
        Merges two sorted lists into a single sorted list.

    Args:
        left (list): A sorted list of integers.
        right (list): A sorted list of integers.

    Returns:
        list: A new list containing all elements from the input lists, sorted in ascending order.

    Description:
        This function takes two sorted lists as input and merges them into a single sorted
        list. It creates an empty list called 'result' and then iterates through both input
        lists using two indices, 'i' and 'j', respectively. It compares the elements at the
        current indices and appends the smaller one to 'result'. If one of the input lists
        is fully consumed, the function appends the remaining elements from the other list
        to 'result'. The resulting list is then returned. This function has a time complexity
        of O(n), where 'n' is the total number of elements in both input lists.
    """

    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result


def mergesort(lst: list) -> None:
    """
        Sorts a given list of numbers in ascending order using the mergesort algorithm.

    Args:
        lst (list): A list of integers to be sorted.

    Returns:
        None. The original list is modified in-place.

    Description:
        This implementation of the mergesort algorithm works by recursively dividing the
        input list into smaller and smaller sub-lists until each sub-list contains only
        one element. It then merges adjacent sub-lists in a bottom-up fashion, combining
        them into larger sorted sub-lists, until the entire list is sorted. The merge
        operation is implemented in a separate 'merge' function. This algorithm has a
        worst-case time complexity of O(n log n), where 'n' is the number of elements in
        the input list.
    """
    if len(lst) > 1:
        mid = len(lst) // 2
        left = lst[:mid]
        right = lst[mid:]

        mergesort(left)
        mergesort(right)

        lst[:] = merge(left, right)


def mergesort_hybrid(lst: list) -> None:
    """
        Sorts the input list using a hybrid algorithm that combines mergesort and insertion sort.

        Args:
            lst: A list of comparable elements.
            k: The threshold at which to switch from mergesort to insertion sort.

        Returns:
            None. The input list is sorted in place.
        """
    if len(lst) > 56:
        mid = len(lst) // 2
        left = lst[:mid]
        right = lst[mid:]

        mergesort_hybrid(left)
        mergesort_hybrid(right)

        lst[:] = merge(left, right)
    else:
        insertionsort(lst)


def quicksort_hybrid(lst: list) -> None:
    """
        Sorts the input list using a hybrid algorithm that combines quicksort and insertion sort.

        Args:
            lst: A list of comparable elements.
            k: The threshold at which to switch from quicksort to insertion sort.

        Returns:
            None. The input list is sorted in place.
        """
    k = 43
    if len(lst) > k:
        pivot = lst[len(lst) // 2]
        left = [x for x in lst if x < pivot]
        middle = [x for x in lst if x == pivot]
        right = [x for x in lst if x > pivot]

        quicksort_hybrid(left)
        quicksort_hybrid(right)

        lst[:] = left + middle + right
    else:
        insertionsort(lst)
