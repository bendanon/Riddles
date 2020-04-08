import unittest
import math

"""
Given an integer array A of N integers, 
find the pair of integers in the array which have minimum XOR value. 
Report the minimum XOR value.
"""


def solution(A):
    min_val = float('inf');
    A.sort()
    for i in range(1, len(A)):
        min_val = min(min_val, A[i-1] ^ A[i])

    return min_val


class TestTemplate(unittest.TestCase):

    def test_basic(self):
        A = [1, 1, 1]
        self.assertEqual(0, solution(A))

    def test_trivial(self):
        A = []
        self.assertEqual(float('inf'), solution(A))

    def test_example_1(self):
        A = [0, 2, 5, 7]
        self.assertEqual(2, solution(A))

    def test_example_2(self):
        A = [0, 4, 7, 9]
        self.assertEqual(3, solution(A))

    def test_challenging(self):
        A = [0, 1, 2, 3, 4, 5, 0]
        self.assertEqual(0, solution(A))


if __name__ == '__main__':
    unittest.main()
