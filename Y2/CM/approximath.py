import math

EPSILON = 1e-6


def sqrt(number, epsilon=EPSILON):  # 10^-6 by default
    previousValue = 1.0
    currentValue = 0.5 * (number + 1)
    while abs(currentValue - previousValue) > epsilon:
        previousValue = currentValue
        currentValue = 0.5 * (currentValue + number / currentValue)
    return currentValue


def sinh(rad, epsilon=EPSILON):
    def term(x, k):
        return (x ** (2*k + 1))/(math.factorial(2*k + 1))

    result = 0.0
    k = 0
    currentTerm = term(rad, k)
    while (abs(currentTerm) > 3 * epsilon):  # multiplying the divider is more efficient
        result += currentTerm
        k += 1
        currentTerm = term(rad, k)
    return result


def cosh(rad, epsilon=EPSILON):
    def term(x, k):
        return (x ** (2*k))/(math.factorial(2*k))

    k = 0
    currentTerm = term(rad, k)
    result = currentTerm

    while (abs(currentTerm) > 1.5 * epsilon):
        k += 1
        currentTerm = term(rad, k)
        result += currentTerm

    return result


def arctg(rad, epsilon=EPSILON):
    def sign(x): return (1, -1)[x < 0]

    def lower_term(x, k):
        return pow(-1, k) * (x ** (2 * k + 1)) / (2 * k + 1)

    def greater_term(x, k):
        return pow(-1, k) * ((x ** (-1 * (2 * k + 1))) / (2 * k + 1))

    result = 0
    k = 0
    currentTerm = 0

    if (abs(rad) < 1):
        currentTerm = lower_term(rad, k)
        while(currentTerm > epsilon):
            result += currentTerm
            k += 1
            currentTerm = lower_term(rad, k)
    else:
        result = math.pi * sign(rad) * 0.5
        currentTerm = greater_term(rad, k)
        while(abs(currentTerm) > epsilon):
            result -= currentTerm
            k += 1
            currentTerm = greater_term(rad, k)

    return result
