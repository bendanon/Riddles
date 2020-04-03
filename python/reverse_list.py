import unittest
from python.Algorithms.list import ListNode

"""
Reverse a linked list. Do it in-place and in one-pass.
"""

def solution(A):

    prev = A
    if prev is None:
        return None

    current = prev.next
    prev.next = None

    while current:
        next = current.next
        current.next = prev
        prev = current
        current = next

    return prev


class TestReverseList(unittest.TestCase):

    def test_basic(self):
        A = [1, 2, 3]
        self.assertEqual([3, 2, 1], solution(ListNode.from_list(A)))

    def test_trivial_none(self):
        A = []
        self.assertEqual(None, solution(ListNode.from_list(A)))

    def test_trivial_one(self):
        A = [1]
        self.assertEqual([1], solution(ListNode.from_list(A)))

    def test_trivial_two(self):
        A = [1, 2]
        self.assertEqual([2, 1], solution(ListNode.from_list(A)))

    def test_example(self):
        A = [1, 2, 3, 4, 5]
        self.assertEqual([5, 4, 3, 2, 1], solution(ListNode.from_list(A)))


if __name__ == '__main__':
    unittest.main()
