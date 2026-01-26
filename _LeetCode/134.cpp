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

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int i = 0;
    while (i < n) {
        int a = 0, b = 0, cnt = 0;
        while (cnt < n) {
            int j = (i + cnt) % n;
            a += gas[j];
            b += cost[j];
            if (b > a) break;
            cnt++;
        }
        if (cnt == n) {
            return i;
        }
        i = i + cnt + 1;
    }
    return -1;
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
