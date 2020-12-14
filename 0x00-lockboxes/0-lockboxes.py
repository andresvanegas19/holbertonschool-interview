#!/usr/bin/python3
''' Is a script to implementing lock boxes '''

def canUnlockAll(boxes):
    ''' This function return a boolena to mean about if all boxes can be
    opened, else return  false couse the boxes will not opened'''
    # check if there is empty boxes
    if len(boxes) == 1 and len(boxes[0]) == 0:
        return True

    # it will find the max of the number it need to reach
    maxim = len(boxes)
    # for lock_box in boxes:
    #     if lock_box and maxim < max(lock_box):
    #         maxim = max(lock_box)

    # for lock_box in boxes:
    #     # iterar sobre cada una de las cajas
    #     if len(lock_box) == 0 and counter == 0:
    #         counter += 1
    # lock_box

    validate = True
    i = 0
    end = total_len = len(boxes)
    counter = 0
    while True:
        # Will check the empty boxes and count the 0

        #debuger
        # print('counter: ',counter)
        # print('i:', i)
        # if boxes:
        #     print('box:', boxes[i])
        # print(boxes)
        # print('validate:', validate)
        # print('end: ', end)
        # print('total len', total_len)
        # print('-' * 60)

        if boxes:
            if not len(boxes[i]) and counter == 0:
                # print(not len(boxes[i]), counter == 0)
                # print(boxes[i], counter)
                validate = True
                counter += 1
                del boxes[i]
                end -= 1
                i -= 1
                # del boxes[i]

            for key in boxes[i]:
                if counter == key:
                    # print(boxes)
                    # print(boxes[i])
                    counter += 1
                    validate = True
                    del boxes[i]
                    end -= 1
                    i -= 1
                    break

            if (validate == False and i == end - 1) or (total_len == counter):
                # print(total_len, counter)
                # print((validate == False and i == end - 1), (total_len - 1 == counter))
                break

            # means reach the end of the boxes
            if end - 1 == i:
                validate = False
                i = -1

            i += 1
        # condicional para parar el loop infinito
    # conditionals to retornar la respuesta
    # print(counter, end, total_len)
    # print(boxes, counter)
    # print(counter, total_len)A
    if counter == total_len and len(boxes) == 0:
        return True

    return False
