import unittest

"""

If we list all the natural numbers below 10 that are multiples of 3 or 5,

we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

"""


def solution(upper_limit):
    """

    :param upper_limit:
    :return: sum
    """

    return sum([num for num in range(upper_limit) if num % 3 == 0 or num % 5 == 0])


class TestMultiplesOf3And5(unittest.TestCase):

    def test_for_1000(self):
        self.assertEquals(solution(1000), 233168)

    def test_for_10(self):
        self.assertEquals(solution(10), 23)

    def test_for_0(self):
        self.assertEquals(solution(0), 0)


if __name__ == '__main__':
    unittest.main()
