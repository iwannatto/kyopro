n, c, k = map(int, input().split())
t = [0 for i in range(n)]
for i in range(n):
    t[i] = int(input())
t.sort()

time_of_bus = 0
num_of_people = 0
num_of_bus = 0
for i in range(n):
    if time_of_bus == 0:
        time_of_bus = t[i] + k
        num_of_people = 1
        num_of_bus += 1
    elif t[i] <= time_of_bus and num_of_people < c:
        num_of_people += 1
    else:
        time_of_bus = t[i] + k
        num_of_people = 1
        num_of_bus += 1
print(num_of_bus)
