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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ll rook = 2, bishop = 0, king = 0;
    if (abs(r1 - c1) % 2 == abs(r2 - c2) % 2)
    {
        bishop = 1;
        if (abs(r1 - r2) != abs(c1 - c2))
            bishop = 2;
    }
    if (r1 == r2 || c1 == c2)
        rook--;
    while (r1 != r2 || c1 != c2)
    {
        if (r1 < r2)
            r1++;
        if (r1 > r2)
            r1--;

        if (c1 < c2)
            c1++;
        if (c1 > c2)
            c1--;
        king++;
    }

    cout << rook << " " << bishop << " " << king;

    return 0;
}