#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, s[200005], ans;
vector<int> ve[10][50];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        int now = 0, aa = s[i], sum = 0;
        while (aa)
        {
            now++;
            sum += aa % 10;
            aa /= 10;
        }
        ve[now][sum].emplace_back(s[i]);
    }
    ans = n;
    for (int i = 2; i <= 10; i += 2)
    {
        int now = i / 2;
        for (int j = now; j < i; j++)
        {
            int k = i - j;
            for (int kk = 0; kk <= 45; kk++)
                for (int v : ve[j][kk])
                {
                    int noww = 0, aa = v, summ = 0, sum2 = 0;
                    while (noww < now)
                    {
                        summ += aa % 10, noww++;
                        aa /= 10;
                    }
                    while (aa)
                    {
                        sum2 += aa % 10, aa /= 10;
                    }
                    ans += ve[k][summ - sum2].size();
                    if (j == now)
                        ans--;
                    if (j == now)
                        continue;
                    noww = 0, aa = v, summ = 0, sum2 = 0;
                    while (noww < j - now)
                    {
                        sum2 += aa % 10, noww++;
                        aa /= 10;
                    }
                    while (aa)
                        summ += aa % 10, aa /= 10;
                    ans += ve[k][summ - sum2].size();
                }
        }
    }
    cout << ans;
    return 0;
}