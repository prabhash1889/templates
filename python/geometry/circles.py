from math import hypot

EPS = 1e-9


def circle_line_intersections(c, r, a, b):
    ax, ay = a[0] - c[0], a[1] - c[1]
    bx, by = b[0] - c[0], b[1] - c[1]
    dx, dy = bx - ax, by - ay
    A = dx * dx + dy * dy
    B = 2 * (ax * dx + ay * dy)
    C = ax * ax + ay * ay - r * r
    D = B * B - 4 * A * C
    if D < -EPS:
        return []
    D = max(0.0, D) ** 0.5
    ans = []
    for t in [(-B - D) / (2 * A), (-B + D) / (2 * A)]:
        ans.append((a[0] + (b[0] - a[0]) * t, a[1] + (b[1] - a[1]) * t))
    return ans[:1] if D <= EPS else ans


def circle_circle_intersections(c1, r1, c2, r2):
    d = hypot(c2[0] - c1[0], c2[1] - c1[1])
    if d > r1 + r2 + EPS or d + min(r1, r2) + EPS < max(r1, r2) or d <= EPS:
        return []
    a = (r1 * r1 - r2 * r2 + d * d) / (2 * d)
    h2 = r1 * r1 - a * a
    if h2 < -EPS:
        return []
    h = max(0.0, h2) ** 0.5
    x = c1[0] + a * (c2[0] - c1[0]) / d
    y = c1[1] + a * (c2[1] - c1[1]) / d
    rx = -(c2[1] - c1[1]) * h / d
    ry = (c2[0] - c1[0]) * h / d
    return [(x + rx, y + ry)] if h <= EPS else [(x + rx, y + ry), (x - rx, y - ry)]
