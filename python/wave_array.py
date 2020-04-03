import unittest
import math

"""
Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
NOTE : If there are multiple answers possible, return the one thats lexicographically smallest. 
"""


def solution(A):

    A = sorted(A)
    for i in range(0, len(A) - 1, 2):
        A[i], A[i + 1] = A[i + 1], A[i]
    return A


class TestTemplate(unittest.TestCase):

    def test_example(self):
        A = [1, 2, 3, 4]
        self.assertEqual(solution(A), [2, 1, 4, 3])

    def test_trivial(self):
        A = [1]
        self.assertEqual(solution(A), [1])

    def test_negative(self):
        A = [-1, 2, 0, 6]
        self.assertEqual(solution(A), [0, -1, 6, 2])

    def test_identical(self):
        A = [1, 1, 1, 1]
        self.assertEqual(solution(A), [1, 1, 1, 1])

    def test_odd_len(self):
        A = [5, 1, 3, 2, 4]
        self.assertEqual(solution(A), [2, 1, 4, 3, 5])

    def test_len_3(self):
        A = [1, 2, 3]
        self.assertEqual([2, 1, 3], solution(A))


if __name__ == '__main__':
    unittest.main()
