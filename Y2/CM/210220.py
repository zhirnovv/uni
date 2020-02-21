import approximath
import math


def v(x):
    return approximath.sqrt(2*x + 0.45, 1e-6 / 6.75)


def u(v):
    return approximath.sinh(v, 1e-6 / 3.72)


def w(x):
    return approximath.arctg(6*x + 1, 1e-6 / 3.36)


def f(x):
    return u(v(x))/w(x)


def uDifferential(x):
    return 1 / w(x)


def vDifferential(x):
    return uDifferential(x) * (approximath.cosh(v(x)) / v(x))


def wDifferential(x):
    return u(v(x))/(pow(w(x), 2))


def vPrecise(x):
    return math.sqrt(2*x + 0.45)


def uPrecise(v):
    return math.sinh(v)


def wPrecise(x):
    return math.atan(6*x + 1)


def fPrecise(x):
    return uPrecise(vPrecise(x)) / wPrecise(x)


x = 0.01
while (x <= 0.06):
    delta = fPrecise(x) - f(x)
    print(f(x), fPrecise(x), delta)
    if (delta >= 1e-06):
        print('NOOOOOOO')
    x += 0.005
