from collections import deque

INF = 10**30


class Dinic:
    def __init__(self, n):
        self.n = n
        self.g = [[] for _ in range(n)]

    def add_edge(self, u, v, cap):
        self.g[u].append([v, cap, len(self.g[v])])
        self.g[v].append([u, 0, len(self.g[u]) - 1])

    def max_flow(self, s, t):
        flow = 0
        while True:
            level = [-1] * self.n
            q = deque([s])
            level[s] = 0
            while q:
                u = q.popleft()
                for v, cap, _ in self.g[u]:
                    if cap and level[v] < 0:
                        level[v] = level[u] + 1
                        q.append(v)
            if level[t] < 0:
                return flow
            it = [0] * self.n

            def dfs(u, f):
                if u == t:
                    return f
                for i in range(it[u], len(self.g[u])):
                    it[u] = i
                    v, cap, rev = self.g[u][i]
                    if cap and level[v] == level[u] + 1:
                        ret = dfs(v, min(f, cap))
                        if ret:
                            self.g[u][i][1] -= ret
                            self.g[v][rev][1] += ret
                            return ret
                return 0

            while True:
                pushed = dfs(s, INF)
                if not pushed:
                    break
                flow += pushed
