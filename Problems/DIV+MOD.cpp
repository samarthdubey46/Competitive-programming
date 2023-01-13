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

ll fax(ll a, ll x)
{
    return floor(x / a) + (x % a);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    re(z, t)
    {
        ll l, r, a;
        cin >> l >> r >> a;
        if (a == 1)
        {
            cout << r;
            continue;
        }
        int m = r / a * a - 1;
        if (m >= l)
            cout << max(fax(a, m), fax(a, r)) << endl;
        else
            cout <<  fax(a, r)   << endl;
    }

    return 0;
}