#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double fl;
typedef vector<ll> vll;
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

ll stringtoint(string s)
{
    stringstream geek(s);
    ll x = 0;
    geek >> x;
    return x;
}
// ll dif(ll h1, ll m1, ll h2, ll m2)
// {
//     return ((m2 - m1) < 1);
// }

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
    vll dp(n, 0);
    vll a(n, 0);
    set<ll> vis;
    // dp[0] = 1;
    re(i, n)
    {
        cin >> a[i];
    }
    set<ll> vis1;
    vis1.insert(a[n-1]);
    dp[n-1] = 1;
    rep(i, 1, n)
    {
        ll idx = (n - 1) - i;
        if (dp[idx] != i + 1)
        {
            dp[idx] = dp[idx + 1];
            if (vis1.find(a[idx]) == vis1.end())
            {
                dp[idx]++;
            }
        }
        vis1.insert(a[idx]);
    }
    // printV(dp);
    ll c;
    re(i,m){
        cin >> c;
        cout << dp[c-1] << endl;
    }
    return 0;
}
// 0 1 2 3 4 5 6 7 8 9
// 1 2 3 4 1 2 3 4 9 8
// 6 5 4 3 6 5 4 3 2 1