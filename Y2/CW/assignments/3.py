def calculate_lucky_tickets(n):
    count = 0
    if (n % 2 != 0 or n == 0):
        return 'n should be even and greater than zero'
    number = '0' * n
    for i in range(10 ** (n-1), 10 ** (n)):
        # number = str(i)
        firstHalfSum = sum(map(int, number[:n//2]))
        secondHalfSum = sum(map(int, number[n//2:]))
        if (firstHalfSum == secondHalfSum):
            count += 1
    return count


print(calculate_lucky_tickets(6))
