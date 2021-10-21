#!/usr/bin/python3

"""
The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard. Write a
program that solves the N queens problem.

sage: nqueens N
If the user called the program with the wrong number
of arguments, print Usage: nqueens N, followed by a new
line, and exit with the status 1
    where N must be an integer greater or equal to 4
    - If N is not an integer, print N must be a number, followed
    by a new line, and exit with the status 1

    - If N is smaller than 4, print N must be at least 4,
    followed by a new line, and exit with the status 1
"""

from sys import argv


def validate_table(large):
    """
    Validate the table

    Args:
        cell (list): [description]

    Returns:
        [type]: [description]
    """
    l_R = len(large) - 1

    difference = 0

    for i in range(0, l_R):
        difference = large[i] - large[l_R]

        if difference < 0:
            difference *= -1

        if difference == 0 or difference == l_R - i:
            return False

    return True


def resolve_quens(dim, row, large, outcome):
    """
    resolve the code

    Args:
        dim (int): [description]
        row (int): [description]
        large (list): [description]
        outcome (list): [description]
    """
    if row == dim:
        print(outcome)

    else:
        for col in range(0, dim):
            large.append(col)
            outcome.append([row, col])
            cond = validate_table(large)

            if (cond):
                resolve_quens(dim, row + 1, large, outcome)

            large.pop()
            outcome.pop()


if __name__ == "__main__":
    try:
        N = int(argv[1])
    except BaseException:  # Validate the number
        exit(1)
    if N < 4:  # be must be 4
        exit(1)
    else:
        resolve_quens(
            N,
            0,
            [],
            []
        )
