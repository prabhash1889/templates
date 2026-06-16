import sys

LOCAL = "LOCAL" in globals()


def debug(*args):
    if LOCAL:
        print(*args, file=sys.stderr)
