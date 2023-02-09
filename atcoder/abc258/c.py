N, Q = map(int, input().split())
S = input()

X = 0

for _ in range(Q):
    t, x = map(int, input().split())

    if t == 1:
        X = (X + x) % N
    elif t == 2:
        print(S[(N - X + x - 1) % N])
    else:
        print("hoge")
