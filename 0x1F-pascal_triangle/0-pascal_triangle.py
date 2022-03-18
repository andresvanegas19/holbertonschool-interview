#!/usr/bin/python3
""" pascal triangle """


def pascal_triangle(n):
    """
    made the pascal’s triangle

    Args:
        n: height of triangle

    Returns:
        a list of lists of integers representing the Pascal’s triangle of n
    """
    if n <= 0:
        return []

    tri = []

    for i in range(n):
        sub = [1] * (i + 1)

        for j in range(i - 1):
            sub[j + 1] = tri[i - 1][j] + tri[i - 1][j + 1]

        tri.append(
            sub
        )

    return tri
