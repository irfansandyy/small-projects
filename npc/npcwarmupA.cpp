#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string n, temp, s;
    getline(std::cin, n);
    getline(std::cin, s);
    vector<string> v;

    stringstream ss(s);

    while(getline(ss, temp, ' ')) {
        v.push_back(temp);
    }

    for(long long unsigned int i = 0; i < v.size(); i++) {
        if(n.find(v[i]) != string::npos) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}