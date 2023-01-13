#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double fl;
typedef vector<ll> vll;
typedef pair<ll, ll> pii;

#define re(i, n) for (int i = 0; i < n; i++)
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; i++)
#define in(a, n) \
    vll a(n);    \
    re(i, n) cin >> a[i];
#define sort_a(a) sort(a.begin(), a.end())
#define sort_desc(a) sort(a.begin(), a.end(), greater<ll>())
#define find_a(a, e) find(a.begin(), a.end(), e)
#define count_a(a, e) count(a.begin(), a.end(), e)

#define printV(a)         \
    for (int i : a)       \
        cout << i << " "; \
    cout << "\n";

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vll> dancers(n, vll(3, 0));
    map<ll, ll> dc;
    re(i, m)
    {
        cin >> dancers[i][0] >> dancers[i][1] >> dancers[i][2];
        vll a = dancers[i];
        if (i == 0)
        {
            dc[a[0]] = 0;
            dc[a[1]] = 1;
            dc[a[2]] = 2;
        }
        else
        {
            vll temp{-1, -1, -1};
            ll filled = 0;
            for (auto &value : a)
            {
                if (dc.find(value) != dc.end())
                {
                    temp[dc[value]] = value;
                    filled++;
                }
            }
            if (filled == 3)
                continue;
            re(j, 3)
            {
                if (dc.find(a[j]) != dc.end())
                {
                    continue;
                    temp[j] = a[j];
                }
                if (temp[j] == -1)
                {
                    dc[a[j]] = j;
                    temp[j] = a[j];
                }
                else
                {
                    if (temp[0] == -1)
                    {
                        dc[a[j]] = 0;
                        temp[0] = a[j];
                    }
                    else if (temp[1] == -1)
                    {
                        dc[a[j]] = 1;
                        temp[1] = a[j];
                    }
                    else if (temp[2] == -1)
                    {
                        temp[2] = a[j];
                        dc[a[j]] = 2;
                    }
                }
            }
            // printV(temp);
        }
    }
    for (auto &it : dc)
    {
        cout << it.second + 1 << " ";
    }

    return 0;
}