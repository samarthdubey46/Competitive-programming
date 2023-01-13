#include <bits/stdc++.h>
#include <stack>
using namespace std;
typedef long ll;
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
    string s,ad;
    string l="",r="";
    cin >> s >> ad;
    ll n = s.size();
    ll n_ = ad.size();
    bool right = false;
    bool RightLarger = true;
    re(i,n){
        if(s[i] == '|') right = true;
        else{
            if(right) r += s[i];
            else l += s[i];
        }
    }
    ll needed = r.size() - l.size();
    if(needed < 0) RightLarger = false;
    needed = abs(needed);
    if(n_ < needed) cout << "Impossible";
    else{
        if(RightLarger) l += ad.substr(0,needed);
        else r += ad.substr(0,needed);
        n_ -= needed;
        if(n_%2 != 0) cout << "Impossible";
        else{
            rep(i,needed,needed+(n_/2)){
                l += ad[i];
            }
            rep(i,needed+(n_/2),ad.size()){
                r += ad[i];
            }
            cout << l <<"|" <<r;
        }
    }
    return 0;
}