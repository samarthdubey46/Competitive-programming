#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
    std::cout << std::setprecision(20);
    ll n, l = 0, r = 0,firstR = -1,lastR = -1,firstL = -1,lastL = -1;
    char step;
    cin >> n;
    vll a(n, 0);
    re(i, n)
    {
        cin >> step;
        if (step == 'L')
        {
            a[i] = -1;
            l++;
            if(firstL == -1) firstL = i;
            
        }
        if (step == 'R')
        {
            if(firstR == -1) firstR = i;
            a[i] = 1;
            r++;
        }
    }
    if(l > 0 && r > 0){
        re(i,n){
            if(a[i] == -1) {
                lastR = i-1;
                break;
            }
        }
        cout << firstR+1 << " " << lastR+1;
    }
    if(l == 0){
        rep(i,firstR,n){
            if(a[i] == 0){
                lastR = i-1;
                break;
            }
        }
        cout << firstR+1 << " " << lastR+2;
    }
    if(r == 0){
        rep(i,firstL,n){
            if(a[i] == 0){
                lastL = i-1;
                break;
            }
        }
        if(lastL != -1) cout << lastL+1 << " " << firstL;
        else cout << n << firstL + 1;
    }
    // printV(a);
    return 0;
}