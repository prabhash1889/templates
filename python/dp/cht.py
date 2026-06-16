from collections import deque


def bad(a, b, c):
    return (b[1] - a[1]) * (a[0] - c[0]) >= (c[1] - a[1]) * (a[0] - b[0])


class ConvexHullTrick:
    def __init__(self):
        self.lines = deque()

    def add_line(self, m, b):
        line = (m, b)
        while len(self.lines) >= 2 and bad(self.lines[-2], self.lines[-1], line):
            self.lines.pop()
        self.lines.append(line)

    def query(self, x):
        def val(line):
            return line[0] * x + line[1]
        while len(self.lines) >= 2 and val(self.lines[0]) >= val(self.lines[1]):
            self.lines.popleft()
        return val(self.lines[0])
