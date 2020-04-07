import unittest
import math

"""
Design a stack that supports push, pop, top, and retrieving the minimum element 
in constant time.
"""


class MinStack:

    def __init__(self):
        self.s = []
        self.s_min = []

    # @param x, an integer
    def push(self, x):
        self.s.append(x)
        if len(self.s_min) == 0:
            self.s_min.append(x)
        else:
            self.s_min.append(min(self.s_min[-1], x))

    # @return nothing
    def pop(self):
        if len(self.s) == 0:
            return
        self.s.pop()
        self.s_min.pop()

    # @return an integer
    def top(self):
        if len(self.s) == 0:
            return -1

        return self.s[-1]

    # @return an integer
    def getMin(self):
        if len(self.s) == 0:
            return -1

        return self.s_min[-1]


class TestTemplate(unittest.TestCase):

    def test_basic(self):
        s = MinStack()
        s.push(1)
        s.push(2)
        self.assertEqual(1, s.getMin())
        self.assertEqual(2, s.top())
        s.pop()
        self.assertEqual(1, s.getMin())
        self.assertEqual(1, s.top())
        s.pop()

    def test_trivial(self):
        s = MinStack()
        self.assertEqual(-1, s.top())
        s.pop() # Nothing should happen
        self.assertEqual(-1, s.getMin())

    def test_negative(self):
        s = MinStack()
        s.push(-3)
        self.assertEqual(-3, s.getMin())
        s.push(1)
        self.assertEqual(1, s.top())
        self.assertEqual(-3, s.getMin())
        s.push(-2)
        self.assertEqual(-2, s.top())
        self.assertEqual(-3, s.getMin())

    def test_challenging(self):
        s = MinStack()
        s.push(1)
        s.push(2)
        s.push(-2)
        s.push(3)
        s.push(0)
        self.assertEqual(-2, s.getMin())
        s.pop()
        self.assertEqual(-2, s.getMin())
        s.pop()
        self.assertEqual(-2, s.getMin())
        s.pop()
        self.assertEqual(1, s.getMin())
        s.pop()
        self.assertEqual(1, s.getMin())
        s.pop()
        self.assertEqual(-1, s.getMin())


if __name__ == '__main__':
    unittest.main()
