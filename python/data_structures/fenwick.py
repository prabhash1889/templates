class Fenwick:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, i, delta):
        i += 1
        while i <= self.n:
            self.bit[i] += delta
            i += i & -i

    def sum(self, r):
        s = 0
        while r > 0:
            s += self.bit[r]
            r -= r & -r
        return s

    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l)

    def lower_bound(self, target):
        idx = 0
        bit = 1 << (self.n.bit_length() - 1)
        while bit:
            nxt = idx + bit
            if nxt <= self.n and self.bit[nxt] < target:
                idx = nxt
                target -= self.bit[nxt]
            bit >>= 1
        return idx
