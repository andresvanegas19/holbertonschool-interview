#!/usr/bin/python3
""" script that reads stdin line by line """
import sys

FILE_SIZE = 0
HTTP_STATUS = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}


if __name__ == "__main__":

    size = 0
    try:
        for line in sys.stdin:
            size += 1
            split = line.split(" ")
            try:
                status = split[-2]
                FILE_SIZE += int(split[-1])

                if status in HTTP_STATUS:
                    HTTP_STATUS[status] += 1

            except Exception:
                pass

            if size % 10 == 0:
                print("File size: {}".format(FILE_SIZE))
                for key in sorted(HTTP_STATUS.keys()):
                    if HTTP_STATUS[key] == 0:
                        continue
                    print("{}: {}".format(key, HTTP_STATUS[key]))

        else:
            print("File size: {}".format(FILE_SIZE))
            for key in sorted(HTTP_STATUS.keys()):
                if HTTP_STATUS[key] == 0:
                    continue
                print("{}: {}".format(key, HTTP_STATUS[key]))

    # Raise this error when press exit
    except KeyboardInterrupt:
        print("File size: {}".format(size))
        for key in sorted(HTTP_STATUS.keys()):
            if HTTP_STATUS[key] == 0:
                continue
            print("{}: {}".format(key, HTTP_STATUS[key]))
