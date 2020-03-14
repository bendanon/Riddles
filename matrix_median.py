import unittest
import math

"""
Given an array of non negative integers A, and a range (B, C),
find the number of continuous subsequences in the array which have sum S in the range [B, C] or B <= S <= C
"""


def solution(A):

    lines = []
    for line in range(len(A)):
        lines += A[line]
    lines_sorted = sorted(lines)
    return lines_sorted[math.floor(len(lines) / 2)]


class TestNumrange(unittest.TestCase):

    def test_trivial(self):
        A = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
        self.assertEqual(solution(A), 5)


if __name__ == '__main__':
    unittest.main()
