N, X = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]

ans = 99999999999999999999999
sum_t = 0
min_b = 9999999999

for i in range(N):
    sum_t += AB[i][0] + AB[i][1]
    X -= 1

    if X == 0:
        ans = min(ans, sum_t)
        break

    min_b = min(min_b, AB[i][1])
    ans = min(ans, sum_t + X * min_b)

print(ans)
