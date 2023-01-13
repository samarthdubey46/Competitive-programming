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
    vll dp(n + 1, 1);
    map<pii, ll> look;
    map<ll, ll> qs;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    ll q = getQ(a[1], a[0], 2);
    look[pii{getA(q,a[1],3),1}] = q;
    cout << q << " " << getA(-1,2,4) << endl;
    for (auto &it : look)
    {
        cout << it.first.first << "-" << it.first.second << "  " << it.second << endl;
    }
    qs[q] += 2;
    rep(i,2,n){
        ll currQ = getQ(a[i],a[i-1],i+1);
        pii currr{a[i],(i+1) % 2};
        if(look.find(currr) != look.end()){
            qs[look[currr]]++;
            ll qq = look[currr];
            look.erase(currr);
            look[pii{getA(qq,a[i],i+2),(i+2) % 2}] = qq;

        }else{
            qs[currQ]++;
            look[pii{getA(currQ,a[i],i+2),(i+2) % 2}] = currQ;
            look[pii{getA(currQ,a[i],i+1),(i + 1) % 2}] = currQ;
        }
    }

    cout << endl;
    for(auto &it : qs){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}