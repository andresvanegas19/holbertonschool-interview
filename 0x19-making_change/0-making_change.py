#!/usr/bin/python3
""" Making Change """


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest number of
    coins needed to meet a given amount total

    Args:
        coins ([list]): a list of the values of the coins in your possession
        total ([number]): amount

    Return:
        fewest number of coins needed to meet total, If total is 0 or less,
        return 0 and If total cannot be met by any number of coins you have
        return -1
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)

    i, n_coins = (0, 0)
    c_total = total
    l_coins = len(coins)

    while(i < l_coins and c_total > 0):
        if (c_total - coins[i]) >= 0:
            c_total -= coins[i]
            n_coins += 1
        else:
            i += 1

    check = c_total > 0 and n_coins > 0

    if check or n_coins == 0:
        return -1
    else:
        return n_coins

    # return -1 if check or n_coins == 0 else n_coins
