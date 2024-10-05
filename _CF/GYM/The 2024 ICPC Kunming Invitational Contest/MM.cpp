#include<bits/stdc++.h>

using namespace std;
#define int long long
const int n = 1e5 + 5;

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }

    int operator^(const Point &b) const { return x * b.y - b.x * y; }
};

int dis(Point &a, Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// 向量ab x 同直ac
int cross(Point a, Point b, Point c) { return (b - a) ^ (c - a); }

// 判断x, y是否在ab两侧
bool same_side(Point a, Point b, Point x, Point y) {
    int f1 = cross(a, b, x);
    int f2 = cross(a, b, y);
    return (!f1 || !f2 || (f1 > 0 && f2 > 0) || (f1 < 0 && f2 < 0));
}

bool check(Point o, Point a, Point b, int r) {
    __int128 len = dis(a, b);
    __int128 area = abs(cross(o, a, b));
    return area * area <= len * r * r;
}

void solve() {
    int n, r;
    cin >> n >> r;
    Point o;
    cin >> o.x >> o.y >> r;
    vector<Point> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    int s = 0;
    int rr = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        while (check(o, p[i], p[rr % n + 1], rr) && same_side(p[i], p[rr % n + 1], o, p[i % n + 1])) {
            s += abs(cross(p[i], p[rr], p[rr % n + 1]));
            rr = rr % n + 1;
        }
        ans = max(ans, s);
        s -= abs(cross(p[i], p[i], p[i % n + 1]));
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}