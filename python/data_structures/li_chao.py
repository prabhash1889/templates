INF = 10**30


class Line:
    def __init__(self, m=0, b=INF):
        self.m = m
        self.b = b

    def __call__(self, x):
        return self.m * x + self.b


class LiChao:
    def __init__(self, xs):
        self.xs = sorted(set(xs))
        self.n = len(self.xs)
        self.st = [Line() for _ in range(4 * max(1, self.n))]

    def add_line(self, line, p=1, l=0, r=None):
        if r is None:
            r = self.n
        m = (l + r) // 2
        x_l, x_m, x_r = self.xs[l], self.xs[m], self.xs[r - 1]
        cur = self.st[p]
        if line(x_m) < cur(x_m):
            self.st[p], line = line, cur
        if r - l == 1:
            return
        if line(x_l) < self.st[p](x_l):
            self.add_line(line, p << 1, l, m)
        elif line(x_r) < self.st[p](x_r):
            self.add_line(line, p << 1 | 1, m, r)

    def query(self, x, p=1, l=0, r=None):
        if r is None:
            r = self.n
        res = self.st[p](x)
        if r - l == 1:
            return res
        m = (l + r) // 2
        if x < self.xs[m]:
            return min(res, self.query(x, p << 1, l, m))
        return min(res, self.query(x, p << 1 | 1, m, r))
