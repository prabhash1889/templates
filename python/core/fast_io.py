import sys

data = sys.stdin.buffer.read().split()
it = iter(data)


def next_int():
    return int(next(it))


def next_str():
    return next(it).decode()


def write_lines(lines):
    sys.stdout.write("\n".join(map(str, lines)))
