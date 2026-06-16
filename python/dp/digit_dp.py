from functools import lru_cache


def count_upto(n):
    digits = list(map(int, str(n)))

    @lru_cache(None)
    def dp(pos, tight, started, rem):
        if pos == len(digits):
            return int(started and rem == 0)
        limit = digits[pos] if tight else 9
        ans = 0
        for d in range(limit + 1):
            nt = tight and d == limit
            ns = started or d != 0
            ans += dp(pos + 1, nt, ns, (rem + d) % 3 if ns else 0)
        return ans

    return dp(0, True, False, 0)
