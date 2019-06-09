import unittest

"""
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
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


def solution(target_prime_index):
    prime_index = 0
    answer = 0
    for p in primes():
        prime_index += 1
        if prime_index == target_prime_index:
            answer = p
            break

    return answer


class TestLargestPrimeFactor(unittest.TestCase):

    def test_for_6(self):
        self.assertEqual(solution(6), 13)

    def test_for_10001(self):
        self.assertEqual(solution(10001), 104743)


if __name__ == '__main__':
    unittest.main()
