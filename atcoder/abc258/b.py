N = int(input())
A = [input() for _ in range(N)]

ans = "0" * N


def max_of_seq_and_rev(s):
    def max_of_seq(s):
        for i in range(len(s)):
            tmp = s[i:] + s[:i]
            global ans
            ans = max(ans, tmp)
    max_of_seq(s)
    max_of_seq("".join(reversed(s)))


for line in A:
    max_of_seq_and_rev("".join(line))

for j in range(N):
    s = ""
    for i in range(N):
        s += A[i][j]
    max_of_seq_and_rev("".join(s))

for j in range(N):
    s = ""
    for i in range(N):
        s += A[i][(i + j) % N]
    max_of_seq_and_rev(s)

for j in range(N):
    s = ""
    for i in range(N):
        s += A[i][(N + j - i) % N]
    max_of_seq_and_rev(s)

print(ans)
