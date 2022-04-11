#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """
    Calculating the winner of the game

    Args:
        x(number): is the number of rounds
        nums(array): fulling of n

    Return:
        - name of the player that won the most rounds
        - If the winner cannot be determined, return None
    """
    if not nums or x < 1:
        return None

    n_d = max(nums)

    playm = [
        True for _ in range(max(n_d + 1, 2))
    ]

    for i in range(2, int(pow(n_d, 0.5)) + 1):
        if not playm[i]:
            continue

        for j in range(i * i, n_d + 1, i):
            playm[j] = False

    playm[0] = False
    playm[1] = False
    j = 0

    for i in range(len(playm)):
        if playm[i]:
            j += 1
        playm[i] = j

    player1 = 0

    for n_d in nums:
        player1 += playm[n_d] % 2 == 1

    if player1 * 2 == len(nums):
        return None

    elif player1 * 2 > len(nums):
        return "Maria"

    else:
        return "Ben"
