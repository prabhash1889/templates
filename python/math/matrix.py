def mat_mul(a, b, mod=None):
    n, m, p = len(a), len(b), len(b[0])
    c = [[0] * p for _ in range(n)]
    for i in range(n):
        for k in range(m):
            if a[i][k]:
                for j in range(p):
                    c[i][j] += a[i][k] * b[k][j]
                    if mod:
                        c[i][j] %= mod
    return c


def mat_pow(a, e, mod=None):
    n = len(a)
    res = [[int(i == j) for j in range(n)] for i in range(n)]
    while e:
        if e & 1:
            res = mat_mul(res, a, mod)
        a = mat_mul(a, a, mod)
        e >>= 1
    return res
