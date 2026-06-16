MOD1 = 1_000_000_007
MOD2 = 1_000_000_009
BASE = 911382323


class RollingHash:
    def __init__(self, s):
        n = len(s)
        self.p1 = [1] * (n + 1)
        self.p2 = [1] * (n + 1)
        self.h1 = [0] * (n + 1)
        self.h2 = [0] * (n + 1)
        for i, ch in enumerate(s):
            x = ord(ch)
            self.p1[i + 1] = self.p1[i] * BASE % MOD1
            self.p2[i + 1] = self.p2[i] * BASE % MOD2
            self.h1[i + 1] = (self.h1[i] * BASE + x) % MOD1
            self.h2[i + 1] = (self.h2[i] * BASE + x) % MOD2

    def get(self, l, r):
        a = (self.h1[r] - self.h1[l] * self.p1[r - l]) % MOD1
        b = (self.h2[r] - self.h2[l] * self.p2[r - l]) % MOD2
        return a, b
