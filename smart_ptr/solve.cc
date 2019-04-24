#include <iostream>
using namespace std;

/**
 * Write a smart pointer class. A smart pointer is a data type, usually
 * implemented with templates, that simulates a pointer while also providing
 * automatic garbage collection. It automatically counts the number of
 * references to a SmartPointer<T*> object and frees the object of type T when
 * the reference count hits zero.
 */

template <class T>
class smart_ptr {
 public:
  T* obj;
  int* count;
  // Construct from the obj, initial reference count to 1
  smart_ptr(T* object) {
    obj = object;
    count = new int;
    *count = 1;
  }
  // construct from an existing smart ptr, increase count by 1
  smart_ptr(smart_ptr<T>& ptr) {
    obj = ptr.obj;
    count = ptr.count;
    ++(*count);
  }

  ~smart_ptr() {
    --(*count);
    if (*count == 0) {
      cout << "deleting obj" << endl;
      delete count;
    }
  }

  // assign old smart_ptr to new smart_ptr. decrease the old ptr, then increase
  // the new ptr
  void operator=(smart_ptr<T>& ptr) {
    // if two ptr are different
    if (&ptr != this) {
      // decrease old ptr
      --(*count);
      if (*count == 0) {
        cout << "deleting obj" << endl;
        delete count;
      }
      // increase new ptr
      this->obj = ptr.obj;
      this->count = ptr.count;
      ++(*count);
    }
  }
};

int main() {
  int a = 3;
  smart_ptr<int> p(&a);
  cout << *p.count << endl;
  smart_ptr<int> p1(p);
  cout << *p1.count << endl;

  smart_ptr<int> p2 = p1;
  cout << *p2.count << endl;

  smart_ptr<int> p3(&a);
  cout << *p3.count << endl;
  p3 = p2;
  cout << *p3.count << endl;
}