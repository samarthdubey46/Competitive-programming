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


bool isposs_to_make_no_by_multiply(ll old,ll ne){
    if(old != 0 && ne == 0) return false;
    if(ne < old) return false;
    return ((ne % old) == 0);
}
bool checkifAp(vll ap){
    if((ap[1] - ap[0]) == ap[2] - ap[1]) return true;
    return false;
}
bool isAppossiblewithd(ll d,vll ap,pair<ll,ll> currD){
    bool poss = true;
    vll newAp{ap[0],ap[1],ap[2]};
    if(currD.first == 0 && currD.second == 1){
        ll C = ap[1] + d;
        return isposs_to_make_no_by_multiply(ap[2],C);
    }
    if(currD.first == 1 && currD.second == 2){
        ll A = ap[1] - d;
        return isposs_to_make_no_by_multiply(ap[0],A);

    }
    if(currD.first == 2 && currD.second == 0){
        if((d % 2) != 0) return false;
        ll B = ap[0] + (d/2);
        return isposs_to_make_no_by_multiply(ap[1],B);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    re(z,t){
        ll a,b,c;
        cin >> a >> b >> c;
        vll ap{a,b,c};
        vll ds(3);

        bool possible = true;
        ds[0] = b - a;
        ds[1] = c - b;
        ds[2] = c - a;
        if(isAppossiblewithd(ds[0],ap,pair<ll,ll>{0,1})){
            cout << "YES" << endl;
            continue;
        }
        if(isAppossiblewithd(ds[1],ap,pair<ll,ll>{1,2})){
            cout << "YES" << endl;
            continue;
        }
        if(isAppossiblewithd(ds[2],ap,pair<ll,ll>{2,0})){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}