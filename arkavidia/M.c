#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define MAX 300000

typedef struct {
    ll a, b, r;
} Pair;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int N;
    ll *arr = (ll *)malloc(sizeof(ll) * MAX);
    Pair *pair = (Pair *)malloc(sizeof(Pair) * MAX);
    ll sum = 1;
    ll pair_count = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            int found = 0;
            for(int k = 0; k < pair_count; k++) {
                if(pair[k].a == arr[i] && pair[k].b == arr[j] || pair[k].a == arr[j] && pair[k].b == arr[i]) {
                    sum = (sum * pair[k].r) % 998244353;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                pair[pair_count].a = arr[i];
                pair[pair_count].b = arr[j];
                pair[pair_count].r = gcd(arr[i], arr[j]);
                sum = (sum * pair[pair_count].r) % 998244353;
                pair_count++;
            }
        }
    }
    printf("%lld\n", sum);
}