import numpy
import math
import functionDefinitions
from lib import newton

# def function(x):
#     return math.log10(x) - (7 / (2 * x + 6))
# def derivative(x):
#     return math.pow((x * math.log(10)), -1) + (7 / (2 * math.pow(x+3, 2)))
# localization = 4
# print(newton.approximate_function(function, derivative, localization))

# localizations = numpy.array([-0.2, 1.1])
# def f1(x):
#     return math.sin(x[0]) + 2 * x[1] - 2
# def f2(x):
#     return x[0] + math.cos(x[1] - 1) - 0.7
# f = [f1, f2]
# def f1dx(x):
#     return math.cos(x[0])
# def f1dy(x):
#     return 2
# def f2dx(x):
#     return 1
# def f2dy(x):
#     return -1 * math.sin(x[1] + 1)
# fd = [[f1dx, f1dy], [f2dx, f2dy]]
# print(newton.approximate_sae(f, fd, localizations, 'default'))


# approximate_sae(functions: [callback], derivatives[callback][callback], localizations: [number], mode?: 'default' | 'modified', iterationsTilModified?: number)
# operation count INCLUDES: matrix multiplication, matrix addition, operations with matrix elements and matrix transmutations (considered a single operation because of pointer changes), and divisions during reverse substitution.
# operation count DOES NOT INCLUDE Jacobi matrix recomputations.
print(newton.approximate_sae(functionDefinitions.functions, functionDefinitions.differentials, functionDefinitions.localizations, 'default'))
print(newton.approximate_sae(functionDefinitions.functions, functionDefinitions.differentials, functionDefinitions.localizations, 'modified', 4)) # setting iteration threshold to 4 provides the same results as executing the default newton method

# the following calls crash on the computation of the first function, no idea why, as the exponent does not depend on x_5 in f1
print(newton.approximate_sae(functionDefinitions.functions, functionDefinitions.differentials, functionDefinitions.modifiedLocalizations, 'modified', 6))

print(newton.approximate_sae(functionDefinitions.functions, functionDefinitions.differentials, functionDefinitions.modifiedLocalizations, 'modified', 7))

print(newton.approximate_sae(functionDefinitions.functions, functionDefinitions.differentials, functionDefinitions.modifiedLocalizations, 'modified', 8))
