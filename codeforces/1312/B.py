t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    print(*reversed(a))