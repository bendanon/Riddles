import unittest
import math

"""
Given an array S of n integers, find three integers in S such that the sum is 
closest to a given number, target. Return the sum of the three integers.
Assume that there will only be one solution
"""


# O(N^3)
def solution_1(A, B):
    closest = float('inf')

    for i in range(len(A)):
        for j in range(len(A)):
            for k in range(len(A)):
                if i == j or i == k or j == k:
                    continue
                sum_3 = A[i] + A[j] + A[k]
                if abs(sum_3 - B) < abs(closest - B):
                    closest = sum_3

    return closest


# O((N^2)log(n))
def solution_2(A, B):
    closest = float('inf')
    A.sort()
    for i in range(len(A)):
        for j in range(i + 1, len(A)):

            to_find = B - (A[i] + A[j])
            low = j + 1
            high = len(A) - 1
            while low <= high:
                mid = math.floor((low + high) / 2)

                if A[mid] == to_find:
                    return B
                elif A[mid] < to_find:
                    low = mid + 1
                elif A[mid] > to_find:
                    high = mid - 1

                sum_3 = A[i] + A[j] + A[mid]
                if abs(sum_3 - B) < abs(closest - B):
                    closest = sum_3

    return closest


# O(N^2)
def solution_3(A, B):

    closest = float('inf')
    A.sort()
    for i in range(len(A)):
        low = i + 1
        high = len(A) - 1

        while closest != B and low < high:
            sum_3 = A[i] + A[low] + A[high]
            if sum_3 < B:
                low += 1
            elif sum_3 > B:
                high -= 1

            if abs(sum_3 - B) < abs(closest - B):
                closest = sum_3
                if closest == B:
                    return B

    return closest


class TestSum3(unittest.TestCase):

    def test_basic(self):
        A = [1, 2, 3, 4]
        B = 8
        self.assertEqual(solution_1(A, B), 8)
        self.assertEqual(solution_2(A, B), 8)
        self.assertEqual(solution_3(A, B), 8)

    def test_trivial(self):
        A = [0, 0, 0]
        B = 0
        self.assertEqual(solution_1(A, B), 0)
        self.assertEqual(solution_2(A, B), 0)
        self.assertEqual(solution_3(A, B), 0)

    def test_example(self):
        A = [-1, 2, 1, -4]
        B = 1
        self.assertEqual(solution_1(A, B), 2)
        self.assertEqual(solution_2(A, B), 2)
        self.assertEqual(solution_3(A, B), 2)

    def test_complex(self):
        A = [3, -2, 9, 0, 1, 7, 5, 8, -10, 5]
        B = 9
        self.assertEqual(solution_1(A, B), 9)
        self.assertEqual(solution_2(A, B), 9)
        self.assertEqual(solution_3(A, B), 9)

    def test_complex_2(self):
        A = [10, -6, 3, 4, -8, -5]
        B = 3
        self.assertEqual(solution_1(A, B), 2)
        self.assertEqual(solution_2(A, B), 2)
        self.assertEqual(solution_3(A, B), 2)


if __name__ == '__main__':
    unittest.main()
