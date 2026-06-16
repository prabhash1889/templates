from bisect import bisect_left, bisect_right
from math import gcd

INF = 10**30
MOD = 10**9 + 7


def chmin(box, value):
    if value < box[0]:
        box[0] = value
        return True
    return False


def chmax(box, value):
    if value > box[0]:
        box[0] = value
        return True
    return False


def coordinate_compress(a):
    vals = sorted(set(a))
    return [bisect_left(vals, x) for x in a], vals
