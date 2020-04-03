import unittest

"""

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

"""


def is_prime(number):
    if number == 2 or number == 3: return True
    if number % 2 == 0 or number < 2: return False
    for i in range(3, int(number**0.5)+1, 2):
        if number % i == 0:
            return False
    return True


def primes():

    """
    A generator of primes
    :return:
    """
    num = 2
    while True:
        if is_prime(num):
            yield num
        num += 1


def solution(number):

    largest = 0

    for prime in primes():
        if number % prime == 0 and prime > largest:
            largest = prime

        if prime > int(number**0.5):
            return largest


class TestLargestPrimeFactor(unittest.TestCase):

    def test_for_13195(self):
       self.assertEqual(solution(13195), 29)

    def test_is_prime(self):
        self.assertFalse(is_prime(0))
        self.assertFalse(is_prime(1))
        self.assertTrue(is_prime(2))
        self.assertTrue(is_prime(3))
        self.assertFalse(is_prime(4))
        self.assertTrue(is_prime(29))

    def test_largest_prime_12(self):
       self.assertEqual(solution(12), 3)

    def test_largest_prime_147(self):
        self.assertEqual(solution(147), 7)

    def test_largest_prime_600851475143(self):
        self.assertEqual(solution(600851475143), 6857)


if __name__ == '__main__':
    unittest.main()
