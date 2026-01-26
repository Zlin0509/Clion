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

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> ans;
    int l = 0, r = 0;
    while (l < m && r < n) {
        if (nums1[l] < nums2[r]) {
            ans.emplace_back(nums1[l++]);
        } else {
            ans.emplace_back(nums2[r++]);
        }
    }
    while (l < m) { ans.emplace_back(nums1[l++]); }
    while (r < n) { ans.emplace_back(nums2[r++]); }
    nums1 = ans;
}

signed main() {
    vector<int> a{2, 3, 4}, b{1, 55, 100};
    merge(a, 3, b, 2);
    for (auto &it: a) cout << it << ' ';
}
