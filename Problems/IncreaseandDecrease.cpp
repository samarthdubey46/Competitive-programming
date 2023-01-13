#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double fl;
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
    ll n;
    cin >> n;
    in(a, n);
    sort_a(a);
    if (n == 1)
    {
        cout << 1;
        return 0;
    };
    if(n == 2){
        if((a[1] - a[0]) % 2 == 0) cout << n;
        else cout << n-1;
        return 0;
    }
    ll elm = a[n - 2];
    re(i, n - 2)
    {
        ll diff = (elm - a[i]);
        a[i] += diff;
        a[n - 1] -= diff;
    }
    ll s = ((n - 1) * elm) + a[n-1];
    if (s % n == 0)
        cout << n;
    else
        cout << n - 1;
    return 0;
}