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


bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    in(a,n);
    vector<pair<ll,ll>> mx(n);
    for(ll i = 0;i < n;i += 1){
        ll end = i + k;
        if(end > n) break;
        mx[i] = pair<ll,ll>{i,accumulate(a.begin()+i,a.begin()+end,0)};
    }
    // 2 3
    sort(mx.begin(),mx.end(),cmp);
    // re(i,n){
    //     cout << mx[i].first << " " << mx[i].second << endl;
    // }
    ll a_ = mx[0].first;
    ll b = -1;
    re(i,n){
        ll temp = mx[i].first;
        if(abs(temp - a_) >= k){
            b = temp;
            break;
        }
        // if(a_ >= b && b +(k-1) >= b) b = -1;
    } 
    cout << min(a_,b) + 1 << " " << max(a_,b) + 1; 


    return 0;
}   