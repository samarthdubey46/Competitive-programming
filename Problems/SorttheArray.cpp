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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    in(a, n);
    pair<ll, ll> mat{-1, -1};
    bool finding = false;
    bool foundonce = false;
    bool no = false;
    re(i, n - 1)
    {
        ll j = i + 1;
        if (a[i] >= a[j])
        {
            if (foundonce && !finding)
            {
                no = true;
                break;
            }
            if (finding)
                continue;
            mat.first = i;
            finding = true;
            foundonce = true;
        }
        else
        {
            if (finding)
            {
                finding = false;
                mat.second = i;
            }
        }
    }
    if (!foundonce)
    {
        cout << "yes" << endl
             << "1 1";
    }
    else
    {
        if (!no)
        {
            if (mat.second == -1)
            {
                mat.second = n - 1;
            }
            // if (mat.first == 0 && mat.second == n - 1)
            // {
            //     cout << "yes" << endl
            //          << mat.first + 1 << " " << mat.second + 1;
            // }
            if (mat.second != n - 1)
                if (a[mat.first] > a[mat.second + 1])
                    no = true;
            if (mat.first > 0)
                if (a[mat.first - 1] > a[mat.second])
                    no = true;
            if (no)
                cout << "no";
            else
                cout << "yes" << endl
                     << mat.first + 1 << " " << mat.second + 1;
        }else{
            cout << "no"; 
        }
    }
    return 0;
}