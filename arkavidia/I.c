#include <stdio.h>
#include <math.h>
#define ll long long

int main() {
    ll N, K;
    scanf("%lld %lld", &N, &K);
    if (abs(N%2) == abs(K%2)) {
        if (K <= N && K >= -N + 2) printf("YES");
        else printf("NO");
    } else {
        printf("NO");
    }
}