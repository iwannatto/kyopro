n = int(input())
a = list(map(int, input().split()))
a.sort()

a_sum = [0 for i in range(n)]
a_sum[0] = a[0]
for i in range(1, n):
    a_sum[i] = a_sum[i - 1] + a[i]

cnt = 1
for i in range((n - 1) - 1, -1, -1):
    if a[i + 1] <= a_sum[i] * 2:
        cnt += 1
    else:
        break

print(cnt)
