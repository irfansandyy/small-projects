#include <iostream>
using namespace std;

int main() {
    int lumpia[4], sisa[4], hari;

    // daging, ayam, udang, ikan

    cin >> lumpia[0];
    cin >> lumpia[1];
    cin >> lumpia[2];
    cin >> lumpia[3];

    for (int i = 0; i < 4; i++) {
        sisa[i] = 0;
        if(lumpia[i] % 3 == 0) {
            hari += lumpia[i]/3;
        } else if (lumpia[i] % 3 == 1) {
            hari += lumpia[i]/3 + 1;
            sisa[i] = -2;
        } else {
            hari += lumpia[i]/3 + 1;
            sisa[i] = -1;
        }
    }
    if(sisa[0] != 0 || sisa[1] != 0 || sisa[2] != 0 || sisa[3] != 0) {
        if(sisa[0] < 0 && sisa[1] == 0 && sisa[2] > 0) {
            sisa[2] += sisa[0];
        } else if (sisa[0] < 0 && sisa[1] == 0 && sisa[2] == 0 && sisa[3] > 0) {
            sisa[3] += sisa[0];
        }
        if(sisa[1] < 0 && sisa[2] > 0) {
            sisa[2] += sisa[1];
        } else if(sisa[1] < 0 && sisa[2] == 0 && sisa[3] > 0) {
            sisa[3] += sisa[1];
        }
    }
    std::cout << hari << endl;
}