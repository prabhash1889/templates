MOD = 10**9 + 7


class ModInt(int):
    def __new__(cls, value):
        return int.__new__(cls, value % MOD)

    def __add__(self, other):
        return ModInt(int(self) + int(other))

    def __sub__(self, other):
        return ModInt(int(self) - int(other))

    def __mul__(self, other):
        return ModInt(int(self) * int(other))

    def __truediv__(self, other):
        return self * ModInt(pow(int(other), MOD - 2, MOD))

    def __pow__(self, power):
        return ModInt(pow(int(self), power, MOD))
