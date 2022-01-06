#!/usr/bin/python3
""" Rotate a matrix """


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees clockwise.
    conditionals:
        Do not return anything. The matrix must be edited in-place.
        You can assume the matrix will have 2 dimensions and will not be empty.

    Args:
        matrix (arr): the matrix
    """
    n = len(matrix)
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            matrix[i][j], matrix[j][n - i - 1], matrix[n - i - 1][n - j - 1], \
                matrix[n - j - 1][i] = matrix[n - j - 1][i], matrix[i][j], \
                matrix[j][n - i - 1], matrix[n - i - 1][n - j - 1]
