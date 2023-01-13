#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, points = 0;
    cin >> n;
    ll largest = 0;
    vll dp(pow(10, 6), 0);
    re(i, n)
    {
        ll temp;
        cin >> temp;
        dp[temp] += temp;
        if (temp > largest)
            largest = temp;
    }

    vll dp2(largest + 4, 0);
    dp2[1] = dp[1];
    rep(i,2,largest + 3){
        dp2[i] = max(dp2[i-1],dp[i] + dp2[i-2]);
    }
    cout << dp2[largest+2];
    return 0;
}