#include <bits/stdc++.h>
#include <stack>
using namespace std;
typedef int ll;
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
    ll n,t = -1;
    string d;
    cin >> n >> d;
    in(a,n);
    stack<ll> right;
    stack<ll> left;
    re(i,n){
        if(d[i] == 'L') left.push(a[i]);
        if(d[i] == 'R') right.push(a[i]);
        if(d[i] == 'L' && right.size() > 0){
            ll l = left.top(),r = right.top();
            left.pop();
            right.pop();
            if(t == -1) t = (l-r)/2;
            else t = min((l-r)/2,t);
        }
    }
    cout << t;

    return 0;
}