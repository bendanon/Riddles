import unittest


class Test(unittest.TestCase):

    def test(self):
        inputs = ["ABC", "ABCDEF"]

        for i in inputs:
            self.assertEqual(sorted(permutations(i)), sorted(permutations2(i)))


"""
permutations("ABC") = [ABC, ACB, BAC, BCA, CAB, CBA]
"""


def permutations(s):

    """
    This is a recursive function that goes through every letter in s and finds all permutations that START with it.
    :param s:
    :return: List of permutations of s
    """

    if len(s) == 1:
        return [s]

    p = []
    for index in range(0, len(s)):
        for permutation in permutations(s[:index] + s[index + 1:]):
            p += [s[index] + permutation]

    return p


def permutations2(s):

    """
    This is a recursive function that chooses the last letter in the s and injects it to every permutation of s
    without it.
    :param s:
    :return: List of permutations of s
    """

    if len(s) <= 1:
        return [s]

    all_chars_except_last = s[:-1]
    last_char = s[-1]

    perms_without_last = permutations2(all_chars_except_last)

    perms = []

    for p in perms_without_last:
        for i in range(len(all_chars_except_last) + 1):
            perms += [p[:i] + last_char + p[i:]]

    return perms


if __name__ == '__main__':
    unittest.main()
