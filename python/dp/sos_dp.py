def sos_dp(a):
    n = (len(a) - 1).bit_length()
    f = a[:]
    for bit in range(n):
        for mask in range(1 << n):
            if mask & (1 << bit):
                f[mask] += f[mask ^ (1 << bit)]
    return f
