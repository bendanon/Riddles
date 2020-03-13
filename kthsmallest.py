import unittest
import math

"""
Find the kth smallest element in an unsorted array of non-negative integers.
"""


def solution(A, B):
    """

    :param A: tuple of integers
    :param B: integer
    :return: an integer
    """

    low = min(A)
    high = max(A)

    k_smallest = high

    while low <= high:
        mid = low + math.floor((high - low) / 2)

        smaller = 0
        equal = 0

        for num in A:
            if num < mid:
                smaller += 1
            if num == mid:
                equal += 1

        if smaller < B <= (smaller + equal):
            k_smallest = mid
            break

        # mid is too big
        if smaller >= B:
            high = mid - 1

        # mid is too small
        if smaller + equal < B:
            low = mid + 1

    return k_smallest


class TestKthsmallest(unittest.TestCase):

    def test_trivial(self):
        A = (2, 1, 4, 3, 2)
        B = 3
        self.assertEqual(solution(A, B), 2)

    def test_complex(self):
        A = [60, 94, 63, 3, 86, 40, 93, 36, 56, 48, 17, 10, 23, 43, 77, 1, 1, 93, 79, 4, 10, 47, 1, 99, 91, 53, 99, 18,
             52, 61, 84, 10, 13, 52, 3, 9, 78, 16, 7, 62]
        B = 22
        self.assertEqual(solution(A, B), 52)


if __name__ == '__main__':
    unittest.main()
