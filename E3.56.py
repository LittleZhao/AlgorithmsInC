result = {}
str = raw_input("Please input your string:\n")

for i in str:
    if result.has_key(i):
        result[i] += 1
    else:
        result[i] = 1

for i in sorted(result.keys()):
    print "%c: %d" %(i, result[i])



