#!/usr/bin/python3
"""
Module for script that execute a parse task
"""


def validUTF8(data):
    """
    method that determines if a given data set represents
    a valid UTF-8 encoding.

    Args:
        data ([a]): [description]

    Returns:
        [bool]: True if data is a valid UTF-8
        encoding, else return False
    """
    bit_n = 0

    for value_converted in data:
        binary = format(value_converted, '#010b')[-8:]

        if bit_n == 0:

            for bit in binary:
                if bit == '0':
                    break

                bit_n = 1 + bit_n

            if bit_n == 0:
                continue

            if bit_n == 1 or bit_n > 4:
                return False
        else:
            validate = (
                binary[0] == '1' and binary[1] == '0'
            )
            if not validate:
                return False

        bit_n = 1 - bit_n

    return bit_n == 0
