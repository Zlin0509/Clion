//
// Created by Zlin on 2024/10/8.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 10;

int n;
ll k, a[N];

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    multiset<int> p;
    int l = 0, r = 0, ans = 0;
    ll sum = 0, tag = 0;

    while (l < n - ans) {
        while (r < l + ans) {
            sum += a[r++];

        }

    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}