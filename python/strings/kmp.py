def prefix_function(s):
    pi = [0] * len(s)
    for i in range(1, len(s)):
        j = pi[i - 1]
        while j and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
        pi[i] = j
    return pi


def kmp_find(text, pattern):
    s = pattern + "#" + text
    pi = prefix_function(s)
    m = len(pattern)
    return [i - 2 * m for i in range(m + 1, len(s)) if pi[i] == m]
