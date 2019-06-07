import unittest
import random
import math


class LinkedListNode:
    value = 0
    next = None

    def __init__(self, value):
        self.value = value

def create_position_list(lst):

    nodeMap = {}

    for index in range(0, len(lst)):
        nodeMap[lst[index]] = LinkedListNode(lst[index])

    for key, node in nodeMap.items():
        node.next = nodeMap[lst[node.value - 1]]

    return nodeMap[lst[-1]]

def find_node_in_cycle(position_list_head):

    fast_runner, slow_runner = position_list_head, position_list_head

    while fast_runner.next:

        slow_runner = slow_runner.next
        fast_runner = fast_runner.next.next
        if fast_runner is slow_runner:
            break

    return fast_runner

def find_cycle_length(node_in_cycle):

    cycle_length = 1
    runner = node_in_cycle.next

    while node_in_cycle != runner:
        runner = runner.next
        cycle_length += 1

    return cycle_length

def find_first_node_in_cycle(position_list_head, cycle_length):

    back_runner = position_list_head
    front_runner = position_list_head

    for _ in range(0, cycle_length):
        front_runner = front_runner.next

    while front_runner != back_runner:
        front_runner = front_runner.next
        back_runner = back_runner.next

    return front_runner

def find_repeat(lst):
    """
    Find repeat, Optimize for space
    :param lst: a list of size n + 1 of integers of range 1...n
    :return: an integer that appears twice
    """

    position_list_head = create_position_list(lst)
    node_in_cycle = find_node_in_cycle(position_list_head)
    cycle_length = find_cycle_length(node_in_cycle)
    first_node_in_cycle = find_first_node_in_cycle(position_list_head, cycle_length)

    return first_node_in_cycle.value


class Test(unittest.TestCase):

    def test_linked_list(self):
        a = LinkedListNode(3)
        b = LinkedListNode(4)
        c = LinkedListNode(5)

        a.next = b
        b.next = c

        self.assertEqual(a.value, 3)
        self.assertEqual(a.next.value, 4)
        self.assertEqual(a.next.next.value, 5)


    def test_position_list(self):
        input = [2, 3, 1, 3]
        expected_output = LinkedListNode(3)
        expected_output.next = LinkedListNode(1)
        expected_output.next.next = LinkedListNode(2)
        expected_output.next.next.next = LinkedListNode(3)
        expected_output.next.next.next.next = expected_output.next

        output = create_position_list(input)

        for _ in range(0, len(input)):
            self.assertEqual(expected_output.value, output.value)
            self.assertEqual(expected_output.next.value, output.next.value)

    def test_find_node_in_cycle(self):
        a = LinkedListNode(1)
        b = LinkedListNode(2)
        a.next = b
        c = LinkedListNode(3)
        b.next = c
        d = LinkedListNode(4)
        c.next = d
        e = LinkedListNode(5)
        d.next = e
        e.next = c

        node = find_node_in_cycle(a)

        self.assertFalse(node in [a, b])
        self.assertTrue(node in [c, d, e])

    def test_find_cycle_length(self):
        a = LinkedListNode(1)
        b = LinkedListNode(2)
        a.next = b
        c = LinkedListNode(3)
        b.next = c
        d = LinkedListNode(4)
        c.next = d
        e = LinkedListNode(5)
        d.next = e
        e.next = c

        cycle_length = find_cycle_length(c)
        self.assertEqual(3, cycle_length)

        cycle_length = find_cycle_length(d)
        self.assertEqual(3, cycle_length)

        cycle_length = find_cycle_length(e)
        self.assertEqual(3, cycle_length)

    def test_find_last_node_in_cycle(self):
        a = LinkedListNode(1)
        b = LinkedListNode(2)
        a.next = b
        c = LinkedListNode(3)
        b.next = c
        d = LinkedListNode(4)
        c.next = d
        e = LinkedListNode(5)
        d.next = e
        e.next = c

        first = find_first_node_in_cycle(a, 3)
        self.assertEqual(c, first)


    def test(self):
        inputs = [([1, 2, 2, 3], 2), ([1, 2, 3, 3, 4], 3)]

        for i in inputs:
            self.assertEqual(find_repeat(i[0]), i[1])

    def test_fuzz(self):

        for _ in range(0,10):
            n = random.randint(3, 20)
            lst = []
            for i in range(0, n+1):
                lst.append(random.randint(1, n))

            r = find_repeat(lst)
            self.assertTrue(lst.count(r) > 1)


if __name__ == '__main__':
    unittest.main()
