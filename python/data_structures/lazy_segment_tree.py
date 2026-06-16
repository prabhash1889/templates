class LazySegTree:
    def __init__(self, a):
        self.n = 1
        while self.n < len(a):
            self.n <<= 1
        self.st = [0] * (2 * self.n)
        self.lazy = [0] * (2 * self.n)
        self.st[self.n:self.n + len(a)] = a
        for i in range(self.n - 1, 0, -1):
            self.st[i] = self.st[i << 1] + self.st[i << 1 | 1]

    def _apply(self, p, l, r, add):
        self.st[p] += add * (r - l)
        self.lazy[p] += add

    def _push(self, p, l, r):
        if self.lazy[p] and r - l > 1:
            m = (l + r) // 2
            self._apply(p << 1, l, m, self.lazy[p])
            self._apply(p << 1 | 1, m, r, self.lazy[p])
            self.lazy[p] = 0

    def add(self, ql, qr, value, p=1, l=0, r=None):
        if r is None:
            r = self.n
        if qr <= l or r <= ql:
            return
        if ql <= l and r <= qr:
            self._apply(p, l, r, value)
            return
        self._push(p, l, r)
        m = (l + r) // 2
        self.add(ql, qr, value, p << 1, l, m)
        self.add(ql, qr, value, p << 1 | 1, m, r)
        self.st[p] = self.st[p << 1] + self.st[p << 1 | 1]

    def sum(self, ql, qr, p=1, l=0, r=None):
        if r is None:
            r = self.n
        if qr <= l or r <= ql:
            return 0
        if ql <= l and r <= qr:
            return self.st[p]
        self._push(p, l, r)
        m = (l + r) // 2
        return self.sum(ql, qr, p << 1, l, m) + self.sum(ql, qr, p << 1 | 1, m, r)
