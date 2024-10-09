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
    vi vis(c + 1), tag(c + 1);
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
    for (int i = 1; i <= r; i++) {
        if (vis[i]) continue;
        queue<int> now;
        now.push(i);
        while (!now.empty()) {
            int u = now.front();
            now.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto j: have[u]) {
                ++tag[j], ++tag[c - j + 1];
                for (auto q: place[j]) now.push(q);
                for (auto q: place[c - j + 1]) now.push(q);
            }
        }
        ++cnt;
    }
    for (int i = 1; i <= c; i++) {
        if (tag[i] > 2) {
            cout << 0 << '\n';
            return;
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