N, Q, X = map(int, input().split())
W = list(map(int, input().split()))

K = [int(input()) for _ in range(Q)]

all_W = sum(W)
X %= all_W

i = 0
i_list = []
i_list_idx = 0
i_list_idx_dict = {}
n_list = []
a = None
while True:
    if i in i_list_idx_dict:
        a = i_list_idx_dict[i]
        break

    n = 1
    sum_w = W[i]
    j = i
    while sum_w < X:
        j = (j + 1) % N
        n += 1
        sum_w += W[j]

    i_list.append(i)
    i_list_idx_dict[i] = i_list_idx
    i_list_idx += 1
    n_list.append(n)

    i = (j + 1) % N

# print(i_list)
# print(n_list)

for Ki in K:
    Ki -= 1

    if Ki < len(n_list):
        print(n_list[Ki])
    else:
        Ki_from_a = Ki - a
        Ki_from_a %= len(n_list) - a
        print(n_list[a + Ki_from_a])
