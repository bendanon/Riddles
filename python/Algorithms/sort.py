import unittest
import math
import random
from copy import deepcopy

"""
Sort an array of N integers
"""


def swap(A, i, j):
    A[i], A[j] = A[j], A[i]


def partition(A, start, end):
    """
    Chooses a pivot element (A[start]) and makes swaps such that A[start] is
    in its sorted position within A[start:end]
    :param A: the array
    :param start: start index for partition
    :param end: end index for partition
    :return: Final position of the element originally chosen as pivot
    """
    pivot = start
    index_first_larger = -1
    for i in range(start + 1, end + 1):
        if A[i] > A[pivot] and index_first_larger == -1:
            index_first_larger = i

        if A[i] < A[pivot] and index_first_larger != -1:
            swap(A, i, index_first_larger)
            index_first_larger += 1

    if index_first_larger != -1:
        final_position = index_first_larger - 1
    else:
        final_position = end

    swap(A, pivot, final_position)

    return final_position


def _quick_sort(A, start, end):
    """
    A recursive algorithm which calls the subroutine "partition" which chooses
    A pivot element (in our case the first element), and moves all smaller
    elements before it and all larger elements after it. After "partition" ends
    the pivot element is in its final sorted position. partition is O(N)
    Time complexity: O(N^2) - if you choose the minimum element as pivot there
    will be O(N) partitions. If the pivot element is the median, there will be
    O(logN) partitions.
    Space complexity: O(log(N)) for stack frames.
    :param A:
    :return:
    """

    if start < end:
        pivot = partition(A, start, end)
        _quick_sort(A, start, pivot - 1)
        _quick_sort(A, pivot + 1, end)

    return A


def quick_sort(A):
    return _quick_sort(A, 0, len(A) - 1)


def insertion_sort(A):
    """
    A simple iterative algorithm which divides the array to two: sorted part
    and unsorted part. In every iteration it takes the first element of the
    unsorted part and inserts it into the correct position in the sorted part.
    Time complexity: O(N^2) - N insertions, each takes O(N). Finding the
    correct position for insertion can be done in O(log(N)) since inserting
    into a sorted array BUT the shifting of elements in the sorted part costs O(N)
    Space complexity: O(1) - in place
    :param A: the unsorted array
    :return: the sorted array
    """

    for i in range(1, len(A)):
        for j in range(0, i):
            if A[i] < A[j]:
                swap(A, i, j)

    return A


def insertion_sort_list(linked_list):
    pass


def bubble_sort(A):
    """
    A simple iterative algorithm that swaps two adjacent elements if the first
    is bigger than the second. It stops after an iteration with no swaps.
    Time complexity: O(N^2) - compare every element to every element
    Space complexity: O(1) - in place
    :param A: the unsorted array
    :return: the sorted array
    """

    for i in range(len(A)):

        swapped = False
        for j in range(len(A) - 1):

            if A[j] > A[j + 1]:
                A[j], A[j + 1] = A[j + 1], A[j]
                swapped = True

        if not swapped:
            break
    return A


def selection_sort(A):
    """
    A simple iterative algorithm which divides the array to two: sorted part
    and unsorted part. In every iteration it chooses the minimum element in
    the unsorted part and adds it to the sorted part.
    Time complexity: O(N^2) - intuitively we find the minimum element (O(N)), N times
    Space complexity: O(1) - the sorting is done in place.
    :param A: the unsorted array
    :return:
    """

    for i in range(len(A)):
        min_j = i

        # Find the min element of the unsorted part (i, len(A)) = "select"
        for j in range(i, len(A)):
            if A[min_j] > A[j]:
                min_j = j

        # Swap the first element of the unsorted part with the minimum
        A[i], A[min_j] = A[min_j], A[i]

    return A


def merge_sort(A):
    """
    A recursive algorithm which splits the array to equal parts (left and right),
    then merges them into a single array in a sorted manner.
    Time complexity: O(nlogn) - intuitively we save comparisons by comparing
    only to the smallest element in each half when merging, and not to all of them.
    Space complexity: O(n + logn) for storing the halves (O(n)) and for stack frames (O(log(n))
    :param A - the unsorted array
    """

    if len(A) == 1:
        return A

    mid = int(len(A) / 2)
    left = A[:mid]
    right = A[mid:]

    sorted_left = merge_sort(left)
    sorted_right = merge_sort(right)

    merged = []
    next_left = 0
    next_right = 0
    while next_left < len(sorted_left) and next_right < len(sorted_right):
        if sorted_left[next_left] <= sorted_right[next_right]:
            merged.append(sorted_left[next_left])
            next_left += 1
        else:
            merged.append(sorted_right[next_right])
            next_right += 1

    return merged + sorted_left[next_left:] + sorted_right[next_right:]


def merge_sort_in_place(linked_list):
    """
    See explanation above
    Space complexity: O(1)
    :param linked_list: the unsorted list
    :return: sorts the list, no return value
    """
    pass


class TestSort(unittest.TestCase):

    def run_all_sorts(self, expected_result, A):
        self.assertEqual(expected_result, merge_sort(deepcopy(A)))
        self.assertEqual(expected_result, selection_sort(deepcopy(A)))
        self.assertEqual(expected_result, bubble_sort(deepcopy(A)))
        self.assertEqual(expected_result, insertion_sort(deepcopy(A)))
        self.assertEqual(expected_result, quick_sort(deepcopy(A)))

    def test_partition(self):
        A = [4, 3, 2, 1]
        start = 0
        end = len(A) - 1

        partition(A, start, end)
        self.assertEqual([1, 3, 2, 4], A)

        A = [3, 4, 2, 1]
        self.assertEqual(2, partition(A, start, end))
        self.assertEqual([1, 2, 3, 4], A)

        A = [2, 4, 1, 3]
        self.assertEqual(1, partition(A, start, end))
        self.assertEqual([1, 2, 4, 3], A)

        A = [1, 2, 3, 4]
        self.assertEqual(0, partition(A, start, end))
        self.assertEqual([1, 2, 3, 4], A)

        A = [2, 1, 4, 3]
        self.assertEqual(1, partition(A, start, end))
        self.assertEqual([1, 2, 4, 3], A)

        A = [5, 4, 3, 2, 1]
        start = 1
        end = 3
        self.assertEqual(3, partition(A, start, end))
        self.assertEqual([5, 2, 3, 4, 1], A)

        A = [5, 2, 3, 1, 4]
        start = 1
        end = 3
        self.assertEqual(2, partition(A, start, end))
        self.assertEqual([5, 1, 2, 3, 4], A)

        A = [5, 2, 3, 1, 4]
        start = 1
        end = 4
        self.assertEqual(2, partition(A, start, end))
        self.assertEqual([5, 1, 2, 3, 4], A)

        A = [2, 5, 3, 1, 4]
        start = 1
        end = 4
        self.assertEqual(4, partition(A, start, end))
        self.assertEqual([2, 4, 3, 1, 5], A)

    def test_no_change(self):
        A = [1, 2, 3, 4]
        expected_result = [1, 2, 3, 4]
        self.run_all_sorts(expected_result, A)

    def test_trivial(self):
        A = [0]
        expected_result = [0]
        self.run_all_sorts(expected_result, A)

    def test_reverse(self):
        A = [4, 3, 2, 1]
        expected_result = [1, 2, 3, 4]
        self.run_all_sorts(expected_result, A)

    def test_negative(self):
        A = [3, -2, -3, 1]
        expected_result = [-3, -2, 1, 3]
        self.run_all_sorts(expected_result, A)

    def test_duplicate(self):
        A = [3, 2, 2, 1]
        expected_result = [1, 2, 2, 3]
        self.run_all_sorts(expected_result, A)

    def test_complex(self):
        A = [3, -2, 9, 0, 1, 7, 5, 8, -10, 5, 0]
        expected_result = [-10, -2, 0, 0, 1, 3, 5, 5, 7, 8, 9]
        self.run_all_sorts(expected_result, A)

    def test_fuzz(self):
        A = []
        for i in range(random.randint(100, 2000)):
            A.append(random.randint(-1000, 1000))
        expected_result = sorted(A)
        self.run_all_sorts(expected_result, A)


if __name__ == '__main__':
    unittest.main()
