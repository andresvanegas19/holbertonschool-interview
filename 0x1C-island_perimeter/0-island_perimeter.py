#!/usr/bin/python3
""" Island Perimeter """


"""
0 represents water
1 represents land
Each cell is square, with a side length of 1
Cells are connected horizontally/vertically (not diagonally).
grid is rectangular, with its width and height not exceeding 100
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid

    Args:
        grid(List[int]) is a list of list of integers:

    Returns:
        perimeter of the island described in grid
    """
    i_perimeter = 0
    len_grid = len(grid)

    for row in range(len_grid):
        len_column = len(grid[row])
        for column in range(len_column):
            if grid[row][column] == 1:
                if row == 0 or grid[row - 1][column] == 0:
                    i_perimeter += 1

                if column == 0 or grid[row][column - 1] == 0:
                    i_perimeter += 1

                if row == len_grid - 1 or grid[row + 1][column] == 0:
                    i_perimeter += 1

                if column == len_column - 1 or grid[row][column + 1] == 0:
                    i_perimeter += 1

    return i_perimeter
