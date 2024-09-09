#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

map<char, int> t;
int n, cnt[26]{};
char s[100010]{};

struct ss
{
    int id, cnt;
} z[26]{};

bool cmp(const ss &a, const ss &b)
{
    return a.cnt > b.cnt;
}

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        ++cnt[s[i] - 'a'];
    }
    for (int i = 0; i < 26; i++)
        z[i] = {i, cnt[i]};
    sort(z, z + 26, cmp);
    int k, M = INT_MAX;
    for (int i = 1; i <= 26; i++)
    {
        if (n % i == 0)
        {
            int check = n / i;
            int ans = 0;
            for (int j = 0; j < i; j++)
            {
                ans += abs(z[j].cnt - check);
            }
            for (int j = i; j < 26; j++)
            {
                ans += z[j].cnt;
            }
            ans /= 2;
            if (ans < M)
            {
                M = ans;
                k = i;
            }
        }
    }
    cout << M << '\n';

    // for (int i = 0; i < k; i++)
    // {
    //     cout << z[i].id << endl;
    // }

    for (int i = 0; i < k; i++)
        cnt[z[i].id] = n / k;
    for (int i = k; i < 26; i++)
        cnt[z[i].id] = 0;
    char hh;
    for (int i = 1; i <= n; i++)
    {
        int ch = s[i] - 'a';
        if (cnt[ch] == 0)
        {
            for (int j = 0; j < k; j++)
            {
                if (z[j].cnt < n / k)
                {
                    ++z[j].cnt;
                    hh = z[j].id + 'a';
                    cout << hh;
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                if (z[j].id == ch)
                {
                    if (z[j].cnt <= n / k)
                    {
                        // cout << "3" << endl;
                        hh = ch + 'a';
                        // cout << z[j].cnt << endl;
                        cout << hh;
                    }
                    else
                    {
                        --z[j].cnt;
                        for (int q = 0; q < k; q++)
                        {
                            if (z[q].cnt < n / k)
                            {
                                // cout << z[q].cnt << endl;
                                // cout << "2" << endl;
                                ++z[q].cnt;
                                hh = z[q].id + 'a';
                                cout << hh;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}