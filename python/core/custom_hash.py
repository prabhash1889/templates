import random

RANDOM = random.randrange(1 << 61)


def splitmix64(x):
    x = (x + 0x9E3779B97F4A7C15) & ((1 << 64) - 1)
    x = ((x ^ (x >> 30)) * 0xBF58476D1CE4E5B9) & ((1 << 64) - 1)
    x = ((x ^ (x >> 27)) * 0x94D049BB133111EB) & ((1 << 64) - 1)
    return x ^ (x >> 31)


class SafeInt(int):
    def __hash__(self):
        return splitmix64(int(self) + RANDOM)
