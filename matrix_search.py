import unittest
import math

"""
Given a matrix of integers A of size N x M and an integer B.
Write an efficient algorithm that searches for integar B in matrix A.
This matrix A has the following properties:
-   Integers in each row are sorted from left to right.
-   The first integer of each row is greater than or equal to the last 
integer of the previous row.
Return 1 if B is present in A, else return 0.
"""


def solution(A, B):
    """

    :param A: The matrix
    :param B: The number
    :return: Return 1 if B is present in A, else return 0.
    """

    low = 0
    high = len(A) - 1
    line = None

    while low <= high:
        mid = math.floor((low + high) / 2)

        if A[mid][0] == B or A[mid][-1] == B:
            return 1
        elif A[mid][0] < B < A[mid][-1]:
            line = A[mid]
            break
        elif A[mid][0] > B:
            high = mid - 1
        elif A[mid][-1] < B:
            low = mid + 1
        else:
            print("%d %d %d", A[mid][0], A[mid][-1], B)

    if not line:
        return 0

    low = 0
    high = len(line) - 1

    while low <= high:
        mid = math.floor((low + high) / 2)

        if line[mid] == B:
            return 1
        elif line[mid] > B:
            high = mid - 1
        elif line[mid] < B:
            low = mid + 1
        else:
            print("%d %d %d %d", low, high, mid, B)

    return 0


class TestMatrixSearch(unittest.TestCase):

    def test_trivial(self):
        A = [[1]]
        B = 1
        self.assertEquals(solution(A, B), 1)

    def test_basic(self):
        A = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 50]]
        B = 50
        self.assertEqual(solution(A, B), 1)

    def test_basic_negative(self):
        A = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 50]]
        B = 4
        self.assertEqual(solution(A, B), 0)

    def test_basic_lines_negative(self):
        A = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 50]]
        B = 9
        self.assertEqual(solution(A, B), 0)

    def test_complex(self):
        A = [[3, 3, 11, 12, 14], [16, 17, 30, 34, 35], [45, 48, 49, 50, 52], [56, 59, 63, 63, 65],
             [67, 71, 72, 73, 79], [80, 84, 85, 85, 88], [88, 91, 92, 93, 94]]
        B = 94
        self.assertEqual(solution(A, B), 1)

    def test_basic_2(self):
        A = [[22, 32, 67]]
        B = 93
        self.assertEqual(solution(A, B), 0)


if __name__ == '__main__':
    unittest.main()
