#include <array>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class rod_cut {
 public:
  tuple<int, int> run(int len, const std::array<int, 10>& price_tab) {
    vector<int> r(len + 1, -1);  // Optimal price
    vector<int> split(len + 1);  // Split rod to two pieces
    r[0] = 0;
    for (int i = 1; i <= len; ++i) {
      for (int j = 1; j <= i; ++j) {
        if (price_tab[j - 1] + r[i - j] > r[i]) {
          r[i] = price_tab[j - 1] + r[i - j];
          split[i] = j;
        }
      }
    }
    return make_tuple(r[len], split[len]);
  }
};

int main() {
  rod_cut solve;
  array<int, 10> price_tab{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  auto result = solve.run(8, price_tab);
  cout << std::get<0>(result) << endl;
  cout << std::get<1>(result) << endl;
}