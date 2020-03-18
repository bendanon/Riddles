import unittest
import math

"""
Given an array ‘A’ of sorted integers and another non negative 
integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
Try doing this in less than linear space complexity.
"""


def solution(A, B):

    if len(A) <= 1:
        return 0

    for i in range(len(A)-1, 0, -1):
        to_find = A[i] - B

        low = 0
        high = i
        while low <= high:
            mid = math.floor((low + high) / 2)
            if A[mid] == to_find:
                # Make sure i != j
                if mid == i:
                    break
                return 1
            elif A[mid] < to_find:
                low = mid + 1
            elif A[mid] > to_find:
                high = mid - 1

    return 0


class TestDiffk(unittest.TestCase):

    def test_positive_basic(self):
        A = [1, 2, 3, 4, 5]
        B = 2
        self.assertEqual(solution(A, B), 1)

    def test_negative_basic(self):
        A = [1, 2, 3, 4, 5]
        B = 7
        self.assertEqual(solution(A, B), 0)

    def test_trivial_negative(self):
        A = [1]
        B = 0
        self.assertEqual(solution(A, B), 0)

    def test_trivial_positive(self):
        A = [1, 1, 1]
        B = 0
        self.assertEqual(solution(A, B), 1)

    def test_trivial_positive_2(self):
        A = [1, 2, 2, 3, 4]
        B = 0
        self.assertEqual(solution(A, B), 1)

    def test_trivial_negative_2(self):
        A = [1, 2, 3]
        B = 0
        self.assertEqual(solution(A, B), 0)

    def test_complex(self):
        A = [1, 2, 3, 6, 8, 8, 10, 16, 19, 19, 32, 33, 36, 40, 43, 48, 50, 52, 57, 58, 58, 63, 63, 63, 69, 75, 94, 95,
            96, 97, 98]
        B = 73
        self.assertEqual(solution(A, B), 1)


if __name__ == '__main__':
    unittest.main()
