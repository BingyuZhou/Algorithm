import cProfile


def binarySearch(alist, item):
    first = 0
    last = len(alist) - 1
    found = False

    while (first <= last and not found):
        midpoint = (first + last) // 2

        if (alist[midpoint] == item):
            found = True
        else:
            if (item < alist[midpoint]):
                last = midpoint-1
            else:
                first = midpoint+1
    return found


def binarySearch_rec(alist, item):
    if len(alist) == 0:
        return False
    else:
        midpoint = len(alist)//2
        if(alist[midpoint] == item):
            return True
        else:
            if(item < alist[midpoint]):
                return binarySearch_rec(alist[:midpoint], item)
            else:
                return binarySearch_rec(alist[midpoint+1:], item)


def recurrence(alist, first, last, item):
    if(first > last):
        return False
    else:
        midpoint = (first+last)//2
        if(alist[midpoint] == item):
            return True
        else:
            if(item < alist[midpoint]):
                return recurrence(alist, first, midpoint-1, item)
            else:
                return recurrence(alist, midpoint+1, last, item)


def binarySearch_rec_imp(alist, item):
    return recurrence(alist, 0, len(alist)-1, item)


if __name__ == "__main__":
    alist = range(1000000000000000)
    item = 0
    r1 = binarySearch(alist, item)
    r2 = binarySearch_rec(alist, item)
    r3 = binarySearch_rec_imp(alist, item)
    print(r1)
    print(r2)
    print(r3)
    cProfile.run('binarySearch(alist, item)')
    cProfile.run('binarySearch_rec(alist, item)')
    cProfile.run('binarySearch_rec_imp(alist, item)')
