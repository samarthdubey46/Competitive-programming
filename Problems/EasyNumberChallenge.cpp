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
 

ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}


ll solve(ll n,ll i = 0){
    ll temp = i+1;
    if(n == 1) return i;
    if(n % 2 == 0) return solve(n/2,temp);
    else return solve(n+1,temp);

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;
    cin >> a >> b >> c;
    ll m = a*b*c;
    vll arr(m + 1,0);
    ll ans = 0;
    rep(i,1,m+1){
        for(ll j = i;j <= m;j+=i) arr[j]++;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                ans += arr[(i * j * k)];
            }
        }
    }
    cout << ans % 1073741824;

    return 0;
}   