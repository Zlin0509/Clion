//
// Created by Zlin on 2024/10/3.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    string x;
    cin >> x;
    int c = 1, ans = 0;
    vi all;
    for (int i = 1; i < x.length(); i++) {
        if (x[i] == x[i - 1]) ++c;
        else {
            ans += c / 2;
            if (c % 2 == 0)
                all.push_back(i - c);
            c = 1;
        }
    }
    ans += c / 2;
    if (c % 2 == 0)
        all.push_back(x.length() - c);
    if (all.size()) {
        if (x[0] != x[x.length() - 1]) --ans;
        else {
            int l = 0, r = x.length() - 1, c1 = 0, c2 = 0;
            for (; l < x.length(); l++) {
                if (x[l] == x[0]) ++c1;
                else break;
            }
            for (; r >= l; r--) {
                if (x[r] == x[0]) ++c2;
                else break;
            }
            if (c1 % 2 == 0 && c2 % 2 == 0 && l != x.length()) --ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}