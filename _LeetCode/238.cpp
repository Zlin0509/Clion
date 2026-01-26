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

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> ans(nums.size(), 1);
        int c = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] *= c;
            c *= nums[i];
        }
        c = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= c;
            c *= nums[i];
        }
        return ans;
    }
};

inline void Zlin() {
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
