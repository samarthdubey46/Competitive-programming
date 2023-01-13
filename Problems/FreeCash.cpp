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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> guest(n, pair<ll, ll>{-1, -1});
    re(i, n)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        guest[i].first = stringtoint(s1);
        guest[i].second = stringtoint(s2);
    }
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    ll waiter = 1;
    ll streak = 1;
    re(i, n - 1)
    {
        ll j = i + 1;
        if (guest[i].second == guest[j].second)
        {
            streak++;
        }
        else
        {
            waiter = max(waiter, streak);
            streak = 1;
        }
    }
    cout << max(waiter, streak);
    return 0;
}