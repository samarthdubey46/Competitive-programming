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
    map<string, string> oldNew;
    map<string, string> newOld;
    string old, ne;
    ll total = 0;
    re(i, n)
    {
        cin >> old >> ne;
        if (oldNew.find(old) == oldNew.end() && newOld.find(old) == newOld.end())
        {
            total++;
            newOld[ne] = old;
            oldNew[old] = ne;
        }else{
            oldNew[newOld[old]] = ne;
            newOld[ne] = newOld[old];
            newOld.erase(old);
        }
    }
    cout << total << endl;
    for(auto &it : oldNew){
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}