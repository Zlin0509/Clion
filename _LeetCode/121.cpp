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

int maxProfit(vector<int> &prices) {
    int ans = 0;
    for (int i = prices.size() - 2; i >= 0; i--) {
        ans = max(ans, prices[i + 1] - prices[i]);
        prices[i] = max(prices[i], prices[i + 1]);
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
