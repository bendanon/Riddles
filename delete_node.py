import unittest

"""
Delete a node from a singly-linked list, given only a variable pointing to that node.
"""


def delete_node(ptr):

    if ptr.next is None:
        raise Exception("Can't delete the last node!")
        return

    ptr.value = ptr.next.value
    ptr.next = ptr.next.next
    return False


class LinkedListNode(object):

    def __init__(self, value):
        self.value = value
        self.next = None


class TestDeleteNode(unittest.TestCase):

    def test_trivial(self):
        a = LinkedListNode('A')
        b = LinkedListNode('B')
        c = LinkedListNode('C')

        a.next = b
        b.next = c

        delete_node(b)

        self.assertEqual(a.next.value, c.value)


if __name__ == '__main__':
    unittest.main()
