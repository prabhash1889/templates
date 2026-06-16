import random


def check(solve, brute, gen, tests=1000):
    for seed in range(tests):
        case = gen(seed)
        got = solve(*case)
        exp = brute(*case)
        if got != exp:
            print("WA seed", seed)
            print("case:", case)
            print("got:", got, "expected:", exp)
            return False
    print("OK")
    return True
