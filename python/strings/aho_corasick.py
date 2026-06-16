from collections import deque


class AhoCorasick:
    def __init__(self):
        self.next = [{}]
        self.link = [0]
        self.out = [[]]

    def add(self, s, idx):
        u = 0
        for ch in s:
            if ch not in self.next[u]:
                self.next[u][ch] = len(self.next)
                self.next.append({})
                self.link.append(0)
                self.out.append([])
            u = self.next[u][ch]
        self.out[u].append(idx)

    def build(self):
        q = deque(self.next[0].values())
        while q:
            u = q.popleft()
            self.out[u] += self.out[self.link[u]]
            for ch, v in self.next[u].items():
                self.link[v] = self.next[self.link[u]].get(ch, 0)
                q.append(v)
            for ch, v in self.next[self.link[u]].items():
                self.next[u].setdefault(ch, v)

    def find(self, text):
        u = 0
        ans = []
        for i, ch in enumerate(text):
            u = self.next[u].get(ch, 0)
            for idx in self.out[u]:
                ans.append((i, idx))
        return ans
