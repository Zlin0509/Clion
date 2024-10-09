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

const ll mo = 1e9 + 7;

ll qpw(ll u, ll v) {
    ll res = 1;
    while (v) {
        if (v & 1) res = res * u % mo;
        u = u * u % mo;
        v >>= 1;
    }
    return res;
}



inline void Zlin() {
    int r, c, cnt = 0;
    cin >> r >> c;
    vi vis(r << 1 + 2), tag(c << 1 + 1);
    vector<vector<int>> have(r + 1), place(c + 1);
    for (int i = 1; i <= r; i++) {
        char x;
        for (int j = 1; j <= c; j++) {
            cin >> x;
            if (x == '1') {
                place[j].push_back(i);
                have[i].push_back(j);
            }
        }
    }

    cout << qpw(2, cnt) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}