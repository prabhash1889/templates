def egcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = egcd(b, a % b)
    return g, y, x - (a // b) * y


def crt(a1, m1, a2, m2):
    g, x, _ = egcd(m1, m2)
    if (a2 - a1) % g:
        return None
    lcm = m1 // g * m2
    t = ((a2 - a1) // g * x) % (m2 // g)
    return (a1 + m1 * t) % lcm, lcm
