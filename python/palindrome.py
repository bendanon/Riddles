import unittest
import math

"""
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
"""


def solution(A):

    if A == '':
        return 1

    clean_string = [l.capitalize() for l in A if l.isalnum()]
    first_half = clean_string[:math.floor(len(clean_string) / 2)]
    second_half = clean_string[math.ceil(len(clean_string) / 2):]

    return first_half == second_half[::-1]


class TestMatrixSearch(unittest.TestCase):

    def test_negative_basic(self):
        A = "race a car"
        self.assertEqual(solution(A), 0)

    def test_positive_basic(self):
        A = "A man, a plan, a canal: Panama"
        self.assertEqual(solution(A), 1)


if __name__ == '__main__':
    unittest.main()
