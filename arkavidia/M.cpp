#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    
    long long N;
    cin >> N;
    
    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<long long, int> freq;
    for(int i = 0; i < N; i++) {
        freq[A[i]]++;
    }
    
    vector<pair<long long, int>> compressed;
    for(auto &p : freq) {
        compressed.push_back(p);
    }
    unordered_map<long long, unordered_map<long long, long long>> memo;

    long long X = 1;
    int size = compressed.size();
    
    for(int i = 0; i < size; i++) {
        long long val = compressed[i].first;
        int count = compressed[i].second;
        if (count > 1) {
            for(int p = 0; p < count*(count-1)/2; p++) {
                X = (X * val) % MOD;
            }
        }
        
        for(int j = i + 1; j < size; j++) {
            long long val2 = compressed[j].first;
            int count2 = compressed[j].second;
            
            long long g;
            if (memo[val].count(val2)) {
                g = memo[val][val2];
            } else if (memo[val2].count(val)) {
                g = memo[val2][val];
            } else {
                g = gcd(val, val2);
                memo[val][val2] = g;
            }
            for(int p = 0; p < count*count2; p++) {
                X = (X * g) % MOD;
            }
        }
    }
    
    cout << X << endl;
    
    return 0;
}