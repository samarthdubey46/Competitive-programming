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

float ap_sum(float n)
{
    return (n*(n+1))/2;
}
map<ll, ll> memo;
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
    vector<pii> a(n, pii{numeric_limits<ll>::max(), numeric_limits<ll>::max()});
    map<ll, ll> x;
    map<ll, ll> y;
    map<pii,ll> cnt;
    ll same = 0, res = 0;
    re(i, n)
    {
        cin >> a[i].first >> a[i].second;
        // same += count_a(a, a[i]) - 1;
        x[a[i].first]++;
        y[a[i].second]++;
        cnt[a[i]]++;
    }
    for (auto const &i : x)
    {
        res += ap_sum(i.second - 1);
    }
    for (auto const &i : y)
    {
        res += ap_sum(i.second - 1);
    }
    for (auto const &i : cnt)
    {
        // cout << i.first.first << " " << i.first.second << " - " << i.second << endl;
        same += ap_sum(i.second - 1);
    }
    res -= same;
    cout << res;

    return 0;
}