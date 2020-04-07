import unittest
import math

"""
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
Input: The only argument given is integer array A.
Output: Return the total water it is able to trap after raining.

Solution is O(n) time, O(1) space. Intuition: in every iteration you pick the smaller
element and compare it to the wall (that is, the current max from its own side).
If the current element is larger than the wall, no water will be trapped.
"""


def solution(A):

    left_wall = right_wall = total = left = 0
    right = len(A) - 1

    while left <= right:

        if A[left] <= A[right]:
            if A[left] >= left_wall:
                left_wall = A[left]
            else:
                total += left_wall - A[left]
            left += 1
        else:
            if A[right] >= right_wall:
                right_wall = A[right]
            else:
                total += right_wall - A[right]
            right -= 1

    return total


class TestTemplate(unittest.TestCase):

    def test_basic(self):
        A = [1, 0, 1]
        self.assertEqual(1, solution(A))

    def test_trivial_empty(self):
        A = []
        self.assertEqual(0, solution(A))

    def test_trivial_single(self):
        A = [1]
        self.assertEqual(0, solution(A))

    def test_trivial_two(self):
        A = [1, 0]
        self.assertEqual(0, solution(A))

    def test_example(self):
        # explanation here: http://i.imgur.com/0qkUFco.png
        A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
        self.assertEqual(6, solution(A))

    def test_identical(self):
        A = [1, 1, 1]
        self.assertEqual(0, solution(A))

    def test_challenging(self):
        A = [3, 2, 0, 1, 2]
        self.assertEqual(3, solution(A))

    def test_challenging_2(self):
        A = [3, 2, 0, 1, 1]
        self.assertEqual(1, solution(A))

    def test_challenging_3(self):
        A = [3, 2, 0, 1, 1, 2]
        self.assertEqual(4, solution(A))

    def test_challenging_4(self):
        A = [0, 0, 2, 1, 2, 1, 2, 0, 2]
        self.assertEqual(4, solution(A))

    def test_challenging_5(self):
        A = [2, 1, 3, 0, 1]
        self.assertEqual(2, solution(A))


if __name__ == '__main__':
    unittest.main()
