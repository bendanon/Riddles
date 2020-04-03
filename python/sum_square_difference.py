import unittest
from math import pow
"""
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
"""


def sum_of_squares(num):
    sum = 0
    for i in range(1, num + 1):
        sum += pow(i, 2)
    return sum


def square_of_sum(num):
    sum = 0
    for i in range(1, num + 1):
        sum += i
    return pow(sum, 2)


def solution(num):
    return square_of_sum(num) - sum_of_squares(num)


class Tests(unittest.TestCase):

    def test_for_10(self):
        self.assertEqual(solution(10), 2640)

    def test_for_100(self):
        self.assertEqual(solution(100), 25164150)


if __name__ == '__main__':
    unittest.main()
