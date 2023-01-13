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


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vll a(n), b(n);
    set<ll> vis;
    map<ll,ll> cnt;
    re(i,n) {
        cin >> a[i] >> b[i];
        cnt[a[i]]++;
    }
    ll opened=0;
    re(i,n) {
        ll curr = b[i];
        if( (vis.find(b[i]) != vis.end()) || (cnt.find(b[i]) == cnt.end()) ) continue;
        if(cnt[b[i]] == -1) {
            opened += 1;
            vis.insert(b[i]);
            continue;
        }
        if(a[i] == b[i]) {
            opened += cnt[b[i]]-1;
            cnt[b[i]]=-1;
            continue;
        }
        vis.insert(b[i]);
        opened += cnt[b[i]];
    }
    cout << n - opened;
    return 0;
}