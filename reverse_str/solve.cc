#include "iostream"

/**
 * Reverse String: Implement a function void reversetchar* str) in C or C++
 * which reverses a null­ terminated string.
 */
using namespace std;

void reverse(char* str) {
  if (str != nullptr) {
    char* tail = str;

    while (*tail) {
      ++tail;
    }
    --tail;
    while (str < tail) {
      char tmp = *str;
      *str = *tail;
      *tail = tmp;
      ++str;
      --tail;
    }
  }
}

int main() {
  char a[] = "happy apple every day";
  cout << a << endl;
  reverse(a);
  cout << a << endl;
}