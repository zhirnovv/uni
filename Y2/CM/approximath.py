import math

DELTA = 1e-6


def sqrt(number, delta=DELTA):  # 10^-6 by default
    previousValue = 1.0
    currentValue = 0.5 * (number + 1)
    while abs(currentValue - previousValue) > delta:
        previousValue = currentValue
        currentValue = 0.5 * (currentValue + number / currentValue)
    return currentValue


def sinh(rad, delta=DELTA):
    def term(x, k):
        return (x ** (2*k + 1))/(math.factorial(2*k + 1))

    result = 0.0
    k = 0
    currentTerm = term(rad, k)
    while (abs(currentTerm)/3 > delta):
        result += currentTerm
        k += 1
        currentTerm = term(rad, k)
    return result


def cosh(rad, delta=DELTA):
    def term(x, k):
        return (x ** (2*k))/(math.factorial(2*k))

    result = 0.0
    k = 0
    currentTerm = term(rad, k)
    while (2 * abs(currentTerm) / 3 > delta):
        result += currentTerm
        k += 1
        currentTerm = term(rad, k)
    return result


def arctg(rad, delta=DELTA):
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
        while(currentTerm > delta):
            result += currentTerm
            k += 1
            currentTerm = lower_term(rad, k)
    else:
        result = math.pi * sign(rad) / 2
        currentTerm = greater_term(rad, k)
        while(abs(currentTerm) > delta):
            result -= currentTerm
            k += 1
            currentTerm = greater_term(rad, k)

    return result
