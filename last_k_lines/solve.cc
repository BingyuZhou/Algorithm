#include <fstream>
#include <iostream>
#include <string>

using namespace std;
/**
 * Write a method to print the last Klines of an input file using C++
 *
 * Circular array of string with size K
 */

void print_last_k_lines(char* file_name) {
  const int k = 10;
  string last_k[k];
  int p = 0;
  ifstream f(file_name);

  while (getline(f, last_k[p])) p = (p + 1) % k;

  for (int i = 0; i < k; ++i) {
    cout << last_k[p] << endl;
    p = (p + 1) % k;
  }
};

int main() {
  char file_name[] = "test.txt";
  print_last_k_lines(file_name);
}