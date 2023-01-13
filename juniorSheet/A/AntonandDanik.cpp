#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
typedef long double fl;
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
    ll n,anton=0,danik=0;
    char temp;
    cin >> n;
    re(i,n){
        cin >> temp;
        if(temp == 'A') anton++;
        else danik++;
    }
    if(anton > danik) cout << "Anton";
    else if(anton < danik) cout << "Danik";
    else cout << "Friendship";
    return 0;
}   