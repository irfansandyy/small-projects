#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long unsigned lumine = 0;
    vector<long long unsigned> v;
    for(int i = 0; i < n; i++) {
        long long unsigned temp;
        cin >> temp;
        v.push_back(temp);
        lumine += (temp/n);
    }

    sort(v.begin(), v.end());
    long long unsigned aether = 0;
    if((v.size() % 2) == 0u) {
        aether = (v[((int) v.size()/2) - 1] + v[((int) v.size()/2) - 1])/2;
    } else {
        aether = v[(int) v.size()/2];
    }
    if(aether == lumine) {
        cout << "Yeay Aku dapat Hu Tao";
    } else if(lumine > aether) {
        cout << "Aduh, Aku dapat B5 limited lain di pity " << lumine - aether << " :(";
    } else {
        cout << "Yahh kok Qiqi, Mana Pity " << aether - lumine << " lagi :(";
    }
}