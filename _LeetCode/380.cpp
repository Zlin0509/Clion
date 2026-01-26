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

class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> a;

    RandomizedSet() {
        mp.clear();
        a.clear();
    }

    bool insert(int val) {
        if (mp.contains(val)) {
            return false;
        }
        mp[val] = a.size();
        a.emplace_back(val);
        return true;
    }

    bool remove(int val) {
        if (!mp.contains(val)) {
            return false;
        }
        int v = a.back();
        a[mp[val]] = v;
        mp[v] = mp[val];

        mp.erase(val);
        a.pop_back();
        return true;
    }

    int getRandom() {
        int k = rand() % a.size();
        return a[k];
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
