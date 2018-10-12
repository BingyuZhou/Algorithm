from heap import *


class heap_delete(heap):
    def delete(self, i):
        # replace the deleted value with the last value in the heap,
        # then do the min_heapify
        self.A[i] = self.A[-1]
        self.A.pop()
        self.heapsize -= 1
        if (i <= self.heapsize):
            if (self.A[parent(i)] > self.A[i]):
                self.decrease_key(i, self.A[i])
            else:
                self.min_heapify(i)
