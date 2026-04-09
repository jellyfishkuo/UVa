import sys

for line in sys.stdin:
    m, n = map(int, line.split())
    if m == 0 and n == 0:
        break
    print(pow(m, n, 10))
