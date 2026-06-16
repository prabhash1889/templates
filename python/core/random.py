import random

rng = random.Random()


def randint(l, r):
    return rng.randrange(l, r + 1)


def shuffle(a):
    rng.shuffle(a)
