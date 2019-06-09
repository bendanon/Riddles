import unittest

"""
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
"""


def solution(sum):

    product = 0

    for a in range(1, sum + 1):
        for b in range(1, sum + 1 - a):
            c = sum - a - b
            if a**2 + b**2 == c**2:
                product = a * b * c
                break

    return product


class Tests(unittest.TestCase):

    def test_for_345(self):
        self.assertEqual(solution(12), 60)

    def test_for_sum_1000(self):
        self.assertEqual(solution(1000), 31875000)


if __name__ == '__main__':
    unittest.main()
