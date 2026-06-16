from collections import deque


def bfs(g, src):
    n = len(g)
    dist = [-1] * n
    parent = [-1] * n
    q = deque([src])
    dist[src] = 0
    while q:
        u = q.popleft()
        for v in g[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                parent[v] = u
                q.append(v)
    return dist, parent
