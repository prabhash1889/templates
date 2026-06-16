class SparseTable:
    def __init__(self, a, op=min):
        self.op = op
        self.log = [0] * (len(a) + 1)
        for i in range(2, len(a) + 1):
            self.log[i] = self.log[i >> 1] + 1
        self.st = [a[:]]
        j = 1
        while (1 << j) <= len(a):
            prev = self.st[-1]
            span = 1 << (j - 1)
            self.st.append([op(prev[i], prev[i + span]) for i in range(len(a) - (1 << j) + 1)])
            j += 1

    def query(self, l, r):
        k = self.log[r - l]
        return self.op(self.st[k][l], self.st[k][r - (1 << k)])
