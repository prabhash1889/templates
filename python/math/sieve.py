def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[:2] = [False, False]
    primes = []
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            if i * i <= n:
                for j in range(i * i, n + 1, i):
                    is_prime[j] = False
    return primes, is_prime


def linear_sieve(n):
    lp = [0] * (n + 1)
    primes = []
    for i in range(2, n + 1):
        if lp[i] == 0:
            lp[i] = i
            primes.append(i)
        for p in primes:
            if p > lp[i] or i * p > n:
                break
            lp[i * p] = p
    return primes, lp
