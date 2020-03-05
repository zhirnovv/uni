import pprint
import numpy
import scipy
import scipy.linalg

A = numpy.array([[7, 3, -1, 2], [3, 8, 1, -4], [-1, 4, 1, -1], [2, -4, 6, 1]])
# scipy implementation
P, L, U = scipy.linalg.lu(A)


def pivot_matrix(matrix):
    print(matrix)

    matrix_length = len(matrix)
    perm_matrix = [[float(i == j) for i in range(matrix_length)]
                   for j in range(matrix_length)]

    # rearrange permutation matrix
    for j in range(matrix_length):
        max_column_index = max(
            range(j, matrix_length), key=lambda i: abs(matrix[i][j]))
        if (max_column_index != j):
            perm_matrix[j], perm_matrix[max_column_index] = perm_matrix[max_column_index], perm_matrix[j]

    return perm_matrix


def decompose_matrix(A):
    matrix_length = len(A)

    L = [[0.0] * matrix_length for i in range(matrix_length)]
    U = [[0.0] * matrix_length for i in range(matrix_length)]

    P = pivot_matrix(A)
    PA = numpy.matmul(P, A)
    for j in range(matrix_length):
        L[j][j] = 1.0

        for i in range(j+1):
            s1 = sum(U[k][j] * L[i][k] for k in range(i))
            U[i][j] = PA[i][j] - s1

        for i in range(j, matrix_length):
            s2 = sum(U[k][j] * L[i][k] for k in range(j))
            L[i][j] = (PA[i][j] - s2) / U[j][j]

    return (P, L, U)


pprint.pprint(decompose_matrix(A))
