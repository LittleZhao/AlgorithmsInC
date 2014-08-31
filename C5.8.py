def rule(l, r, h):
    m = l + (r-l)/2
    if h > 0:
        result[m] = h
        rule(l, m, h-1)

        rule(m, r, h-1)




result = {}
if __name__ == "__main__":
    l, r, h = 0, 128, 4
    rule(l, r, h)
    for i in (sorted(result.keys())):
        print("%d: %d " %(i, result[i]))


