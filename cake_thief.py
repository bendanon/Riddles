import unittest

"""
Write a function max_duffel_bag_value() that takes a list of cake type tuples and a weight capacity, 
and returns the maximum monetary value the duffel bag can hold.
"""

def max_duffel_bag_value(cake_tuples, capacity):
    """
    Finds the max duffel bag value
    :return:
    """
    d = {}

    for t in cake_tuples:
        if t[0] == 0 and t[1] > 0:
            return float('inf')

    for i in range(0, capacity+1):

        temp_max_value = 0

        for t in cake_tuples:
            if t[0] <= i:
                temp_max_value = max(temp_max_value, t[1] + d[i - t[0]])

        d[i] = temp_max_value

    return d[capacity]


class TestMaxDuffelBagValue(unittest.TestCase):

    def test_example(self):
        cake_tuples = [(7, 160), (3, 90), (2, 15)]
        capacity = 20
        self.assertEqual(max_duffel_bag_value(cake_tuples, capacity), 555)

    def test_inf(self):
        cake_tuples = [(0, 1), (1, 1)]
        capacity = 2
        self.assertEqual(max_duffel_bag_value(cake_tuples, capacity), float('inf'))

    def test_duplicate_weights(self):
        cake_tuples = [(1, 2), (2, 2), (1, 1), (2, 1)]
        capacity = 10
        self.assertEqual(max_duffel_bag_value(cake_tuples, capacity), 20)


if __name__ == '__main__':
    unittest.main()
