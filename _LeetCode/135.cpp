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

int candy(vector<int> &ratings) {
    int n = ratings.size(), len = 1, val = 1, ans = 1, pre = 0;
    for (int i = 1; i < n; i++) {
        if (ratings[i] >= ratings[i - 1]) {
            len = 0;
            val = ratings[i] == ratings[i - 1] ? 1 : val + 1;
            ans += val;
            pre = val;
        } else {
            ++len;
            if (len == pre) {
                ++len;
            }
            ans += len;
            val = 1;
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
