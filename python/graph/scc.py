def scc(g):
    n = len(g)
    order = []
    seen = [False] * n

    def dfs(u):
        seen[u] = True
        for v in g[u]:
            if not seen[v]:
                dfs(v)
        order.append(u)

    rg = [[] for _ in range(n)]
    for u in range(n):
        for v in g[u]:
            rg[v].append(u)
    for i in range(n):
        if not seen[i]:
            dfs(i)
    comp = [-1] * n

    def rdfs(u, c):
        comp[u] = c
        for v in rg[u]:
            if comp[v] == -1:
                rdfs(v, c)

    c = 0
    for u in reversed(order):
        if comp[u] == -1:
            rdfs(u, c)
            c += 1
    return comp, c
