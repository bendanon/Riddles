import unittest
import math

"""
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
"""


def solution(A):
    lst = []
    A.sort()

    for i in range(len(A)):
        low = i + 1
        high = len(A) - 1
        found = False
        while low < high:
            sum_3 = A[i] + A[low] + A[high]
            if sum_3 > 0:
                high -= 1
            elif sum_3 < 0:
                low += 1
            else:

                # Make sure you don't insert duplicates
                # Don't know why this is faster than a hash table!
                for t in lst:
                    if t == (A[i], A[low], A[high]):
                        found = True
                if not found:
                    lst.append((A[i], A[low], A[high]))

                found = False
                high -= 1
                low += 1

    return lst


class TestSum3(unittest.TestCase):

    def test_basic(self):
        A = [1, 2, 3, 4]
        self.assertEqual(solution(A), [])

    def test_trivial(self):
        A = [0, 0, 0]
        B = 0
        self.assertEqual(solution(A), [(0, 0, 0)])

    def test_basic_2(self):
        A = [1, 2, 2, -4, 1]
        self.assertEqual(solution(A), [(-4, 2, 2)])

    def test_example(self):
        A = [-1, 0, 1, 2, -1, -4]
        self.assertEqual(solution(A), [(-1, -1, 2), (-1, 0, 1)])


if __name__ == '__main__':
    unittest.main()
