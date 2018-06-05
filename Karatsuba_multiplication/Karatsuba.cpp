#include <iostream>
#include <math.h>
using namespace std;

int karatsuba_mul(int n1, int n2)
{
    int len_n1 = to_string(n1).length();
    int len_n2 = to_string(n2).length();

    if (len_n1 == 1 | len_n2 == 1)
    {
        return n1 * n2;
    }
    int l1_h = len_n1 / 2;
    int l2_h = len_n2 / 2;
    int b = n1 % static_cast<int>(pow(10, l1_h));
    int a = n1 - b;
    int d = n2 % static_cast<int>(pow(10, l2_h));
    int c = n2 - d;

    return karatsuba_mul(a, c) * pow(10, (l1_h + l2_h) / 2) + karatsuba_mul(a, d) * pow(10, l1_h / 2) + karatsuba_mul(b, c) * pow(10, l2_h / 2) + karatsuba_mul(b, d);
}
int main()
{
    int a, b;
    cout << "Karatsuba algorithm:" << endl;
    cin >> a;
    cin >> b;

    int prod = karatsuba_mul(a, b);
    cout << prod << endl;
}