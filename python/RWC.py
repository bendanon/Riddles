import unittest
import random

"""
Design a DS that has Read, write and clear in O(1)
"""

class ReadWriteClearArray:

    storage = [0]
    versions = [0]
    size = 0
    version = 0

    def __init__(self, size):
        self.storage = [0] * size
        self.versions = [0] * size
        self.size = size

    def read(self, position):
        if self.versions[position] == self.version:
            return self.storage[position]
        return 0

    def write(self, position, value):
        self.storage[position] = value
        self.versions[position] = self.version

    def clear(self):
        self.version += 1


class TestRWCArray(unittest.TestCase):

    def test_trivial(self):
        arr = ReadWriteClearArray(5)
        arr.write(1, 2)
        self.assertEqual(arr.read(1), 2)
        arr.clear()
        self.assertEqual(arr.read(1), 0)

    def test_fuzz(self):
        size = 10
        arr = ReadWriteClearArray(size)

        for i in range(0, 100):

            # Simple read and write random values into random positions
            position, value = random.randint(0, size-1), random.randint(0, 100)
            arr.write(position, value)
            self.assertEqual(arr.read(position), value)

            # Clear and validate the array is clear
            arr.clear()
            for j in range(0, size):
                self.assertEqual(arr.read(j), 0)

            # Write after clear
            arr.write(position, value)
            self.assertEqual(arr.read(position), value)

            # Validate all but written cell is clear
            for j in range(0, size):
                if j != position:
                    self.assertEqual(arr.read(j), 0)


if __name__ == '__main__':
    unittest.main()
