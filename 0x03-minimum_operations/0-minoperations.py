#!/usr/bin/python3
""" script that calculate the min operation """

def minOperations(n):
    """ there is a single character H.
        Your text editor can execute only
        two operations in this file:
        Copy All and Paste. Given a number n,
        write a method that calculates the
        fewest number of operations needed to
        result in exactly n H characters in the file.
    """
    operations = 0

    if n < 2:
        return 0

    end = n ** 0.5 + 1
    for start in range(2, int(end)):

        while n % start == 0:
            operations += start

            n //= start


    if n >= 2:
        operations += n

    return operations

