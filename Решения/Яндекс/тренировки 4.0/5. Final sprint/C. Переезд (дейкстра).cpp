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

    int n, k; cin >> n >> k;
    int s = 1, f = n;
    ll u, v, t, w;
    vector<vector<pair<ll, pair<ll, int>>>>a(n + 1);
    fori(i, 0, k)
    {
        cin >> u >> v >> t >> w;
        a[u].push_back({ t, {w, v} });
        a[v].push_back({ t, {w, u} });
    }
    if (s == f)
    {
        cout << 10000000;
        return 0;
    }

    int l = 0;
    int r = 1e7 + 1;
    while (r - l > 1) // сколько максимум кружек перевезёт? 
    {
        ll m = (r + l) / 2;
        ll sw = 3000000 + 100 * m; //масса грузовика + по 100г за каждую кружку
        ll st = 0;

        // дальше дейкстра за квадрат, похоже
        // это от стартовой куда можем попасть
        vector<int>used(n + 1);
        used[s] = 1;
        vector<ll>dist(n + 1, 1e18); // на самом деле время, но так проще было
        dist[s] = 0;
        fori(j, 0, a[s].size())
        {
            if (sw <= a[s][j].second.first)
                dist[a[s][j].second.second] = min(dist[a[s][j].second.second], dist[s] + a[s][j].first);
        }
        // затем из ближайшего куда можем попасть, потом от второго по дальности,.. и т.д. ну, дейкстра
        bool flag = false;
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
            {
                used[u] = 1;
                st = dist[u];
            }
            if (u == f) //чтобы понимать, что до конечной вершины мы смогли доехать
                flag = true;
            if (u == f || minw == 1e18)
            {
                break;
            }
            fori(j, 0, a[u].size())
            {
                if (sw <= a[u][j].second.first)
                    dist[a[u][j].second.second] = min(dist[a[u][j].second.second], dist[u] + a[u][j].first);
            }
        }

        if (flag && st > 0 && st <= 1440)
            l = m;
        else r = m;
    }
    if (s == f) 
    {
        cout << 1e7; // 1е7 всего кружек
    }
    cout << l;
}
/*
3 3
2 3 40 3000299
1 3 4 3000056
1 2 10 3000201

2


3 3
1 3 1440 3000100
1 2 1440 3000200
2 3 1 3000200

1


3 1
1 2 1 3000100

0
*/