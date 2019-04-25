/**
 * Letters and Numbers: Given an array filled with letters and numbers, find the
 * longest subarray with an equal number of letters and numbers.
 */

#include <ctype.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string solve(string& s) {
  vector<int> delta(s.size());
  int count_letter = 0, count_number = 0;

  // count number of letters and numbers
  if (isalpha(s[0])) {
    count_letter++;
    delta[0] = count_letter - count_number;
  }
  if (isdigit(s[0])) {
    count_number++;
    delta[0] = count_letter - count_number;
  }
  for (int i = 1; i < s.size(); ++i) {
    if (isalpha(s[i])) {
      count_letter++;
      delta[0] = count_letter - count_number;
    }
    if (isdigit(s[i])) {
      count_number++;
      delta[0] = count_letter - count_number;
    }
  }

  // find the longest same value in delta
  unordered_map<int, int> table;  // remember the initial place
  int start_ind, max_length = 0;
  for (int i = 0; i < s.size(); ++i) {
    auto res = table.find(delta[i]);
    // meet the same value
    if (res != table.end()) {
      int len = i - res->second;
      if (len > max_length) {
        start_ind = res->second;
        max_length = len;
      }
    }  // remember initial place
    else {
      table[delta[i]] = i;
    }
  }

  return s.substr(start_ind, max_length);
}

int main() {
  string s = "123ertffedfsd32de2g3f3qQ8R4234FD";
  cout << solve(s) << endl;
}