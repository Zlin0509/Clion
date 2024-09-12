//
// Created by Zlin on 2024/9/12.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;
int n, q, m;
int a[N];
int vis[N][2030], sum[N][2030];

inline void init() {
    m = sqrt(n);
    for (int i = 1; i <= m; i++) {
        int k = 1, x = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i] <= k) continue;
            vis[j][i] = 1;
            if (++x == i) x = 0, ++k;
        }
    }

    int l = n / m + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= l; j++) if (a[i] > j) ++sum[i][j];
        for (int j = 1; j <= l; j++) sum[i][j] += sum[i - 1][j];
    }
}

inline int ask(int l, int r, int k) { return sum[r][k] - sum[l - 1][k]; }

inline bool check(int i, int k) {
    int x = 1, l, r, mid;
    for (int cnt = 1; cnt <= n / m + 1; cnt++) {
        l = x, r = n;
        while (l < r) {
            mid = l + r >> 1;
            if (ask(x, mid, cnt) >= cnt) r = mid;
            else l = mid + 1;
        }
        if (l < i) x = l + 1;
        else return a[i] > cnt;
    }
    return 0;
}

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init();
    int i, k;
    while (q--) {
        cin >> i >> k;
        if (k <= m) cout << (vis[i][k] ? "YES" : "NO") << '\n';
        else cout << (check(i, k) ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    Zlin();
}