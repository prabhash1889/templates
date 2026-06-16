INF = 10**30


def knuth_dp(n, cost):
    dp = [[0] * n for _ in range(n)]
    opt = [[0] * n for _ in range(n)]
    for i in range(n):
        opt[i][i] = i
    for length in range(2, n + 1):
        for l in range(n - length + 1):
            r = l + length - 1
            dp[l][r] = INF
            for k in range(opt[l][r - 1], opt[l + 1][r] + 1):
                val = (dp[l][k] if k > l else 0) + (dp[k + 1][r] if k < r else 0) + cost(l, r)
                if val < dp[l][r]:
                    dp[l][r] = val
                    opt[l][r] = k
    return dp, opt
