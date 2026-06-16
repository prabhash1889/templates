def find_bridges(g):
    n = len(g)
    tin = [-1] * n
    low = [0] * n
    bridges = []
    timer = 0

    def dfs(u, pe=-1):
        nonlocal timer
        tin[u] = low[u] = timer
        timer += 1
        for eid, v in g[u]:
            if eid == pe:
                continue
            if tin[v] != -1:
                low[u] = min(low[u], tin[v])
            else:
                dfs(v, eid)
                low[u] = min(low[u], low[v])
                if low[v] > tin[u]:
                    bridges.append((u, v))

    for i in range(n):
        if tin[i] == -1:
            dfs(i)
    return bridges
