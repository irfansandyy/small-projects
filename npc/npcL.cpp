#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> n, k;
    vector<vector<int>> v;
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int a, b;
        vector<int> c;
        cin >> a >> b;
        n.push_back(a);
        k.push_back(b);
        for(int j = 0; j < a; j++) {
            int d;
            cin >> d;
            c.push_back(d);
        }
        v.push_back(c);
    }

    for(int i = 0; i < t; i++) {
        int next_case = 1;
        vector<int> truth(n[i], 0);
        for(int j = 0; j < n[i]; j++) {
            for(int l = 0; l < n[i]; l++) {
                if(((v[i][j] + v[i][l]) == k[i]) && (j != l)) { 
                    truth[j] = 1;
                    break;
                }
                if(((v[i][j] - v[i][l]) == k[i]) && (j != l)) {
                    truth[j] = 1;
                    break;
                }
            }
            if(truth[j] == 0) {
                cout << "No" << endl;
                next_case = 0;
                break;
            }
        }
        if(next_case == 1) {
            cout << "Yes" << endl;
        }
    }
}