import unittest
import math

"""
A hotel manager has to process N advance bookings of rooms for the next season. 
His hotel has K rooms. Bookings contain an arrival date and a departure date. 
He wants to find out whether there are enough rooms in the hotel to satisfy the demand.
arrival and departure on the same day doesn't require 2 separate rooms.
 
Write a program that solves this problem in time O(N log N) .
"""


def get_key(pair):
    return pair[0] + (pair[1] * 0.5)


# O(NlogN)
def solution(arrive, depart, K):
    """
    Booking i arrives at day arrive[i] and departs at day depart[i]

    :param arrive: list for arrival time of booking.
    :param depart: list for departure time of booking.
    :param K: count of rooms.
    :return: A boolean which tells whether its possible to make a booking.
    """

    event_points = []

    for a in arrive:
        event_points.append((a, 1))

    for d in depart:
        event_points.append((d, 0))

    event_points.sort(key=lambda x: get_key(x))
    num_of_guests = 0

    for i in range(len(event_points)):

        if event_points[i][1] == 1:
            num_of_guests += 1

        if event_points[i][1] == 0:
            num_of_guests -= 1

        if num_of_guests > K:
            return False

    return True


class TestHotelBookingsPossible(unittest.TestCase):

    def test_basic(self):
        arrive = [1, 3, 5]
        depart = [2, 4, 6]
        K = 1
        self.assertEqual(solution(arrive, depart, K), True)

    def test_trivial(self):

        # An edge case of a single booking
        arrive = [1]
        depart = [2]
        K = 1
        self.assertEqual(solution(arrive, depart, K), True)

        # No rooms, always return False
        K = 0
        self.assertEqual(solution(arrive, depart, K), False)

    def test_example(self):
        arrive = [1, 3, 5]
        depart = [2, 6, 8]
        K = 1
        self.assertEqual(solution(arrive, depart, K), False)

    def test_example_modified(self):
        arrive = [1, 3, 5]
        depart = [2, 6, 8]
        K = 2
        self.assertEqual(solution(arrive, depart, K), True)

    def test_identical_departure_and_arrival(self):
        arrive = [1, 2]
        depart = [1, 2]
        K = 1
        self.assertEqual(solution(arrive, depart, K), True)

    def test_multiple_arrivals_same_day(self):
        arrive = [1, 1, 1, 3, 3, 3]
        depart = [2, 2, 2, 4, 4, 4]
        K = 3
        self.assertEqual(solution(arrive, depart, K), True)
        K = 2
        self.assertEqual(solution(arrive, depart, K), False)

    def test_concurrent_arrival_departure(self):
        arrive = [1, 2, 3]
        depart = [2, 3, 4]
        K = 1
        self.assertEqual(solution(arrive, depart, K), True)

    def test_long_overlap(self):
        arrive = [1, 2, 3]
        depart = [10, 7, 4]
        K = 2
        self.assertEqual(solution(arrive, depart, K), False)
        K = 3
        self.assertEqual(solution(arrive, depart, K), True)

    def test_unsorted_long_overlap(self):
        arrive = [2, 1, 3]
        depart = [7, 10, 4]
        K = 2
        self.assertEqual(solution(arrive, depart, K), False)
        K = 3
        self.assertEqual(solution(arrive, depart, K), True)

    def test_partial_overlap(self):
        arrive = [1, 2, 4, 6]
        depart = [4, 3, 5, 7]
        K = 1
        self.assertEqual(solution(arrive, depart, K), False)
        K = 2
        self.assertEqual(solution(arrive, depart, K), True)


if __name__ == '__main__':
    unittest.main()
