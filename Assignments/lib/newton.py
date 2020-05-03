import numpy
import math
from lib import slae
from timeit import default_timer as timer

class ImpreciseRootsError(Exception):
    pass

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


def get_jacobi_matrix(derivatives, roots):
    A = numpy.array([[derivatives[i][j](roots) for j in range(len(roots))]
                     for i in range(len(roots))])
    return A


def get_coefficients(functions, roots):
    b = numpy.array([-1 * functions[i](roots)
                     for i in range(len(roots))])
    return b


def get_delta(roots_next, roots_prev):
    return numpy.linalg.norm(roots_next - roots_prev)

def verify_coefficients(functions, roots, eps):
    coefficients = get_coefficients(functions, roots)
    print('f(x) values for computed roots: ', coefficients)
    for i in range(len(coefficients)):
        if (abs(coefficients[i]) > eps):
            raise ImpreciseRootsError

def newton_default_iteration(functions, derivatives, roots):
    A = get_jacobi_matrix(derivatives, roots)
    b = get_coefficients(functions, roots)

    temp_roots, op_count = slae.ls_solution(A, b)
    return A, temp_roots, op_count


def newton_modified_iteration(functions, P, Q, L, U, roots):
    op_count = 0
    b = get_coefficients(functions, roots)

    Pb = numpy.matmul(P, b)
    # matrix multiplication requires n^3 operations
    op_count += math.pow(len(roots), 3)

    y, y_op_count = slae.substitute(L, Pb, False)
    z, z_op_count = slae.substitute(U, y, True)
    op_count += y_op_count + z_op_count

    temp_roots = numpy.matmul(Q, z)
    # matrix multiplication requires n^3 operations
    op_count += math.pow(len(roots), 3)

    return temp_roots, op_count


def default_sae_approximation(functions, derivatives, localizations, eps=1e-5):
    roots_prev = numpy.copy(localizations)
    iter_count = 0  # iteration counter
    op_count = 0  # operation counter

    start = timer()

    try:
        while iter_count < 20000:
            iter_count += 1
            _, temp_roots, linalg_op_count = newton_default_iteration(
                functions, derivatives, roots_prev)
            op_count += linalg_op_count
            roots_next = roots_prev + temp_roots

            if (get_delta(roots_next, roots_prev) < eps):
                verify_coefficients(functions, roots_next, eps)
                end = timer()
                return roots_next, iter_count, op_count, end-start

            roots_prev = numpy.copy(roots_next)
        
        return 'Iteration count exceeded 2000: breaking.'

    except ImpreciseRootsError:
        return 'One or more functions of a system are too great with computed roots'

    except OverflowError:
        return 'System does not converge'


def modified_sae_approximation(functions, derivatives, localizations, iteration_threshold=1, eps=1e-5):
    roots_prev = numpy.copy(localizations)
    iter_count = 0  # iteration counter
    op_count = 0  # operation counter
    L_is_generated = False

    start = timer()

    try:
        while iter_count < 20000:
            if (iter_count < iteration_threshold):
                A, temp_roots, linalg_op_count = newton_default_iteration(
                    functions, derivatives, roots_prev
                )
                op_count += linalg_op_count
            else:
                if not L_is_generated:
                    P, Q, L, U, d_op_count = slae.matrix_decomposition(A)
                    op_count += d_op_count
                    L_is_generated = True

                temp_roots, linalg_op_count = newton_modified_iteration(
                    functions, P, Q, L, U, roots_prev
                )

                op_count += linalg_op_count

            iter_count += 1

            roots_next = roots_prev + temp_roots
            if (get_delta(roots_next, roots_prev) < eps):
                verify_coefficients(functions, roots_next, eps)
                end = timer()
                return roots_next, iter_count, op_count, end - start

            roots_prev = numpy.copy(roots_next)

        return 'Iteration count exceeded 20000: breaking.'

    except ImpreciseRootsError:
        return 'One or more functions of a system are too great with computed roots'

    except OverflowError:
        return 'System does not converge'


def hybrid_sae_approximation(functions, derivatives, localizations, iteration_multiplier=1, eps=1e-5):
    try:
        roots_prev = numpy.copy(localizations)
        iter_count = 0  # iteration counter
        op_count = 0  # operation counter
        L_is_generated = False

        start = timer()

        while iter_count < 20000:
            if (iter_count % iteration_multiplier == 0):
                A, temp_roots, linalg_op_count = newton_default_iteration(
                    functions, derivatives, roots_prev
                )
                L_is_generated = False
                op_count += linalg_op_count
            else:
                if not L_is_generated:
                    P, Q, L, U, d_op_count = slae.matrix_decomposition(A)
                    op_count += d_op_count
                    L_is_generated = True

                temp_roots, linalg_op_count = newton_modified_iteration(
                    functions, P, Q, L, U, roots_prev
                )

                op_count += linalg_op_count

            roots_next = roots_prev + temp_roots

            if (get_delta(roots_next, roots_prev) < eps):
                verify_coefficients(functions, roots_next, eps)
                end = timer()
                return roots_next, iter_count, op_count, end - start

            roots_prev = numpy.copy(roots_next)
            iter_count += 1

        return 'Iteration count exceeded 20000: breaking.'

    except ImpreciseRootsError:
        return 'One or more functions of a system are too great with computed roots'

    except OverflowError:
        return 'System does not converge.'
        
