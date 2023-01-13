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
 
ll ap_sum(float n)
{
    return (n*(n+1))/2;
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,d;
    cin >> n >> d;
    in(a,n);
    ll found = 0;
    re(i,n - 2){
        ll last = lower_bound(a.begin(),a.end(),a[i] + d) - a.begin();
        if(last == n || a[last] != (a[i]+d)) last--;
        found += ap_sum((last - i) - 1);
    }
    cout << found;
    return 0;
}