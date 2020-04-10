import unittest
from python.Algorithms.list import ListNode

"""
Reverse a linked list using recursion.
"""


def solution(A):

    if not A or not A.next:
        return A

    next_node = A.next
    head = solution(A.next)
    next_node.next = A
    A.next = None

    return head


class TestTemplate(unittest.TestCase):

    def test_example(self):
        A = [1, 2, 3, 4, 5]
        self.assertEqual([5, 4, 3, 2, 1], solution(ListNode.from_list(A)))

    def test_trivial(self):
        A = []
        self.assertEqual(None, solution(ListNode.from_list(A)))

    def test_trivial_1(self):
        A = [1]
        self.assertEqual([1], solution(ListNode.from_list(A)))

    def test_trivial_2(self):
        A = [1, 2]
        self.assertEqual([2, 1], solution(ListNode.from_list(A)))

    def test_identical(self):
        A = [1, 1, 1]
        self.assertEqual([1, 1, 1], solution(ListNode.from_list(A)))


if __name__ == '__main__':
    unittest.main()
