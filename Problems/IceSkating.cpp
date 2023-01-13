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
    ll n;
    cin >> n;
    map<ll, ll> AccessX;
    map<ll, ll> AccessY;
    ll needed = 0;
    vector<pii> drifts(n, pii{-1, -1});
    re(i, n)
    {
        cin >> drifts[i].first >> drifts[i].second;
        pii curr = drifts[i];
        if (i > 0)
        {
            if (AccessX.find(curr.first) == AccessX.end() && AccessY.find(curr.second) == AccessY.end()) needed++;
        }
        AccessX[curr.first] = 1;
        AccessY[curr.second] = 1;
    }
    cout << needed;

    return 0;
}