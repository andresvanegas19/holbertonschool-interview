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


def validate_table(solve, temp):
    """
    Validate the table

    Args:
        cell (list): [description]

    Returns:
        [type]: [description]
    """
    for row in solve:
        if row[1] == temp[1]:
            return False

        if (row[0] + row[1]) == (temp[0] + temp[1]):
            return False

        if (row[0] - row[1]) == (temp[0] - temp[1]):
            return False

    return True


def resolve_quens(income, row, solve):
    """
    resolve the code

    Args:
        dim (int): [description]
        row (int): [description]
        large (list): [description]
        outcome (list): [description]
    """
    if (row == income):
        print(solve)

    else:
        for col in range(income):
            temp = [row, col]

            if validate_table(solve, temp):
                solve.append(temp)
                resolve_quens(row + 1, income, solve)
                solve.remove(temp)


if __name__ == "__main__":
    if len(argv) != 2:  # validate not more args
        exit(1)

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
        )
