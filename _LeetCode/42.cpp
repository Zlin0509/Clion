//
// Created by 27682 on 2026/1/26.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int trap(vector<int> &height) {
    int ans = 0;
    int l = 0, r = height.size() - 1;
    int lmx = 0, rmx = 0;
    while (l < r) {
        lmx = max(lmx, height[l]);
        rmx = max(rmx, height[r]);
        if (height[l] < height[r]) {
            ans += lmx - height[l];
            ++l;
        } else {
            ans += rmx - height[r];
            --r;
        }
    }
    return ans;
}

inline void Zlin() {
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
