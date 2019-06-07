import unittest

"""
Given the list of IDs, which contains many duplicate integers and one unique integer, 
find the unique integer.
"""

def find_unique_integer(list):
    """
    Finds a unique integer in a list of duplicates
    :return: The unique integer
    """

    xor = 0
    for item in list:
        xor ^= item

    return xor


class TestFindUniqueInteger(unittest.TestCase):

    def test_trivial(self):
        list = [1, 2, 2, 3, 3]
        self.assertEqual(find_unique_integer(list), 1)

    def test_different_order(self):
        list = [2, 1, 2, 3, 3]
        self.assertEqual(find_unique_integer(list), 1)

if __name__ == '__main__':
    unittest.main()
