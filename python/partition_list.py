import unittest
from python.Algorithms.list import ListNode

"""
Given a linked list and a value x, partition it such that all nodes less than x 
come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
"""


def solution(A, B):

    head_larger = ListNode(0)
    head_smaller = ListNode(0)
    larger_lst, smaller_lst = head_larger, head_smaller

    while A:

        if A.val >= B:
            larger_lst.next, larger_lst = A, A
        else:
            smaller_lst.next, smaller_lst = A, A

        A = A.next

    larger_lst.next = None
    smaller_lst.next = head_larger.next

    return head_smaller.next


class TestPartitionList(unittest.TestCase):

    def test_basic(self):
        A = [1, 2, 3]
        B = 1
        self.assertEqual([1, 2, 3], solution(ListNode.from_list(A), B))

    def test_trivial_none(self):
        A = []
        B = 1
        self.assertEqual(None, solution(ListNode.from_list(A), B))

    def test_trivial_one(self):
        A = [1]
        B = 1
        self.assertEqual([1], solution(ListNode.from_list(A), B))

    def test_trivial_two(self):
        A = [1, 2]
        B = 2
        self.assertEqual([1, 2], solution(ListNode.from_list(A), B))

    def test_example(self):
        A = [1, 4, 3, 2, 5, 2]
        B = 3
        self.assertEqual([1, 2, 2, 4, 3, 5], solution(ListNode.from_list(A), B))

    def test_complex(self):
        A = [1, 6, 2, 10, 3, 7, 9, 8]
        B = 6
        self.assertEqual([1, 2, 3, 6, 10, 7, 9, 8], solution(ListNode.from_list(A), B))

    def test_complex_2(self):
        A = [7, 8, 1, 5, 7, 7, 5]
        B = 5
        self.assertEqual([1, 7, 8, 5, 7, 7, 5], solution(ListNode.from_list(A), B))


if __name__ == '__main__':
    unittest.main()
