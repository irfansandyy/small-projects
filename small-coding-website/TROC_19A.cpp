#include <iostream>
using namespace std;

int flowerCalc(int p, int q) {
    int bunga = p * p + q * q + 1;
    if (bunga%4 == 0) {
        return bunga;
    }
    else {
        return -1;
    }
}

int main() {
    cout << flowerCalc(12, 73) << endl;
    return 0;
}
