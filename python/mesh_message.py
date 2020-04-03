import unittest
from collections import deque

"""
Given information about active users on the network, find the shortest route for a message from one user (the sender) 
to another (the recipient). 

Return a list of users that make up this route.
"""


def find_shortest_route(network, sender, recipient):

    parent = {}
    route = []
    queue = deque([])

    if sender == recipient:
        return [sender]

    queue.append(sender)

    while len(queue) > 0:

        node = queue.popleft()

        neighbors = network[node]

        for neighbor in neighbors:

            if neighbor == recipient:
                route.append(recipient)
                node_on_route = node

                while node_on_route != sender:
                    route.append(node_on_route)
                    node_on_route = parent[node_on_route]

                route.append(sender)
                route.reverse()
                return route

            if not parent.get(neighbor) and not neighbor == sender:
                parent[neighbor] = node
                queue.append(neighbor)

    return route

class Test(unittest.TestCase):

    def test_example(self):
        network = {
            'Min': ['William', 'Jayden', 'Omar'],
            'William': ['Min', 'Noam'],
            'Jayden': ['Min', 'Amelia', 'Ren', 'Noam'],
            'Ren': ['Jayden', 'Omar'],
            'Amelia': ['Jayden', 'Adam', 'Miguel'],
            'Adam': ['Amelia', 'Miguel', 'Sofia', 'Lucas'],
            'Miguel': ['Amelia', 'Adam', 'Liam', 'Nathan'],
            'Noam': ['Nathan', 'Jayden', 'William'],
            'Omar': ['Ren', 'Min', 'Scott'],
            'Nathan': ['Noam'],
            'Scott': ['Omar'],
            'Lucas': ['Adam'],
            'Sofia': ['Adam'],
            'Liam': ['Miguel'],
            'Ben': []
        }

        shortest_route = find_shortest_route(network, 'Jayden', 'Adam')

        self.assertFalse(shortest_route == ['Jayden', 'Adam', 'Amelia'])
        self.assertTrue(shortest_route == ['Jayden', 'Amelia', 'Adam'])
        shortest_route = find_shortest_route(network, 'Omar', 'Noam')
        self.assertTrue(shortest_route in [['Omar','Min','William','Noam'],
                                           ['Omar','Min','Jayden','Noam'],
                                           ['Omar','Ren','Jayden','Noam']])

        shortest_route = find_shortest_route(network, 'Omar', 'Ben')
        self.assertEqual([], shortest_route)

        shortest_route = find_shortest_route(network, 'Ben', 'Omar')
        self.assertEqual([], shortest_route)

        shortest_route = find_shortest_route(network, 'Scott', 'Sofia')
        self.assertEqual(7, len(shortest_route))

        self.assertEqual(find_shortest_route(network, 'Ben', 'Ben'), ['Ben'])


if __name__ == '__main__':
    unittest.main()
