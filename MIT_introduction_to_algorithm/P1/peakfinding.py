import numpy as np
from PIL import Image


def global_maximum(c):
    base = c[0]
    index = 0
    for i in range(c.shape[0]):
        if c[i] > base:
            index = i
            base = c[i]
    return index


def two_dim_peak_finding():
    A = np.random.randint(low=-100, high=100, size=(3, 3), dtype='int')
    print('Array is {}'.format(A))

    a = np.copy(A)

    while True:

        n, m = a.shape
        c = a[:, m//2]
        i = global_maximum(c)

        if (a[i, m//2] < a[i, min(m-1, m//2+1)]):
            a = np.copy(a[:, m//2:])
        elif (a[i, m//2] < a[i, max(0, m//2-1)]):
            a = np.copy(a[:, 0:m//2+1])
        else:
            peak = a[i, m//2]
            break
    print('Peak is {}'.format(peak))


def one_dim_peak_finding():
    A = np.random.randint(low=-1000000, high=1000000, size=1000000)
    print('Array is {} '.format(A))

    # Divide and Conque
    a = np.copy(A)
    peak = []
    while True:
        n = a.shape[0]
        if (a[n//2] < a[n//2-1]):  # Only need to look at the left array
            a = np.copy(a[0:n//2+1])
        elif (a[n//2] < a[n//2+1]):  # Only need to look at the right array
            a = np.copy(a[n//2:])
        else:  # Peak found!
            peak = a[n//2]
            break
    print('Peak is {}'.format(peak))


def main():
    print("This code shows algorithm for 1-D and 2-D peak finding problems.\n Please choose the problem type:\n 0->1D\n 1->2D")
    type = input()
    if type == '0':
        one_dim_peak_finding()
    else:
        two_dim_peak_finding()


if __name__ == "__main__":
    main()
