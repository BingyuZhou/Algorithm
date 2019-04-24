#include <iostream>
using namespace std;

/**
 * 20 Alloc: Write a function in C called my2DA1loc which allocates a
 * two-dimensional array. Minimize the number of calls to malloc and make sure
 * that the memory is accessible by the notation arr [i] [j].
 */

int** solve(int rows, int cols) {
  // allocate array of pointers to row
  int** row_ptr = new int*[rows];

  // allocate cols for each row
  for (int i = 0; i < rows; ++i) {
    row_ptr[i] = new int[cols];
  }
  return row_ptr;
};

int main() {
  auto res = solve(2, 3);
  cout << res[1][2] << res[0][2] << endl;
}