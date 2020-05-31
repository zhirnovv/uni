import math
import numpy
from lib import integrals

a = 2.5
b = 4.3
alpha = 2 / 7
beta = 0

def f(x):
    return math.cos(1.5 * x) * math.exp(2 * x / 3) + 3 * math.sin(5.5 * x) * math.exp(-2 * x) + 2

exact_integral_value = 10.65722906811476196545133157861241468330
methodical_eval_integral = 0.373760077969103
diff_evaluation = 70

def moment_0(x):
    return 7/5 * math.pow((x - 5/2), 5/7)

def moment_1(x):
    return 7/24 * math.pow((x - 5/2), 5/7) * (2 * x + 7)

def moment_2(x):
    return 7/456 * math.pow((x - 5/2), 5/7) * (24 * math.pow(x, 2) + 70 * x + 245)

def moment_3(x):
    return (7 * math.pow(x - 5/2, 5/7) * (304 * math.pow(x, 3) + 840 * math.pow(x, 2) + 2450 * x + 8575)) / 7904

def moment_4(x):
    return (7 * math.pow(x - 5/2, 5/7) * (3952 * math.pow(x, 4) + 10640 * math.pow(x, 3) + 29400 * math.pow(x, 2) + 85750 * x + 300125)) / 130416

def moment_5(x):
    return (7 * math.pow(x - 5/2, 5/7) * (260832 * math.pow(x, 5) + 691600 * math.pow(x, 4) + 1862000 * math.pow(x, 3) + 5145000 * math.pow(x, 2) + 15006250 * x + 52521875)) / 10433280

iqf_moments = [moment_0, moment_1, moment_2]
gqf_moments = [moment_0, moment_1, moment_2, moment_3, moment_4, moment_5]

iqf = (integrals.iqf(f, a, b, iqf_moments))
methodical_eval = (integrals.methodical_eval(methodical_eval_integral, diff_evaluation, 3))
exact_eval = iqf - exact_integral_value

cqf_iqf, S_iqf = (integrals.cqf(f, a, b, iqf_moments, 2, integrals.iqf, exact_integral_value))

h_opt = integrals.h_optimal(f, a, b, 2, S_iqf)
cqf_opt, S_opt = integrals.cqf(f, a, b, iqf_moments, 2, integrals.iqf, exact_integral_value, h_opt)

gqf = (integrals.gqf(f, a, b, gqf_moments))

cqf_gqf, S_gqf = integrals.cqf(f, a, b, gqf_moments, 2, integrals.gqf, exact_integral_value)


print("Interpolational Quadratic Formula: ", iqf)
print("Methodical evaluation is: ", methodical_eval)
print("Exact evaluation is: ", exact_eval)
print("--------------------")
print("Compound Quadratic Formula using IQF: ", cqf_iqf, S_iqf)
print("Optimal CQF: ", cqf_opt, S_opt)
print("--------------------")
print("Gauss Quadratic Formula: ", gqf)
print("Compound Quadratic Formula using GQF: ", cqf_gqf, S_gqf)
