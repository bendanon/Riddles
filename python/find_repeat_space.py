import unittest
import random
import math

"""
Given a singly-linked a list of size n + 1 of integers of range 1...n, 
find a repeat in O(nlog(n)) runtime and O(1) space
"""


def find_repeat(lst):
    """
    Divides the space of 1...n to two ranges (x, y), counts list nums in
    options 1 which are x <= num <= y, if pigeonhole principle holds,
    recursively.
    :param lst: a list of size n + 1 of integers of range 1...n
    :return: an integer that appears twice
    """

    n = len(lst) - 1

    option_one = (1, math.floor(n / 2))
    option_two = (math.floor(n / 2) + 1, n)
    current_option = option_one

    duplicate = 0
    found_duplicate = False

    while not found_duplicate:

        nums_in_range = len([num for num in lst if num in range(current_option[0], current_option[1] + 1)])
        size_of_range = current_option[1] - current_option[0] + 1

        # Means current_option[1] == current_option[0] and it is a duplicate
        if size_of_range == 1 and nums_in_range > 1:
            duplicate = current_option[0]
            found_duplicate = True
            continue

        # Means the duplicate is in this range (pigeonhole principle)
        if nums_in_range > size_of_range:
            midpoint = math.floor((current_option[0] + current_option[1]) / 2)
            option_one = (current_option[0], midpoint)
            option_two = (midpoint + 1, current_option[1])

            current_option = option_one
        else:
            current_option = option_two

    return duplicate


class Test(unittest.TestCase):

    def test(self):
        inputs = [([1, 2, 2, 3], 2), ([1, 2, 3, 3, 4], 3)]

        for i in inputs:
            self.assertEqual(find_repeat(i[0]), i[1])

    def test_fuzz(self):

        for _ in range(0, 10):
            n = random.randint(3, 20)
            lst = []
            for i in range(0, n+1):
                lst.append(random.randint(1, n))

            r = find_repeat(lst)
            self.assertTrue(lst.count(r) > 1)


if __name__ == '__main__':
    unittest.main()
