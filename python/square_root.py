import unittest

"""
Return the square root of a number
"""


def solution(A):

    if A == 0:
        return 0

    if A == 1 or A == 2:
        return 1

    low = 1
    high = A
    while low < high:
        mid = int((low + high) / 2)

        if mid**2 == A:
            return mid

        if mid**2 < A:
            if (mid + 1)**2 > A:
                return mid
            low = mid

        elif mid**2 > A:
            high = mid


class TestSquareRoot(unittest.TestCase):

    def test_to_1000(self):
        for i in range(1001):
            self.assertEqual(solution(i), int(i**0.5))


if __name__ == '__main__':
    unittest.main()
