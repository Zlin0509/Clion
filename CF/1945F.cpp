//
// Created by Zlin on 2024/9/6.
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
ll n, ans, sum;
ll a[N], b[N], c[N];
priority_queue<int, vi, greater<int>> p;

inline void Zlin() {
    while (!p.empty()) p.pop();
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) c[i] = a[b[i]];
    for (int i = n; i >= 1; i--) {
        p.push(c[i]);
        while (p.size() > i)
            p.pop();
        if (ans <= (ll) p.size() * p.top()) {
            ans = (ll) p.size() * p.top();
            sum = p.size();
        }
    }
    cout << ans << ' ' << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}