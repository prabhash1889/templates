class SegTree:
    def __init__(self, a_or_n, op=max, ident=-(10**30)):
        self.op = op
        self.ident = ident
        n0 = a_or_n if isinstance(a_or_n, int) else len(a_or_n)
        self.n = 1
        while self.n < n0:
            self.n <<= 1
        self.st = [ident] * (2 * self.n)
        if not isinstance(a_or_n, int):
            self.st[self.n:self.n + n0] = a_or_n
            for i in range(self.n - 1, 0, -1):
                self.st[i] = op(self.st[i << 1], self.st[i << 1 | 1])

    def set(self, i, value):
        i += self.n
        self.st[i] = value
        i >>= 1
        while i:
            self.st[i] = self.op(self.st[i << 1], self.st[i << 1 | 1])
            i >>= 1

    def query(self, l, r):
        left = self.ident
        right = self.ident
        l += self.n
        r += self.n
        while l < r:
            if l & 1:
                left = self.op(left, self.st[l])
                l += 1
            if r & 1:
                r -= 1
                right = self.op(self.st[r], right)
            l >>= 1
            r >>= 1
        return self.op(left, right)
