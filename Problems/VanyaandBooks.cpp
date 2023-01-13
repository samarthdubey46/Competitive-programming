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
 
map<pair<ll,ll>, ll> old;
ll ans = 0;
 
int cutRibbion(ll n, set<ll> v, ll i = 0)
{
    if (n == 0)
        return i;
    if (n < 0)
        return -1;
    for (const ll &value : v)
    {
        ll newI = i + 1;
        ll temp;
        pair<ll,ll> tempPair{n - value,value};
        if (old.find(tempPair) != old.end())
            temp = old[tempPair];
        else
        {
            temp = cutRibbion(n - value, v, newI);
            old[tempPair] = temp;
        }
        if (temp > ans)
            ans = temp;
    }
    return ans;
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
    ll res = 0;
    ll i = 1;
    while(n > 0){
        ll value = 9*pow(10,i-1);
        ll temp = min(value,n);
        res += temp * i;
        n -= temp;
        i++;
    }
    cout << res;
    return 0;
}