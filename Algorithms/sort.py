import unittest
import math
import random

"""
Sort an array of N integers
"""


def merge_sort(A):

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


class TestSort(unittest.TestCase):

    def test_no_change(self):
        A = [1, 2, 3, 4]
        self.assertEqual(merge_sort(A), [1, 2, 3, 4])

    def test_trivial(self):
        A = [0]
        self.assertEqual(merge_sort(A), [0])

    def test_reverse(self):
        A = [4, 3, 2, 1]
        self.assertEqual(merge_sort(A), [1, 2, 3, 4])

    def test_negative(self):
        A = [3, -2, -3, 1]
        self.assertEqual(merge_sort(A), [-3, -2, 1, 3])

    def test_duplicate(self):
        A = [3, 2, 2, 1]
        self.assertEqual(merge_sort(A), [1, 2, 2, 3])

    def test_complex(self):
        A = [3, -2, 9, 0, 1, 7, 5, 8, -10, 5, 0]
        self.assertEqual(merge_sort(A), [-10, -2, 0, 0, 1, 3, 5, 5, 7, 8, 9])

    def test_fuzz(self):
        A = []
        for i in range(random.randint(100, 2000)):
            A.append(random.randint(-1000, 1000))
        self.assertEqual(merge_sort(A), sorted(A))


if __name__ == '__main__':
    unittest.main()
