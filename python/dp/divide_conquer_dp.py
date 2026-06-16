INF = 10**30


def divide_conquer_dp(prev, n, compute_cost):
    cur = [INF] * n

    def solve(l, r, opt_l, opt_r):
        if l >= r:
            return
        mid = (l + r) // 2
        best = (INF, opt_l)
        for k in range(opt_l, min(opt_r, mid) + 1):
            best = min(best, (prev[k] + compute_cost(k, mid), k))
        cur[mid] = best[0]
        solve(l, mid, opt_l, best[1])
        solve(mid + 1, r, best[1], opt_r)

    solve(0, n, 0, n - 1)
    return cur
