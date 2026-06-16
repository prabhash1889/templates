class XorBasis:
    def __init__(self, bits=63):
        self.basis = [0] * bits

    def add(self, x):
        for i in range(len(self.basis) - 1, -1, -1):
            if not (x >> i) & 1:
                continue
            if not self.basis[i]:
                self.basis[i] = x
                return True
            x ^= self.basis[i]
        return False

    def max_xor(self, x=0):
        for b in reversed(self.basis):
            x = max(x, x ^ b)
        return x
