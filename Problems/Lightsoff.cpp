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
    ll n = 3;
    vector<vll> a(n,vll(n,0));
    vector<vll> res(n,vll(n,1));

    re(i,n){
        re(j,n){
            cin >> a[i][j];
        }
    }
    re(i,n){
        re(j,n){
            ll temp = a[i][j];
            if(temp % 2 != 0){
                res[i][j] = !res[i][j];
                if(i != 0){
                    res[i-1][j] = !res[i-1][j]; 
                }
                if(i != (n-1)){
                    res[i+1][j] = !res[i+1][j]; 
                }

                if(j != 0){
                    res[i][j - 1] = !res[i][j - 1]; 
                }
                if(j != (n-1)){
                    res[i][j +1] = !res[i][j + 1]; 
                }
            }
        }
    }
    re(i,n){
        re(j,n){
            cout << res[i][j] << "";
        }
        cout << endl;
    }


    return 0;
}