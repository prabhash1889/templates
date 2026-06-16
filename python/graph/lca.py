from collections import deque


class LCA:
    def __init__(self, tree, root=0):
        n = len(tree)
        self.LOG = max(1, n.bit_length())
        self.up = [[-1] * n for _ in range(self.LOG)]
        self.depth = [-1] * n
        q = deque([root])
        self.depth[root] = 0
        while q:
            u = q.popleft()
            for v in tree[u]:
                if v != self.up[0][u]:
                    self.up[0][v] = u
                    self.depth[v] = self.depth[u] + 1
                    q.append(v)
        for k in range(1, self.LOG):
            for v in range(n):
                p = self.up[k - 1][v]
                self.up[k][v] = -1 if p == -1 else self.up[k - 1][p]

    def lift(self, v, steps):
        k = 0
        while steps:
            if steps & 1:
                v = self.up[k][v]
            steps >>= 1
            k += 1
        return v

    def lca(self, a, b):
        if self.depth[a] < self.depth[b]:
            a, b = b, a
        a = self.lift(a, self.depth[a] - self.depth[b])
        if a == b:
            return a
        for k in range(self.LOG - 1, -1, -1):
            if self.up[k][a] != self.up[k][b]:
                a = self.up[k][a]
                b = self.up[k][b]
        return self.up[0][a]
