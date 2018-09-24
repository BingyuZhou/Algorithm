import random
import timeit


def main():
    s = set()
    p = set()
    for i in range(10000):
        s.add(random.randint(-10000, 1000))
        p.add(random.randint(-10000, 1000))

    print(timeit.timeit('s.intersection(p)', globals=locals()))


if __name__ == "__main__":
    main()
