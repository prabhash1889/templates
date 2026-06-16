def centroid_decomposition(tree):
    n = len(tree)
    blocked = [False] * n
    size = [0] * n
    parent = [-1] * n

    def calc_size(u, p):
        size[u] = 1
        for v in tree[u]:
            if v != p and not blocked[v]:
                calc_size(v, u)
                size[u] += size[v]

    def find_centroid(u, p, total):
        for v in tree[u]:
            if v != p and not blocked[v] and size[v] * 2 > total:
                return find_centroid(v, u, total)
        return u

    def build(entry, p):
        calc_size(entry, -1)
        c = find_centroid(entry, -1, size[entry])
        parent[c] = p
        blocked[c] = True
        for v in tree[c]:
            if not blocked[v]:
                build(v, c)

    build(0, -1)
    return parent
