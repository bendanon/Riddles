import unittest
import math

"""
Find the contiguous subarray within an array, A of length N which has the largest sum.
Input Format: The first and the only argument contains an integer array, A.
Output Format: Return an integer representing the maximum possible sum of the contiguous subarray.
"""


# O(N^3)
def solution_1(A):
    max_sum = float('-inf')
    for i in range(0, len(A)):
        for j in range(i, len(A)):
            temp_sum = sum(A[i:j+1])
            if temp_sum > max_sum:
                max_sum = temp_sum
    return max_sum


# O(N^2)
def solution_2(A):
    max_sum = float('-inf')
    sums = {}
    for i in range(0, len(A)):
        sums[(i, i)] = A[i]
        for j in range(i+1, len(A)):
            sums[(i, j)] = sums[(i, j-1)] + A[j]
            if sums[(i, j)] > max_sum:
                max_sum = sums[(i, j)]
    return max_sum


# O(Nlog(N))
def solution_3(A):

    if len(A) == 1:
        return A[0]

    mid = int(len(A) / 2)
    right_mss = solution_3(A[mid:])
    left_mss = solution_3(A[:mid])
    left_sum = float('-inf')
    right_sum = float('-inf')
    sum = 0

    # Calculate left_sum
    for i in range(mid - 1, -1, -1):
        sum += A[i]
        left_sum = max(left_sum, sum)

    sum = 0

    # Calculate right_sum
    for i in range(mid, len(A)):
        sum += A[i]
        right_sum = max(right_sum, sum)

    mss_max = max(right_mss, left_mss)
    return max(mss_max, left_sum + right_sum)


# O(N) - Kadane's algorithm
def solution(A):

    sub_sum = 0
    max_sum = float('-inf')

    for i in range(len(A)):
        sub_sum += A[i]
        max_sum = max(max_sum, sub_sum)
        sub_sum = max(sub_sum, 0)

    return max_sum


# O(N), returning the max subset
def bonus_solution(A):

    max_element = float('-inf')
    for i in range(len(A)):
        max_element = max(max_element, A[i])

    if max_element <= 0:
        return [max_element]

    sub_start = 0
    max_subset = []
    sub_sum = 0
    max_sum = float('-inf')

    for i in range(len(A)):
        sub_sum += A[i]
        if sub_sum > max_sum:
            max_sum = sub_sum
            max_subset = A[sub_start:i + 1]

        if sub_sum < 0:
            sub_sum = 0
            sub_start = i + 1

    return max_subset


class TestMaxSumContSubarr(unittest.TestCase):

    def test_basic(self):
        A = [1, 2, 3, 4]
        self.assertEqual(solution(A), 10)
        self.assertEqual(bonus_solution(A), [1, 2, 3, 4])

    def test_trivial(self):
        A = [0, 0, 0]
        self.assertEqual(solution(A), 0)
        self.assertEqual(bonus_solution(A), [0])

    def test_basic_2(self):
        A = [1, 2, 2, -4, 1]
        self.assertEqual(solution(A), 5)
        self.assertEqual(bonus_solution(A), [1, 2, 2])

    def test_basic_3(self):
        A = [-1, 0, 1, 2, -1, -4]
        self.assertEqual(solution(A), 3)
        self.assertEqual(bonus_solution(A), [0, 1, 2])

    def test_example(self):
        A = [1, 2, 3, 4, -10]
        self.assertEqual(solution(A), 10)
        self.assertEqual(bonus_solution(A), [1, 2, 3, 4])

    def test_example_2(self):
        A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        self.assertEqual(solution(A), 6)
        self.assertEqual(bonus_solution(A), [4, -1, 2, 1])

    def test_negative(self):
        A = [-500]
        self.assertEqual(solution(A), -500)
        self.assertEqual(bonus_solution(A), [-500])

    def test_non_positive(self):
        A = [-500, 0]
        self.assertEqual(solution(A), 0)
        self.assertEqual(bonus_solution(A), [0])


if __name__ == '__main__':
    unittest.main()
