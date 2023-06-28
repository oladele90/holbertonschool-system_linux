#!/usr/bin/python3
"""finds and replaces string with new string in memory"""

from sys import argv


def maps_parse(pid):

    """looks through the maps file and finds heap start-stop"""

    heap_start = None
    heap_stop = None
    try:
        with open("/proc/{:d}/maps".format(pid), "r") as f:
            for line in f:
                if line.endswith("[heap]\n"):
                    heap_start = \
                        [int(x, 16) for x in line.split(" ")[0].split("-")[0]]
                    heap_stop = \
                        [int(x, 16) for x in line.split(" ")[0].split("-")[1]]
    except Exception:
        exit(1)
    return heap_start, heap_stop


def change_mem(pid, search_string, replace_string, heap_start, heap_stop):

    """finds and replaces string with new string in memory"""

    try:
        with open("/proc/{:d}/mem".format(pid), "r+b") as fi:
            fi.seek(heap_start)
            heap_data = fi.read(heap_stop - heap_start)
            target = heap_data.find(search_string.encode())
            if target >= 0:
                fi.seek(heap_start + target)
                fi.write(replace_string.encode() + b'\x00')
            else:
                exit(1)
    except Exception:
        exit(1)

if __name__ == "__main__":
    if len(argv) < 4:
        exit(1)
    heap_start, heap_stop = maps_parse(int(argv[1]))
    change_mem(int(argv[1]), argv[2], argv[3], heap_start, heap_stop)
