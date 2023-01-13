#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
    ll n, st = 0, temp;
    cin >> n;
    re(i, n)
    {
        cin >> temp;
        if (temp % 2 == 0)
        {
            cout << temp / 2;
        }
        else
        {
            if (st % 2 == 0)
            {
                cout << ((fl)temp / 2.0) - 0.5;
            }
            else
            {
                cout << ((fl)temp / 2.0) + 0.5;
            }
            st++;
        }
        cout << endl;
    }
    return 0;
}