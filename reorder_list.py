import unittest
from Algorithms.list import ListNode
import math

"""
Given a singly linked list
 L: L0 → L1 → … → Ln-1 → Ln,
 reorder it to:
 L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 You must do this in-place without altering the nodes’ values.
"""


def reverse_list(A):

    prev = A
    if not prev:
        return A
    current = prev.next
    if not current:
        return A

    prev.next = None

    while current:
        next = current.next
        current.next = prev
        prev = current
        current = next

    return prev


def get_second_half(A):

    fast = A
    slow = A

    while fast and fast.next and (slow == A or slow != fast):
        slow = slow.next
        fast = fast.next.next

    if fast == slow:
        return None

    return slow


# len(A) >= len(B)
def combine_lists(A, B):

    new_list_head = ListNode(0)
    new_list = new_list_head

    while B:
        nexta = A.next
        nextb = B.next
        new_list.next = A
        new_list.next.next = B
        A = nexta
        B = nextb
        new_list = new_list.next.next

    if A:
        new_list.next = A
        new_list = new_list.next

    new_list.next = None

    return new_list_head.next


def solution(A):

    # get second half of the list (O(n))
    second_half = get_second_half(A)

    if not second_half:
        return A

    # Reverse the second half (O(n))
    second_half_rev = reverse_list(second_half)

    # Combine the reversed half with the first half (O(n))
    combined = combine_lists(A, second_half_rev)

    return combined


class TestReorderList(unittest.TestCase):

    def test_basic(self):
        A = [1, 2, 3]
        self.assertEqual([1, 3, 2], solution(ListNode.from_list(A)))

    def test_trivial_none(self):
        A = []
        self.assertEqual(None, solution(ListNode.from_list(A)))

    def test_trivial_one(self):
        A = [1]
        self.assertEqual([1], solution(ListNode.from_list(A)))

    def test_trivial_two(self):
        A = [1, 2]
        self.assertEqual([1, 2], solution(ListNode.from_list(A)))

    def test_example(self):
        A = [1, 2, 3, 4]
        self.assertEqual([1, 4, 2, 3], solution(ListNode.from_list(A)))

    def test_complex_even(self):
        A = [1, 6, 2, 10, 3, 7, 9, 8]
        self.assertEqual([1, 8, 6, 9, 2, 7, 10, 3], solution(ListNode.from_list(A)))

    def test_complex_odd(self):
        A = [1, 2, 3, 4, 5, 6, 7]
        self.assertEqual([1, 7, 2, 6, 3, 5, 4], solution(ListNode.from_list(A)))


if __name__ == '__main__':
    unittest.main()
