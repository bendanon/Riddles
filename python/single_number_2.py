import unittest
import math

"""
Given an array of integers, every element appears thrice except for one which occurs once.
Find that element which does not appear thrice.
Note: Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?
"""


def solution(A):
    ones = [0] * 32
    for num in A:
        for bit in range(32):
            if (num >> bit) & 1 == 1:
                ones[bit] += 1

    result = 0
    for bit in range(32):
        if ones[bit] % 3 != 0:
            result = result | (1 << bit)

    return result


class TestTemplate(unittest.TestCase):

    def test_example_basic(self):
        A = [0, 0, 0, 1]
        self.assertEqual(1, solution(A))

    def test_example_complex(self):
        A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
        self.assertEqual(4, solution(A))

    def test_challenging(self):
        A = [7, 5, 1, 7, 5, 1, 7, 5, 1, 4]
        self.assertEqual(4, solution(A))


if __name__ == '__main__':
    unittest.main()
