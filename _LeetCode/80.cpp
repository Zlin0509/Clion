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

int removeDuplicates(vector<int> &nums) {
    int ans = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (ans > 1 && nums[i] == nums[ans - 1] && nums[i - 1] == nums[ans - 2]) continue;
        nums[ans++] = nums[i];
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
