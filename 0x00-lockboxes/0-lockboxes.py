#!/usr/bin/python3
''' Is a script to implementing lock boxes '''


def canUnlockAll(boxes):
    ''' This function return a boolena to mean about if all boxes can be
    opened, else return  false couse the boxes will not opened'''

    # check if there is empty boxes
    if len(boxes) == 1 and len(boxes[0]) == 0:
        return True

    validate = True
    i = 0
    end = total_len = len(boxes)
    counter = 0
    while boxes:
        if not len(boxes[i]) and counter == 0:
            validate = True
            counter += 1
            del boxes[i]
            end -= 1
            i -= 1

        for key in boxes[i]:
            if counter == key:
                counter += 1
                validate = True
                del boxes[i]
                end -= 1
                i -= 1
                break

        if (not validate and i == end - 1) or (total_len == counter):
            break

        # means reach the end of the boxes
        if end - 1 == i:
            validate = False
            i = -1

        i += 1

    if counter == total_len and len(boxes) == 0:
        return True

    return False
