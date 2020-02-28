def calculate_series(n):
    sum = 0
    temp = 1
    for i in range(1, n+1):
        temp /= i
        sum += temp
    return sum


print(calculate_series(4))
