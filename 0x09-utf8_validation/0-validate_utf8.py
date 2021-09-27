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
        binary = 1 << 7

        if bit_n == 0:
            while binary & value_converted:
                # begging on UTF-8 char
                bit_n += 1
                binary = binary >> 1
            if bit_n == 0:  # 1 byte char
                continue
            if bit_n == 1 or bit_n > 4:
                return False

        else:
            if not (
                # significant bit
                #  byte == hay un UTF-8 char
                value_converted & 1 << 7
                and
                # significant bit
                # validate two most significant bits
                not (value_converted & 1 << 6)
            ):
                return False

        bit_n -= 1

    return bit_n == 0
