import unittest

"""
Given an array of non negative integers A, and a range (B, C),
find the number of continuous subsequences in the array which have sum S in the range [B, C] or B <= S <= C
"""


def solution(A, B, C):
    """

    :param A: list of integers
    :param B: range low
    :param C: range high
    :return: number of subsequences qualifying
    """
    if B == 0 and C == 0:
        return 0

    count = sub_sum = start = end = 0

    while start in range(len(A)):

        sub_sum += A[end]

        if B <= sub_sum <= C:
            count += 1
            end += 1

        elif sub_sum < B:
            end += 1

        elif sub_sum > C:
            sub_sum = 0
            start += 1
            end = start

        if end == len(A):
            start += 1
            sub_sum = 0
            end = start

    return count


class TestNumrange(unittest.TestCase):

    def test_trivial(self):
        A = [1]
        B = 0
        C = 0
        self.assertEqual(solution(A, B, C), 0)

    def test_basic(self):
        A = [10, 5, 1, 0, 2]
        B = 6
        C = 8
        self.assertEqual(solution(A, B, C), 3)

    def test_complex(self):
        A = [80, 97, 78, 45, 23, 38, 38, 93, 83, 16, 91, 69, 18, 82, 60, 50, 61, 70, 15, 6, 52, 90]
        B = 99
        C = 269
        self.assertEqual(solution(A, B, C), 58)


if __name__ == '__main__':
    unittest.main()
