import unittest

"""
Given an order string and a list of words, sort list according to order
"""


def key_func(order, word):
    """

    :param order: the given order with which we need to sort
    :param word: the word we need to translate to a sortable key
    :return: the key
    """

    key = ''

    for c in word:

        # Translate the position of the char in the order to a char in the
        # key string
        index = order.find(c)
        if index == -1:
            raise Exception(c + " is not in the alphabet")

        key = key + chr(index)

    return key


def solution(order, words):
    """

    :param order: the order to sort by
    :param words: the word to sort
    :return: a sorted list of words
    """

    return sorted(words, key=lambda word: key_func(order, word))


class TestSortAccordingToOrder(unittest.TestCase):

    def test_trivial(self):
        words = ["ben", "gal"]
        order = "abcdefghijklmnopqrstuvwxyz"
        words_sorted = solution(order, words)
        expected_solution = ["ben", "gal"]
        self.assertEqual(words_sorted, expected_solution)

    def test_one_replacement(self):
        words = ["ben", "gal"]
        order = "agcdefbhijklmnopqrstuvwxyz"
        words_sorted = solution(order, words)
        expected_solution = ["gal", "ben"]
        self.assertEqual(words_sorted, expected_solution)

    def test_multiple_words(self):
        words = ["gen", "ben", "gal"]
        order = "agcdefbhijklmnopqrstuvwxyz"
        words_sorted = solution(order, words)
        expected_solution = ["gal", "gen", "ben"]
        self.assertEqual(words_sorted, expected_solution)

    def test_bad_input(self):
        words = ["A", "ben", "gal"]
        order = "agcdefbhijklmnopqrstuvwxyz"
        flag = False
        try:
            solution(order, words)
        except:
            flag = True

        self.assertTrue(flag)

    def test_multiple_letters(self):
        words = ["abcdegj", "abcdebj", "gabcde"]
        order = "agcdefbhijklmnopqrstuvwxyz"
        words_sorted = solution(order, words)
        expected_solution = ["abcdegj", "abcdebj", "gabcde"]
        self.assertEqual(words_sorted, expected_solution)


if __name__ == '__main__':
    unittest.main()
