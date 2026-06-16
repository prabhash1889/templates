MOD = 10**9 + 7


class Comb:
    def __init__(self, n, mod=MOD):
        self.mod = mod
        self.fact = [1] * (n + 1)
        self.ifact = [1] * (n + 1)
        for i in range(1, n + 1):
            self.fact[i] = self.fact[i - 1] * i % mod
        self.ifact[n] = pow(self.fact[n], mod - 2, mod)
        for i in range(n, 0, -1):
            self.ifact[i - 1] = self.ifact[i] * i % mod

    def ncr(self, n, r):
        if r < 0 or r > n:
            return 0
        return self.fact[n] * self.ifact[r] % self.mod * self.ifact[n - r] % self.mod
