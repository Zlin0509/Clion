#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef __int128 int128;
typedef long double ldb;

inline int128 abs128(int128 x) {
    return x < 0 ? -x : x;
}

inline ll read_ll() {
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x * 10) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

void print_int128(int128 x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    char buf[40];
    int idx = 0;
    while (x > 0) {
        buf[idx++] = (x % 10) + '0';
        x /= 10;
    }
    while (idx--) putchar(buf[idx]);
}

int128 n, rx, ry, rr, ans;
struct point {
    int128 x, y;
};
vector<point> a;
vector<int128> s;

int128 dif(int l, int r) {
    return a[l].x * a[r].y - a[l].y * a[r].x;
}

int128 cal(int l, int r) {
    return abs128(s[r] - s[l] + dif(r, l));
}

bool check(int l, int r) {
    int128 A = a[l].y - a[r].y;
    int128 B = a[r].x - a[l].x;
    int128 C = dif(l, r);
    ldb d = (ldb)(A * rx + B * ry + C) / sqrt((ldb)(A * A + B * B));
    d = abs(d);

    bool c = (d >= rr);
    if (c) {
        if (a[l].x == a[r].x) {
            if (a[l].y > a[r].y && rx <= a[l].x) c = false;
            if (a[l].y < a[r].y && rx >= a[l].x) c = false;
        } else {
            int128 res = A * rx + B * ry + C;
            if (res <= 0) c = false;
        }
    }
    return c;
}

inline void Zlin() {
    n = read_ll();
    rx = read_ll();
    ry = read_ll();
    rr = read_ll();
    a.assign(n * 2, {0, 0});
    s.assign(n * 2, 0);
    ans = 0;

    for (int i = 0; i < n; i++) {
        int128 x = read_ll(), y = read_ll();
        a[i].x = x;
        a[i].y = y;
        a[i + n] = a[i];
    }

    for (int i = 1; i < n * 2; i++) {
        s[i] = s[i - 1] + dif(i - 1, i);
    }

    int l = 0, r = l + 2;
    while (l < n) {
        if (check(l, r)) {
            ans = max(ans, cal(l, r));
            ++r;
        } else {
            ++l;
        }
        if (l + 1 == r) ++r;
    }
    print_int128(ans);
    putchar('\n');
}

int main() {
    int ttt = read_ll();
    while (ttt--) Zlin();
}