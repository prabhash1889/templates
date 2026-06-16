from heapq import heappop, heappush

INF = 10**30


def dijkstra(g, sources):
    n = len(g)
    dist = [INF] * n
    parent = [-1] * n
    pq = []
    for s in sources:
        dist[s] = 0
        heappush(pq, (0, s))
    while pq:
        du, u = heappop(pq)
        if du != dist[u]:
            continue
        for v, w in g[u]:
            nd = du + w
            if nd < dist[v]:
                dist[v] = nd
                parent[v] = u
                heappush(pq, (nd, v))
    return dist, parent


def restore_path(parent, t):
    path = []
    while t != -1:
        path.append(t)
        t = parent[t]
    return path[::-1]
