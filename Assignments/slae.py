import numpy

from lib import slae

numpy.set_printoptions(5)

n = 3
A = numpy.array(numpy.random.randint(-20, 20, size=(n, n)), float)
b = numpy.array(numpy.random.randint(-100, 100, n), float)
testA = numpy.array([[1, 2, 3], [2, 5, 6], [3, 6, 9]])
testB = [1, 2, 3]

print('Original array: ')
print(A)
print('Right hand value set: ')
print(b)

print('LU decomposition: ')
P, Q, L, U = slae.matrix_decomposition(A)
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

print('Determinant: ')
print(slae.determinant(A))

print('SLAE solution: ')
print(slae.ls_solution(A, b))

print('Inverse matrix: ')
print(slae.inverse_matrix(A))

print('Condition Number:')
print(slae.condition_number(A))

print('Rank:')
print(slae.rank(A))

print('Matrix consistency and generic solution if consistent: ')
print(slae.is_consistent(A, b))

print('QR decomposition: ')
Q, R = slae.qr_decomposition(A)
print('Q: ')
print(Q)
print('R: ')
print(R)
print('QR: ')
print(numpy.matmul(Q, R))

print('Linear system solution via QR-decomposition')
print(slae.qr_solve_linear_system(A, b))

print(slae.jacobi_ls_solution(slae.dd_matrix(n), b, 1e-6))
print(slae.seidel_ls_solution(slae.pd_matrix(n), b, 1e-6))
