#include <iostream>
#include <string>
using namespace std;

int make_length_equal(string &a, string &b)
{
    int len_n1 = a.length();
    int len_n2 = b.length();

    if (len_n1 != len_n2)
    {
        string str;
        if (len_n1 > len_n2)
        {
            for (int i = 0; i < len_n1 - len_n2; i++)
                str.append("0");
            str.append(b);
            b = str;
            return len_n1;
        }
        else
        {
            for (int i = 0; i < len_n2 - len_n1; i++)
                str.append("0");
            str.append(a);
            a = str;
            return len_n2;
        }
    }
    return len_n1;
}

string minus_fun(string a, string b)
{
    string sum;
    string str1, str2;
    int len = make_length_equal(a, b);

    int flag = 0;
    for (int i = len - 1; i >= 0; i--)
    {

        int first = a.at(i) - '0';
        int second = b.at(i) - '0';
        int sum_bit = first - second + flag;
        if (sum_bit < 0)
        {
            sum_bit += 10;
            flag = -1;
        }
        else
            flag = 0;
        sum = to_string(sum_bit) + sum;
    }
    if (flag == -1)
        cout << "Wrong" << endl;
    return sum;
}

string add(string a, string b, int n, int m)
{
    string sum;
    string str1, str2;
    for (int i = 0; i < n; i++)
    {
        str1.append("0");
    }

    for (int i = 0; i < m; i++)
        str2.append("0");

    a.append(str1);
    b.append(str2);
    int len = make_length_equal(a, b);
    int flag = 0;
    for (int i = len - 1; i >= 0; i--)
    {

        int first = a.at(i) - '0';
        int second = b.at(i) - '0';
        int sum_bit = first + second + flag;
        if (sum_bit >= 10)
        {
            sum_bit -= 10;
            flag = 1;
        }
        else
            flag = 0;
        sum = to_string(sum_bit) + sum;
    }
    if (flag == 1)
        sum = '1' + sum;
    return sum;
}

string karatsuba_mul(string n1, string n2)
{
    int len = make_length_equal(n1, n2);
    if (len == 1)
    {
        int prod = (n1.at(0) - '0') * (n2.at(0) - '0');
        return to_string(prod);
    }
    int len_h = len / 2;

    string b = n1.substr(len - len_h, len_h);
    string a = n1.substr(0, len - len_h);
    string d = n2.substr(len - len_h, len_h);
    string c = n2.substr(0, len - len_h);

    string ac = karatsuba_mul(a, c);
    string bd = karatsuba_mul(b, d);
    string acbd = add(ac, bd, 0, 0);
    string ab = add(a, b, 0, 0);
    string cd = add(c, d, 0, 0);
    string adcb = minus_fun(karatsuba_mul(ab, cd), acbd);

    string add1 = add(adcb, bd, len_h, 0);
    string result = add(add1, ac, 0, (int)(len / 2) * 2);

    return result;
}
int main()
{
    string a, b;
    cout << "Karatsuba algorithm:" << endl;
    cin >> a;
    cin >> b;

    string prod = karatsuba_mul(a, b);
    cout << prod << endl;
}