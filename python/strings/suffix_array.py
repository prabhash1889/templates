def suffix_array(s):
    s += "$"
    n = len(s)
    p = sorted(range(n), key=lambda i: s[i])
    c = [0] * n
    for i in range(1, n):
        c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]])
    k = 0
    while (1 << k) < n:
        p.sort(key=lambda i: (c[i], c[(i + (1 << k)) % n]))
        nc = [0] * n
        for i in range(1, n):
            cur = (c[p[i]], c[(p[i] + (1 << k)) % n])
            prev = (c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n])
            nc[p[i]] = nc[p[i - 1]] + (cur != prev)
        c = nc
        k += 1
    return p[1:]


def lcp_array(s, sa):
    n = len(s)
    rank = [0] * n
    for i, p in enumerate(sa):
        rank[p] = i
    h = 0
    lcp = [0] * (n - 1)
    for i in range(n):
        if rank[i] == n - 1:
            h = 0
            continue
        j = sa[rank[i] + 1]
        while i + h < n and j + h < n and s[i + h] == s[j + h]:
            h += 1
        lcp[rank[i]] = h
        if h:
            h -= 1
    return lcp
