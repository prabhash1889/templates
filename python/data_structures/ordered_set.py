from bisect import bisect_left, bisect_right, insort


class OrderedSet:
    def __init__(self, values=()):
        self.a = sorted(set(values))

    def add(self, x):
        i = bisect_left(self.a, x)
        if i == len(self.a) or self.a[i] != x:
            self.a.insert(i, x)

    def discard(self, x):
        i = bisect_left(self.a, x)
        if i < len(self.a) and self.a[i] == x:
            self.a.pop(i)

    def order_of_key(self, x):
        return bisect_left(self.a, x)

    def find_by_order(self, k):
        return self.a[k]
