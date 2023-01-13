#include <bits/stdc++.h>
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

bool verify(vector<vll> arr, ll i, ll j, ll n, ll check)
{
    // Left Up
    if (i != 0 && j != 0)
    {
        if (arr[i][j - 1] == check && arr[i - 1][j] == check && arr[i - 1][j - 1] == check)
        {
            return true;
        }
    }
    // Right Up
    if (i != 0 && j != n - 1)
    {
        if (arr[i][j + 1] == check && arr[i - 1][j] == check && arr[i - 1][j + 1] == check)
            return true;
    }
    // Left Down
    if (i != n - 1 && j != 0)
    {
        if (arr[i][j - 1] == check && arr[i + 1][j] == check && arr[i + 1][j - 1] == check)
            return true;
    }
    // Right Down
    if (i != n - 1 && j != n - 1)
    {
        if (arr[i][j + 1] == check && arr[i + 1][j] == check && arr[i + 1][j + 1] == check)
            return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n = 4;
    char temp;
    vector<vll> arr(n, vll(n, 0));
    re(i, n)
    {
        re(j, n)
        {
            cin >> temp;
            if (temp == '#')
                arr[i][j] = 1;
        }
    }
    bool status = false;

    re(i, n)
    {
        re(j, n)
        {
            if (verify(arr, i, j, n, 1) || verify(arr, i, j, n, 0))
            {
                status = true;
            }
        }
    }
    if (status)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}