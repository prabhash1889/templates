def solve_brute(a):
    ans = 0
    for i in range(len(a)):
        for j in range(i, len(a)):
            ans = max(ans, sum(a[i:j + 1]))
    return ans
