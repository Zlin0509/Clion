//
// Created by Zlin on 2024/10/10.
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

const int N = 3e3 + 10;

int n;

struct node {
    ll x, y;
    int id;

    bool operator<(const node &b) const {
        if (x != b.x) return x < b.x;
        return y < b.y;
    }
};

struct kkk {
    ll val;
    int id;

    bool operator<(const kkk &b) const {
        return val < b.val;
    }
};

vector<node> a;
vi vis;

ll cross(node a, node b, node c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<node> cal() {
    vector<node> res;
    for (int i = 0; i < n; i++) {
        while (res.size() >= 2 && cross(res[res.size() - 2], res.back(), a[i]) <= 0)
            res.pop_back();
        res.push_back(a[i]);
    }
    int t = res.size() + 1;
    for (int i = n - 1; i >= 0; i--) {
        while (res.size() >= t && cross(res[res.size() - 2], res.back(), a[i]) <= 0)
            res.pop_back();
        res.push_back(a[i]);
    }
    res.pop_back();
    for (auto it: res)
        vis[it.id] = 1;
    return res;
}

inline void Zlin() {
    cin >> n;
    a.assign(n, {0, 0, 0});
    vis.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(a.begin(), a.end());
    cal();
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (vis[a[i].id]) continue;
        vector<kkk> all;
        node b = a[i];
        b.x += 10;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            all.push_back({cross(a[i], b, a[j]), a[j].id});
        }
        sort(all.begin(), all.end());
        int len = all.size();
        if (vis[all[0].id] == vis[all[len - 1].id] == 1) ++ans;
        for (int i = 1; i < len; i++) {
            if (vis[all[i].id] == vis[all[i - 1].id] == 1) ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}