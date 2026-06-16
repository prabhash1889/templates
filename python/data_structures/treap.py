import random


class Node:
    __slots__ = ("key", "prio", "left", "right", "size")

    def __init__(self, key):
        self.key = key
        self.prio = random.randrange(1 << 30)
        self.left = None
        self.right = None
        self.size = 1


def size(t):
    return t.size if t else 0


def pull(t):
    if t:
        t.size = 1 + size(t.left) + size(t.right)
    return t


def split(t, key):
    if not t:
        return None, None
    if t.key < key:
        a, b = split(t.right, key)
        t.right = a
        return pull(t), b
    a, b = split(t.left, key)
    t.left = b
    return a, pull(t)


def merge(a, b):
    if not a or not b:
        return a or b
    if a.prio > b.prio:
        a.right = merge(a.right, b)
        return pull(a)
    b.left = merge(a, b.left)
    return pull(b)


def insert(t, key):
    a, b = split(t, key)
    return merge(merge(a, Node(key)), b)


def erase(t, key):
    a, b = split(t, key)
    mid, c = split(b, key + 1)
    return merge(a, c)
