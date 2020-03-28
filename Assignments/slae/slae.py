import numpy
import math
import scipy
import scipy.linalg
import pdb


def swap_rows(Arr, src, dest):
    if (dest != src):
        Cp = numpy.copy(Arr)
        Arr[src], Arr[dest] = Cp[dest], Cp[src]
    return Arr


def swap_columns(Arr, src, dest):
    if (dest != src):
        Cp = numpy.copy(Arr)
        Arr[::, src], Arr[::, dest] = Cp[::, dest], Cp[::, src]
    return Arr


def matrix_decomposition(A):

    def pivot_matrix(Arr, k, i, j):
        Arr = swap_rows(Arr, k, i)
        Arr = swap_columns(Arr, k, j)

        return Arr

    matrix_length = len(A)

    P = numpy.eye(matrix_length)
    Q = numpy.eye(matrix_length)
    L = numpy.zeros((matrix_length, matrix_length))
    U = numpy.copy(A)

    for k in range(matrix_length - 1):
        u = abs(U)

        if u[k:, k:].sum() < 1e-16:
            break

        i, j = numpy.where(u[k:, k:] == u[k:, k:].max())
        i[0] += k
        j[0] += k

        P = swap_rows(P, k, i[0])
        Q = swap_columns(Q, k, j[0])
        L = pivot_matrix(L, k, i[0], j[0])
        U = pivot_matrix(U, k, i[0], j[0])

        M = numpy.eye(matrix_length)
        for l in range(k+1, matrix_length):
            L[l, k] = U[l, k] / U[k, k]
            M[l, k] = (-1) * L[l, k]
        U = numpy.matmul(M, U)

    L = L + numpy.eye(matrix_length)

    return P, Q, L, U


def substitute(A, b, isUpper):
    roots = numpy.zeros(len(b))

    if isUpper:
        for i in reversed(range(0, len(b))):
            if (A[i, i] != 0):
                roots[i] = (b[i]
                            - sum(A[i, j]*roots[j] for j in reversed(range(i, len(b)))))/A[i, i]
    else:
        for i in range(0, len(b)):
            roots[i] = (b[i]
                        - sum(A[i, j]*roots[j] for j in range(0, i)))/A[i, i]

    return roots


def ls_solution(A, b):
    P, Q, L, U = matrix_decomposition(A)

    Pb = numpy.matmul(P, b)

    y = substitute(L, Pb, False)
    z = substitute(U, y, True)
    x = numpy.matmul(Q, z)

    return x


def determinant(A):
    _, _, _, U = matrix_decomposition(A)
    det = 1

    for i in range(len(A)):
        det *= U[i, i]

    return det


def inverse_matrix(A):
    invA = numpy.zeros((len(A), len(A)))

    for i in range(len(A)):
        e = [0] * len(A)
        e[i] = 1
        x = ls_solution(A, e)
        for j in range(len(A)):
            invA[j, i] = x[j]

    return invA


def matrix_norm(A):
    return max(sum(abs(A.T[i])) for i in range(len(A)))


def condition_number(A):
    invA = inverse_matrix(A)

    return matrix_norm(A) * matrix_norm(invA)


def rank(A):
    _, _, _, U = matrix_decomposition(A)
    _rank = 0
    for i in range(len(A)):
        if abs(U[i, i]) > 1e-16:
            _rank += 1

    return _rank


def is_consistent(A, b):
    P, Q, L, U = matrix_decomposition(A)
    _rank = rank(A)

    Pb = numpy.matmul(P, b)
    y = substitute(L, Pb, False)
    ext_U = numpy.column_stack((U, y))
    ext_rank = 0
    for i in range(len(y)):
        if abs(ext_U[i]).sum() > 1e-16:
            ext_rank += 1

    if (ext_rank != _rank):
        return False, None

    z = substitute(U, y, True)
    x = numpy.matmul(Q, z)

    return True, x


def qr_decomposition(A):
    def normalize(Arr_t):
        for i in range(len(Arr_t)):
            norm = math.sqrt(pow(Arr_t[i], 2).sum())
            for j in range(len(Arr_t)):
                Arr_t[i, j] = Arr_t[i, j] / norm
        return Arr_t

    A_t = A.transpose()
    B_t = numpy.zeros((len(A), len(A)))
    for i in range(len(A)):
        B_t[i] = A_t[i]
        for j in reversed(range(i)):
            c = numpy.dot(A_t[i], B_t[j])/numpy.dot(B_t[j], B_t[j])
            B_t[i] -= numpy.multiply(c, B_t[j])
    Q_t = normalize(B_t)

    Q = Q_t.transpose()
    R = numpy.matmul(Q_t, A)

    return Q, R


def qr_solve_linear_system(A, b):
    Q, R = qr_decomposition(A)
    Q_t = Q.transpose()
    Q_tb = numpy.matmul(Q_t, b)
    x = substitute(R, Q_tb, True)
    return x
