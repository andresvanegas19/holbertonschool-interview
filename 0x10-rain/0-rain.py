#!/usr/bin/python3
""" rain trivial """


def rain(walls):
    """
    calculate how many square units of water will be retained after it rains

    args:
        walls: list of integers represultenting the height of the walls

    returns:
        integer represultenting the amount of water retained
    """

    len_wall = len(walls)
    result = 0

    for i in range(1, len_wall - 1):
        l_wall = walls[i]
        for j in range(i):
            l_wall = max(l_wall, walls[j])

        r_wall = walls[i]

        for j in range(i + 1, len_wall):
            r_wall = max(r_wall, walls[j])

        result += min(l_wall, r_wall) - walls[i]

    return result
