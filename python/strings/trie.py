class Trie:
    def __init__(self):
        self.next = [{}]
        self.end = [0]

    def add(self, s):
        u = 0
        for ch in s:
            if ch not in self.next[u]:
                self.next[u][ch] = len(self.next)
                self.next.append({})
                self.end.append(0)
            u = self.next[u][ch]
        self.end[u] += 1

    def count(self, s):
        u = 0
        for ch in s:
            if ch not in self.next[u]:
                return 0
            u = self.next[u][ch]
        return self.end[u]
