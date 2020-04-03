import unittest
from python.Algorithms.list import ListNode

"""
Given a linked list, remove the nth node from the end of list and return its head.
"""


def solution(A, B):

    back = A

    if back is None:
        return None

    front = back

    # create a lead of B nodes from back to front
    while front is not None and B > 0:
        front = front.next
        B -= 1

    # This means B is larger than the length of the list
    # Remove the first node
    if front is None:
        return back.next

    while front.next is not None:
        front = front.next
        back = back.next

    back.next = back.next.next

    return A


class TestReverseList(unittest.TestCase):

    def test_basic(self):
        A = [1, 2, 3]
        B = 1
        self.assertEqual([1, 2], solution(ListNode.from_list(A), B))

    def test_trivial_none(self):
        A = []
        B = 1
        self.assertEqual(None, solution(ListNode.from_list(A), B))

    def test_trivial_one(self):
        A = [1]
        B = 1
        self.assertEqual(None, solution(ListNode.from_list(A), B))

    def test_trivial_two(self):
        A = [1, 2]
        B = 2
        self.assertEqual([2], solution(ListNode.from_list(A), B))

    def test_example(self):
        A = [1, 2, 3, 4, 5]
        B = 2
        self.assertEqual([1, 2, 3, 5], solution(ListNode.from_list(A), B))


if __name__ == '__main__':
    unittest.main()
