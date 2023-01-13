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
    ll n,m;
    cin >> n >> m;
    vector<vll> v(n,vll(m,0));
    vector<pair<ll,ll>> w;
    vector<pair<ll,ll>> p;

    re(i,n){
        re(j,m){
            char c;
            cin >> c;
            if(c == 'P') v[i][j] = 1;
            if(c == 'W') v[i][j] = 2;
            if(v[i][j] == 2){
                w.push_back(pair<ll,ll>{i,j});
            }else if(v[i][j] == 1){
                p.push_back(pair<ll,ll>{i,j});
            }

        }
    }
    ll eaten = 0;
    re(i,n){
        re(j,m){
            ll curr = v[i][j];
            if(curr == 2){
                if(j > 0){
                    if(v[i][j-1] == 1){
                        eaten++;
                        v[i][j-1] = 0;
                        continue;
                    }
                }
                if(i > 0){
                    if(v[i - 1][j] == 1){
                        eaten++;
                        v[i - 1][j] = 0;
                        continue;
                    }
                }
                if(j != m-1){
                    if(v[i][j + 1] == 1){
                        eaten++;
                        v[i][j + 1] = 0;
                        continue;
                    }
                }
                if(i != n-1){
                    if(v[i + 1][j] == 1){
                        eaten++;
                        v[i + 1][j] = 0;
                        continue;
                    }
                }
            }
        }
    }
    cout << eaten;     
    return 0;
}   