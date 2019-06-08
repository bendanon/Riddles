import unittest

"""
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""


def is_palindrome(num):
    """
    :param num:
    :return: True is num is a palindrome
    """
    num_str = str(num)
    length = len(num_str)

    first_half = num_str[:int(length/2)]
    second_half = num_str[int(length/2) + length % 2:]

    if first_half[::-1] == second_half:
        return True

    return False


def largest_palindrome_3_of_digit_factors():
    """
    :return: the largest palindrome made from the product of two 3-digit numbers.
    """
    largest_palindrome = 0
    for i in range(999, 99, -1):
        for j in range(999, 99, -1):
            if i * j > largest_palindrome and is_palindrome(j*i):
                largest_palindrome = i * j

    return largest_palindrome


class Tests(unittest.TestCase):

    def test_is_palindrome(self):
        self.assertTrue(is_palindrome(9009))
        self.assertFalse(is_palindrome(9099))
        self.assertTrue(is_palindrome(111))
        self.assertTrue(is_palindrome(11211))
        self.assertTrue(is_palindrome(12321))
        self.assertTrue(is_palindrome(1))


if __name__ == '__main__':
    print(largest_palindrome_3_of_digit_factors())
    unittest.main()
