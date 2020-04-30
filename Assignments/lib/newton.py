import numpy
import math
from lib import slae
from timeit import default_timer as timer


def approximate_function(function, derivative, localization, eps=1e-5):
    x_prev = localization
    x_next = localization-1
    start = timer()

    while(abs(x_next-x_prev) > eps):
        temp = x_prev
        x_prev = x_next
        x_next = temp - function(temp)/derivative(temp)

    end = timer()
    return x_next, end-start


def approximate_sae(functions, derivatives, localizations, mode, iterationsTilModified=1, eps=1e-5):
    roots_prev = numpy.copy(localizations)
    iter_count = 0 # iteration counter
    op_count = 0 # operation counter

    start = timer()

    def get_jacobi_matrix(derivatives, roots):
        A = numpy.array([[derivatives[i][j](roots_prev) for j in range(len(localizations))]
                         for i in range(len(localizations))])
        return A

    def get_coefficients(functions, roots):
        b = numpy.array([-1 * functions[i](roots_prev)
                         for i in range(len(localizations))])
        return b

    def get_delta(roots_next, roots_prev):
        return numpy.linalg.norm(roots_next - roots_prev)

    def newton_default_iteration(functions, derivatives, roots):
        A = get_jacobi_matrix(derivatives, roots)
        b = get_coefficients(functions, roots)
                
        temp_roots, op_count = slae.ls_solution(A, b)
        return A, temp_roots, op_count

    def newton_modified_iteration(functions, A, roots):
        b = get_coefficients(functions, roots)

        temp_roots, op_count = slae.ls_solution(A, b)
        return temp_roots, op_count

    if (mode == 'default'):
        while True:
            iter_count += 1
            _, temp_roots, linalg_op_count = newton_default_iteration(functions, derivatives, roots_prev)
            op_count += linalg_op_count
            roots_next = roots_prev + temp_roots

            if (get_delta(roots_next, roots_prev) < eps):
                break
            
            roots_prev = numpy.copy(roots_next)

    if (mode == 'modified'):
        k = 0

        while True:
            iter_count += 1
            if (k < iterationsTilModified):
                A, temp_roots, linalg_op_count = newton_default_iteration(functions, derivatives, roots_prev)
                op_count += linalg_op_count
                k += 1
            else:
                temp_roots, linalg_op_count = newton_modified_iteration(functions, A, roots_prev)
                op_count += linalg_op_count

            roots_next = roots_prev + temp_roots

            if (get_delta(roots_next, roots_prev) < eps):
                break

            roots_prev = numpy.copy(roots_next)

    end = timer()
    return roots_next, iter_count, op_count, end-start
