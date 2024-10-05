//
// Created by Zlin on 2024/10/4.
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
typedef vector<__int128> v128;

ll n, rx, ry, rr, ans;
struct point {
    ll x, y;
};
vector<point> a;
v128 s;

ll dif(int l, int r) {
    return a[l].x * a[r].y - a[l].y * a[r].x;
}

ll cal(int l, int r) {
    return llabs(s[r] - s[l] + dif(r, l));
}

bool check(int l, int r) {
    ll A = a[l].y - a[r].y, B = a[r].x - a[l].x, C = dif(l, r);
    ldb d = (ldb) (A * rx + B * ry + C) / sqrt(A * A + B * B);
    d = abs(d);
    bool c = (d >= rr);
    if (c) {
        if (a[l].x == a[r].x) {
            if (a[l].y > a[r].y && rx <= a[l].x) c = false;
            if (a[l].y < a[r].y && rx >= a[l].x) c = false;
        } else {
            ll res = A * rx + B * ry + C;
            if (res <= 0) c = false;
        }
    }
    return c;
}

inline void Zlin() {
    cin >> n >> rx >> ry >> rr;
    a.assign(n * 2, {0, 0});
    s.assign(n * 2, 0);
    ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y, a[i + n] = a[i];
    for (int i = 1; i < n * 2; i++) s[i] = s[i - 1] + dif(i - 1, i);
    int l = 0, r = l + 2;
    while (l < n) {
        if (check(l, r)) {
            ans = max(ans, cal(l, r));
            ++r;
        } else ++l;
        if (l + 1 == r) ++r;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}