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

pair<ll, ll> getConsecutives(vll curr, ll m)
{
    ll start = -1, end = -1;
    ll Maxstart = -1, Maxend = -1;
    ll i = 1;
    ll largest = 0, currentL = 0;
    if (m == 1)
    {
        if(curr[0] == 1)
            return pair<ll, ll>{0, 0};
        else 
            return pair<ll, ll>{-1, -1};

    }
    if (curr[0] == 1)
    {
        start = 0;
        end = 0;
    }
    while (i != m)
    {
        if (curr[i] == 1)
        {
            if (start == -1)
            {
                start = i;
                end = i - 1;
            }
            end++;
            currentL++;
        }
        else
        {
            if (currentL > largest)
            {
                largest = currentL;
                Maxstart = start;
                Maxend = end;
            }
            start = -1;
            end = -1;
            currentL = 0;
        }
        i++;
    }
    if ((start != -1 && Maxstart == -1) || currentL > largest)
    {
        Maxstart = start;
        Maxend = end;
        largest = currentL;
    }
    return pair<ll, ll>{Maxstart, Maxend};
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vll> grid(n, vll(m, 0));
    ll score = 0;
    vector<pair<ll, ll>> scores(n);
    vll onlyScores(n, 0);
    ll largestI = -1;
    re(i, n)
    {
        re(j, m)
        {
            cin >> grid[i][j];
        }
    }
    re(i, n)
    {

        pair<ll, ll> res = getConsecutives(grid[i], m);
        scores[i] = res;
        ll temp = (res.second - res.first) + 1;
        if(res.first == -1) temp = 0;
        onlyScores[i] = temp;
        if (temp > score)
        {
            score = temp;
            largestI = i;
        }
        // printV(grid[i]);
    }
    // cout << score << endl;
    re(z, q)
    {
        ll i, j;
        cin >> i >> j;
        i--;
        j--;
        grid[i][j] = !grid[i][j];
        pair<ll, ll> res = getConsecutives(grid[i], m);
        scores[i] = res;
        ll temp = (res.second - res.first) + 1;
        if(res.first == -1) temp = 0;
        onlyScores[i] = temp;

        score = *max_element(onlyScores.begin(), onlyScores.end());
        cout << score << endl;
    }

    return 0;
}