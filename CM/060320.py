import pprint
import numpy
import scipy
import scipy.linalg

def pivot_matrix(matrix):
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

    matrix_length = len(matrix)
    P = numpy.eye(len(matrix))
    Q = numpy.eye(len(matrix))
    
    # rearrange permutation matrix
    for j in range(matrix_length):
        max_column_index = max(range(j, matrix_length), key=lambda i: abs(matrix[i][j]))
        max_row_index = max(range(j, matrix_length), key=lambda i: abs(matrix[j][i]))
        P = swap_rows(Q, j, max_row_index)
        Q = swap_columns(P, j, max_column_index)

    return P, Q


def decompose_matrix(A):
    matrix_length = len(A)

    L = numpy.zeros((matrix_length, matrix_length))
    U = numpy.zeros((matrix_length, matrix_length))

    P, Q = pivot_matrix(A)
    PA = numpy.matmul(P, A)
    PAQ = numpy.matmul(PA, Q)
    # compose first row of U and first column of L:
    for i in range(matrix_length):
        for k in range(i, matrix_length):
            U[i, k] = PAQ[i, k] - sum(L[i, j]*U[j, k] for j in range(i))

        for k in range(i, matrix_length):
            if (i == k):
                L[i, i] = 1
            else:
                L[k, i] = (PAQ[k, i] - sum(L[k, j]*U[j, i] for j in range(i)))/U[i, i]

    return (P, Q, L, U)


# A is a square matrix, b is a list of right hand values (same length as A)


def solve_linear_system(A, b):
    def back_substitute(A, b, isUpper):
        roots = [0.0 for i in range(0, len(b))]

        if isUpper:
            for i in reversed(range(0, len(b))):
                roots[i] = (b[i]
                            - sum(A[i, j]*roots[j] for j in reversed(range(i, len(b)))))/A[i, i]
        else:
            for i in range(0, len(b)):
                roots[i] = (b[i]
                            - sum(A[i, j]*roots[j] for j in range(0, i)))/A[i, i]

        return roots

    P, Q, L, U = decompose_matrix(A)
    Pb = numpy.matmul(P, b)
    y = back_substitute(L, Pb, False)
    z = back_substitute(U, y, True)
    x = numpy.matmul(Q, z)

    return x

def determinant(A):
    _, _, _, U = decompose_matrix(A)
    det = 1 

    for i in range(len(A)):
        det *= U[i, i]

    return det

def inverse_matrix(A):
    invA = numpy.zeros((len(A), len(A)))

    for i in range(len(A)):
        e = [0] * len(A)
        e[i] = 1
        x = solve_linear_system(A, e)
        for j in range(len(A)):
            invA[j, i] = x[j]
    
    return invA

def condition_number(A):
    def matrix_norm(A):
        return max(sum(abs(A.T[i])) for i in range(len(A)))

    invA = inverse_matrix(A)

    return matrix_norm(A) * matrix_norm(invA)

n = 5
A = numpy.array(numpy.random.randint(-20, 20, size=(n, n)), float)
b = numpy.array(numpy.random.randint(-100, 100, n), float)
print('Original array: ')
print(A)
print('Right hand value set: ')
print(b)
print('Decomposition: ')
P, Q, L, U = decompose_matrix(A)
print('P: ')
print(P)
print('Q: ')
print(Q)
print('L: ')
print(L)
print('U: ')
print(U)
print('PAQ: ')
print(numpy.matmul(numpy.matmul(P, A), Q))
print('LU: ')
print(numpy.matmul(L, U))
print('det(A): ')
print(determinant(A))
print('Ax=b, x=...')
print(solve_linear_system(A, b))
print('A^-1')
print(inverse_matrix(A))
print('Condition Number')
print(condition_number(A))
