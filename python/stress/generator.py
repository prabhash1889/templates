import random


def gen(seed=None):
    random.seed(seed)
    n = random.randint(1, 10)
    a = [random.randint(0, 20) for _ in range(n)]
    return n, a


if __name__ == "__main__":
    n, a = gen()
    print(n)
    print(*a)
