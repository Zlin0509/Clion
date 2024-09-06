//
// Created by Zlin on 2024/9/5.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll Base = 233, Mod = 3143271;
const int N = 2e5 + 5;

ll hd[N], Hash[N];
char a[N];
int n, l, r, cnt, ans;
vi place;

inline void init() {
    place.clear();
    ans = 0;
}

inline void Zlin() {
    cin >> n >> cnt >> r;

    init();

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Hash[i] = (Hash[i - 1] * Base + a[i]) % Mod;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    hd[0] = 1;
    for (int i = 1; i < N; i++) hd[i] = hd[i - 1] * Base % Mod;

    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}