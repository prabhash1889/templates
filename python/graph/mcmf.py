from heapq import heappop, heappush

INF = 10**30


class MinCostMaxFlow:
    def __init__(self, n):
        self.n = n
        self.g = [[] for _ in range(n)]

    def add_edge(self, u, v, cap, cost):
        self.g[u].append([v, cap, cost, len(self.g[v])])
        self.g[v].append([u, 0, -cost, len(self.g[u]) - 1])

    def flow(self, s, t, need=INF):
        n = self.n
        pot = [0] * n
        total_flow = total_cost = 0
        while total_flow < need:
            dist = [INF] * n
            parent = [None] * n
            dist[s] = 0
            pq = [(0, s)]
            while pq:
                du, u = heappop(pq)
                if du != dist[u]:
                    continue
                for i, (v, cap, cost, _) in enumerate(self.g[u]):
                    nd = du + cost + pot[u] - pot[v]
                    if cap and nd < dist[v]:
                        dist[v] = nd
                        parent[v] = (u, i)
                        heappush(pq, (nd, v))
            if parent[t] is None:
                break
            for i in range(n):
                if dist[i] < INF:
                    pot[i] += dist[i]
            add = need - total_flow
            v = t
            while v != s:
                u, i = parent[v]
                add = min(add, self.g[u][i][1])
                v = u
            v = t
            while v != s:
                u, i = parent[v]
                e = self.g[u][i]
                e[1] -= add
                self.g[v][e[3]][1] += add
                total_cost += add * e[2]
                v = u
            total_flow += add
        return total_flow, total_cost
