#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<any>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<cassert>

#define fori(it, a, b) for(int it = a; it < b; it++)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'
#define minel(v) *min_element(v.begin(), v.end());
#define maxel(v) *max_element(v.begin(), v.end());
#define sortv(v) sort(v.begin(), v.end());
#define forl(a, k, b) for(long long a = k; a < b; a++)
#define useless ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);

    int n; cin >> n;
    int s, f; cin >> s >> f;
    ll u, v, w;
    vector<vector<pair<ll, int>>>a(n + 1);
    fori(i, 1, n + 1)
    {
        fori(j, 1, n + 1)
        {
            cin >> w;
            if (w >= 0)
                a[i].push_back({ w, j });
        }
    }
    if (s == f)
    {
        cout << 0;
        return 0;
    }
    vector<int>used(n + 1);
    used[s] = 1;
    vector<ll>dist(n + 1, 1e18);
    dist[s] = 0;
    fori(j, 0, a[s].size())
    {
        dist[a[s][j].second] = min(dist[a[s][j].second], dist[s] + a[s][j].first);
    }
    while (true)
    {
        ll minw = 1e18;
        u = -1;
        fori(i, 1, n + 1)
        {
            if (!used[i])
            {
                if (dist[i] < minw)
                {
                    minw = dist[i];
                    u = i;
                }
            }
        }
        if (u != -1)
            used[u] = 1;
        if (u == f || minw == 1e18)
            break;
        fori(j, 0, a[u].size())
        {
            dist[a[u][j].second] = min(dist[a[u][j].second], dist[u] + a[u][j].first);
        }
    }

    if (dist[f] != 1e18)
        cout << dist[f];
    else cout << -1;
}
/*
4 3 1
0 1 1 0
4 0 1 1
2 1 0 -1
1 -1 -1 0

3 2 1
0 1 1
-1 0 1
-1 1 0

*/