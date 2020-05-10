n = int(input("N: "))

arr = [[0] * n] * n
print(arr)

t = 1

for i in range(n // 2):
    for j in range(i, n-i):
        arr[i][j] = t
        t += 1
        print(t)
    for j in range(i+1, n-i):
        arr[j][n-i-1] = t
        t += 1
        print(t)
    for j in reversed(range(n-2-i, i-1, -1)):
        arr[n-1-i][j] = t
        t += 1
        print(t)
    for j in reversed(range(n-i-2, i, -1)):
        arr[j][i] = t
        t += 1 
        print(t)
if n % 2 == 1:
    arr[n//2][n//2] = t

print(arr)

