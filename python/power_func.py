import unittest
import math

"""
Given x, n, d find x^n % d
"""


def solution(A, B, C):
    """

    :param A: x the base
    :param B: n the power
    :param C: d the modulus
    :return: x^n % d
    """
    res = 1

    if A == 0 or (A > C and A / C == 0.0):
        return 0

    # Update A if it is more
    # than or equal to C
    A = A % C

    while B > 0:

        # If B is odd, multiply
        # A with result
        if B % 2 == 1:
            res = (res * A) % C

        B = B >> 1
        A = (A * A) % C

    return res


class TestMatrixSearch(unittest.TestCase):

    def test_basic(self):
        A = 3
        B = 4
        C = 4
        self.assertEqual(solution(A, B, C), 1)

    def test_stress(self):
        for i in range(2, 10):
            for j in range(2, 10):
                for k in range(2, 10):
                    self.assertEqual(solution(i, j, k), i**j % k)


if __name__ == '__main__':
    unittest.main()
