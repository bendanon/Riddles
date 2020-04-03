import unittest
import math

"""
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.
"""


def f(A, i, j):
    return int(math.fabs(A[i] - A[j]) + math.fabs(i - j))


def solution_1(A):
    max_val = 0
    for i in range(len(A)):
        for j in range(i + 1, len(A)):
            max_val = max(max_val, f(A, i, j))
    return max_val


def solution(A):

    if len(A) == 0:
        return 0

    max_val_j_smaller = max_val_j_bigger = float('-inf')
    min_val_j_smaller = min_val_j_bigger = float('inf')
    for i in range(len(A)):
        max_val_j_bigger = max(max_val_j_bigger, A[i] + i)
        min_val_j_bigger = min(min_val_j_bigger, A[i] + i)
        max_val_j_smaller = max(max_val_j_smaller, A[i] - i)
        min_val_j_smaller = min(min_val_j_smaller, A[i] - i)

    diff_j_bigger = max_val_j_bigger - min_val_j_bigger
    diff_j_smaller = max_val_j_smaller - min_val_j_smaller

    return max(diff_j_bigger, diff_j_smaller)


class TestMaxAbsDiff(unittest.TestCase):

    def test_example(self):
        A = [1, 3, -1]
        self.assertEqual(5, solution(A))

    def test_trivial(self):
        A = []
        self.assertEqual(0, solution(A))

    def test_basic(self):
        A = [1, 1]
        self.assertEqual(1, solution(A))

    def test_basic_2(self):
        A = [1, 2]
        self.assertEqual(2, solution(A))

    def test_basic_4(self):
        A = [1, 1, 1, 1, 1, 1]
        self.assertEqual(5, solution(A))

    def test_complex(self):
        A = [-70, -64, -6, -56, 64, 61, -57, 16, 48, -98]
        self.assertEqual(167, solution(A))

    def test_complex_2(self):
        A = [-98, -5, 37, -97, 38, 22, 70, 42, 61, 84]
        self.assertEqual(191, solution(A))


if __name__ == '__main__':
    unittest.main()
