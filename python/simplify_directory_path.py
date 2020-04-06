import unittest
import math

"""
Given a string A representing an absolute path for a file (Unix-style).
Return the string A after simplifying the absolute path.
Note:
    Absolute path always begin with ’/’ ( root directory ).
    Path will not have whitespace characters.
"""


def solution(A):

    tokens = A.split('/')
    s = []
    for t in tokens[1:]:
        if t == '.' or t == '':
            continue
        elif t == '..':
            if len(s) > 0:
                s.pop()
        else:
            s.append(t)

    return '/' + '/'.join(s)


class TestTemplate(unittest.TestCase):

    def test_basic(self):
        A = "/home"
        self.assertEqual("/home", solution(A))

    def test_trivial(self):
        A = "/"
        self.assertEqual("/", solution(A))

    def test_trivial_2(self):
        A = "/../"
        self.assertEqual("/", solution(A))

    def test_trivial_2(self):
        A = "/../../../../"
        self.assertEqual("/", solution(A))

    def test_example_trivial(self):
        A = "/home/"
        self.assertEqual("/home", solution(A))

    def test_example(self):
        A = "/a/./b/../../c/"
        self.assertEqual("/c", solution(A))

    def test_complex(self):
        A = "/././home/../home/ben"
        self.assertEqual("/home/ben", solution(A))

    def test_complex_2(self):
        A = "/home/a/b/c/../../d/e/."
        self.assertEqual("/home/a/d/e", solution(A))


if __name__ == '__main__':
    unittest.main()
