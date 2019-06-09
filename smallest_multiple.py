import unittest
"""
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

"""


def divisible_by_all(candidate, num):

    for i in range(num, 1, -1):
        if candidate % i != 0:
            return False

    return True


def find_smallest_multiple(num):
    """
    Find the smallest multiple for every number i in 1...num.
    Uses the smallest multiple of i as an increment for finding the smallest multiple of 1...i+1
    :return: The smallest multiple of 1...num
    """

    smallest_multiple = num

    for i in range(1, num + 1):

        current = smallest_multiple

        while True:
            if divisible_by_all(current, i):
                smallest_multiple = current
                break
            current += smallest_multiple

    return smallest_multiple


class Tests(unittest.TestCase):

    def test_for_10(self):
        self.assertEqual(find_smallest_multiple(10), 2520)

    def test_for_20(self):
        self.assertEqual(find_smallest_multiple(20), 232792560)


if __name__ == '__main__':
    unittest.main()
