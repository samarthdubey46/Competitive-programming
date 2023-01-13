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

ll getQ(ll a, ll b, ll i)
{
    ll diff = 1;
    if (i % 2 == 0)
        diff = -1;
    return ((a - b) * diff);
}
ll getA(ll q, ll b, ll i)
{
    ll diff = q;
    if (i % 2 == 0)
        diff = (q * -1);
    ll res = b + diff;
    return res;
}

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
    in(a, n);
    ll highest = 1;
    if (n == 2)
    {
        cout << 2;
        return 0;
    }
    rep(i, 1, n)
    {
        ll index = i + 1;
        ll q = getQ(a[i], a[i - 1], index);
        ll count = 2;
        ll last = a[i];
        rep(j, i + 1, n)
        {
            ll q_ = getQ(a[j], last, index + 1);
            if (q_ == q)
            {
                index++;
                count++;
                last = a[j];
            }
        }
        if (count > highest)
            highest = count;
    }
    cout << highest;

    return 0;
}