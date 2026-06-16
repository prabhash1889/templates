class HLD:
    def __init__(self, tree, root=0):
        n = len(tree)
        self.parent = [-1] * n
        self.depth = [0] * n
        self.heavy = [-1] * n
        self.head = [0] * n
        self.pos = [0] * n
        size = [1] * n

        def dfs(u):
            best = 0
            for v in tree[u]:
                if v == self.parent[u]:
                    continue
                self.parent[v] = u
                self.depth[v] = self.depth[u] + 1
                dfs(v)
                size[u] += size[v]
                if size[v] > best:
                    best = size[v]
                    self.heavy[u] = v

        dfs(root)
        cur = 0

        def decompose(u, h):
            nonlocal cur
            self.head[u] = h
            self.pos[u] = cur
            cur += 1
            if self.heavy[u] != -1:
                decompose(self.heavy[u], h)
                for v in tree[u]:
                    if v != self.parent[u] and v != self.heavy[u]:
                        decompose(v, v)

        decompose(root, root)

    def path_segments(self, a, b):
        ans = []
        while self.head[a] != self.head[b]:
            if self.depth[self.head[a]] < self.depth[self.head[b]]:
                a, b = b, a
            ans.append((self.pos[self.head[a]], self.pos[a] + 1))
            a = self.parent[self.head[a]]
        if self.depth[a] > self.depth[b]:
            a, b = b, a
        ans.append((self.pos[a], self.pos[b] + 1))
        return ans
