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
        op_count = 0
        Arr = swap_rows(Arr, k, i)
        Arr = swap_columns(Arr, k, j)
        op_count += 2

        return Arr, op_count

    matrix_length = len(A)
    op_count = 0

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
        op_count += 2
        L, l_op_count = pivot_matrix(L, k, i[0], j[0])
        U, u_op_count = pivot_matrix(U, k, i[0], j[0])

        op_count += l_op_count + u_op_count

        M = numpy.eye(matrix_length)
        for l in range(k+1, matrix_length):
            L[l, k] = U[l, k] / U[k, k]
            M[l, k] = (-1) * L[l, k]
            op_count += 2

        U = numpy.matmul(M, U)
        # matrix multiplication requires n^3 operations
        op_count += math.pow(matrix_length, 3)

    L = L + numpy.eye(matrix_length)
    # matrix addition requires n^2 operations
    op_count += math.pow(matrix_length, 2)

    return P, Q, L, U, op_count


def substitute(A, b, isUpper):
    op_count = 0
    roots = numpy.zeros(len(b))

    if isUpper:
        for i in reversed(range(0, len(b))):
            # number of comparisons to find the sum of len(b) - 1 + 1 elements of a matrix's row
            op_count += len(b) - i + 1
            op_count += 1  # consider division by A[i][i] as well
            if (A[i, i] != 0):
                roots[i] = (b[i]
                            - sum(A[i, j]*roots[j] for j in reversed(range(i, len(b)))))/A[i, i]
    else:
        for i in range(0, len(b)):
            # number of comparisons to find the sum of len(b) - 1 + 1 elements of a matrix's row
            op_count += len(b) - i + 1
            op_count += 1  # consider division by A[i][i] as well
            roots[i] = (b[i]
                        - sum(A[i, j]*roots[j] for j in range(0, i)))/A[i, i]

    return roots, op_count


def ls_solution(A, b):
    op_count = 0
    P, Q, L, U, d_op_count = matrix_decomposition(A)
    op_count += d_op_count

    Pb = numpy.matmul(P, b)
    op_count += math.pow(len(A), 3) # matrix multiplication requires n^3 operations

    y, y_op_count = substitute(L, Pb, False)
    z, z_op_count = substitute(U, y, True)
    op_count += y_op_count + z_op_count

    x = numpy.matmul(Q, z)
    op_count += math.pow(len(A), 3) # matrix multiplication requires n^3 operations

    return x, op_count


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

# k is the number of iterations


def dd_matrix(n):
    M = numpy.array(numpy.random.randint(-20, 20, size=(n, n)), float)
    numpy.fill_diagonal(M, 0)
    for i in range(n):
        M[i, i] = numpy.random.randint(
            0, 20) + sum(abs(M[i, j]) for j in range(n) if j != i)
    return M


def pd_matrix(n):
    M = numpy.array(numpy.random.randint(-9, 9, size=(n, n)), float)
    return numpy.matmul(M.transpose(), M)


def apriori_iteration_count(C, D, eps):
    C_norm = max(abs(C[i]).sum() for i in range(len(C)))
    D_norm = D.max()
    return (numpy.log(eps) + numpy.log(1-C_norm) - numpy.log(D_norm))/numpy.log(C_norm)


def jacobi_ls_solution(A, b, eps):
    print('DD Matrix: ')
    print(A)
    D_inv = numpy.zeros((len(A), len(A)))
    numpy.fill_diagonal(D_inv, 1 / numpy.diagonal(A))
    B = numpy.identity(len(A)) - numpy.matmul(D_inv, A)
    g = numpy.matmul(D_inv, b)
    k_apriori = apriori_iteration_count(B, g, eps)
    print('k_apriori:')
    print(k_apriori)
    prev_x = numpy.zeros(len(A))
    x = numpy.zeros(len(A))
    numpy.fill_diagonal(A, 0)
    k = 0
    while(k < 1000):
        for i in range(len(A)):
            x[i] = D_inv[i, i] * (b[i] - numpy.dot(A[i], prev_x))
        if abs(x - prev_x).max() < eps:
            break
        prev_x = x.copy()
        k += 1
    return x, k


def seidel_ls_solution(A, b, eps):
    print('PB Matrix: ')
    print(A)
    prev_x = numpy.zeros(len(A))
    x = numpy.zeros(len(A))
    k = 0
    while(k < 1000):
        x = numpy.copy(prev_x)
        for i in range(len(A)):
            before_sum = sum(A[i, j] * x[j] for j in range(i))
            after_sum = sum(A[i, j] * x[j] for j in range(i+1, len(A)))
            x[i] = b[i] - before_sum - after_sum
            x[i] /= A[i, i]
        if abs(x - prev_x).max() < eps:
            break
        prev_x = numpy.copy(x)
        k += 1
    return x, k
