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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, d, sum = -1;
    cin >> n >> m >> d;
    in(a, n * m);
    bool error = false;
    re(i, n * m)
    {
        ll t = 0;

        re(j, n * m)
        {
            ll temp = abs(a[i] - a[j]);
            if (temp % d == 0)
            {
                t += abs(a[i] - a[j]) / d;
            }
            else
            {
                error = true;
                break;
            }
        }
        if (error)
        {
            break;
        }
        if (i == 0)
        {
            sum = t;
        }
        else
        {
            sum = min(sum, t);
        }
    }
    cout << (error ? -1 : sum);
    return 0;
}