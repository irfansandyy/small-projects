#include <iostream>
#define MAX 500000
#include <cmath>
using namespace std;

int multiply(int x, int res[], int res_size);

void factorial(int n, int k)
{
    int res[MAX];

    res[0] = 1;
    int res_size = 1;

    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    int tr = n/5 + n/25 + n/125 + n/625 + n/3125 + n/15625 + n/78125 + n/390625;

    if(res_size < k) {
        for (int i = res_size - 1; i >= tr; i--) {
            cout << res[i];
        }
        cout << endl;
    } else {
        for (int i = tr + k; i >= tr; i--) {
            cout << res[i];
        }
        cout << endl;
    }
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;

    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;


        res[i] = prod % 10;

        carry = prod / 10;
    }

    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        factorial(n, k - 1);
    }
}