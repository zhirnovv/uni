import math
import numpy
from lib import slae

# Weight function is:
# math.pow(x - a, -alpha) * math.pow(b - x, -beta)

# interpolational quadratic formula
def iqf(f, a, b, moments):
    nodes = [a, (a + b)/2, b]
    n = len(nodes)

    calculated_moments = [moment(b) - moment(a) for moment in moments]

    function_matrix = numpy.array(
        [[math.pow(nodes[j], i) for j in range(n)] for i in range(0, n)])

    coefficients, _ = slae.ls_solution(function_matrix, calculated_moments)

    return numpy.sum([coefficients[i] * f(nodes[i]) for i in range(n)])

def methodical_eval(methodical_eval_integral, Mn, n):
    return Mn / math.factorial(n) * methodical_eval_integral

def aitken_growth_rate(sums, index, L):
    return -math.log((sums[index] - sums[index-1]) / (sums[index - 1] - sums[index - 2])) / math.log(L)

def richardson_eval(r, sums, steps, m):
    step_matrix = numpy.zeros([r + 1, r + 1])
    for i in range(r):
        step_matrix[::, i] = numpy.power(steps, i + m)
    step_matrix[::, r] = -1
    C, _ = slae.ls_solution(step_matrix, sums * -1)
    return C

# compound quadratic formula
def cqf(f, a, b, moments, L, method, exact_integral, h_opt = 1, eps = 1e-6):
    def convergence_table(sum, step):
        sums = numpy.array([sum])
        steps = numpy.array([step])
        return sums, steps

    section_count = h_opt
    while True:
        s = 0
        h = (b - a) / section_count

        for i in range(int(section_count)):
            s += method(f, a + h * i, a + h * (i + 1), moments)

        if section_count == h_opt:
            S, H = convergence_table(s, h)
        else:
            S = numpy.append(S, s)
            H = numpy.append(H, h)
        
        m = 3 # derived from aitken growth rate
        r = len(H) - 1

        if len(H) >= 3:
            m = aitken_growth_rate(S, r, L)

        C = richardson_eval(r, S, H, m) 

        if r == 0:
            delta = S[r] - exact_integral
        else:
            delta = S[r] - C[r]

        if abs(delta) < eps:
            break

        section_count *= L

    return s, S

def h_optimal(f, a, b, L, S, eps=1e-6):
    m = aitken_growth_rate(S, 2, L)

    h_opt = 0.95 * ((b - a) / math.pow(L, 2)) * math.pow(eps / abs((S[2] - S[1]) / (math.pow(L, m) - 1)), 1/m)

    return math.ceil((b - a) / h_opt)
        
# Tri-node Gauss quadratic formula
def gqf(f, a, b, moments):
    n = 3
    calculated_moments = [moment(b) - moment(a) for moment in moments]

    rhv = numpy.array(calculated_moments[n:])
    lhc = numpy.array([calculated_moments[i:i+n] for i in range(n)])
    nodes = numpy.zeros(len(rhv) + 1)
    nodes[0] = 1
    temp, _ = slae.ls_solution(lhc, rhv * -1)
    nodes[:0:-1] = temp
    roots = numpy.roots(nodes)

    root_matrix = numpy.array(
        [[math.pow(roots[j], i) for j in range(n)] for i in range(0, n)])

    coefficients, _ = slae.ls_solution(root_matrix, numpy.array(calculated_moments[:3]))
    
    return numpy.sum([coefficients[i] * f(roots[i]) for i in range(n)])



