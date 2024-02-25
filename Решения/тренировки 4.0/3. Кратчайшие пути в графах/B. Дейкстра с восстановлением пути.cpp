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
        cout << s << ' ' << f;
        return 0;
    }
    vector<int>used(n + 1);
    used[s] = 1;
    vector<ll>dist(n + 1, -1);
    dist[s] = 0;
    multiset<pair<ll, pair<int, int>>>st; //вес, откуда, куда
    fori(i, 0, a[s].size())
    {
        st.insert({ dist[s] + a[s][i].first, {s, a[s][i].second} });
    }
    vector<int>way(n + 1);
    way[s] = -1;
    while (st.size())
    {
        w = st.begin()->first;
        u = st.begin()->second.first;
        v = st.begin()->second.second;
        st.erase(st.begin());
        if (used[v])
            continue;
        dist[v] = w;
        way[v] = u;
        if (v == f)
            break;
        fori(i, 0, a[v].size())
        {
            if (!used[a[v][i].second])
                st.insert({ dist[v] + a[v][i].first, {v, a[v][i].second} });
        }
        used[v] = 1;
    }
    if (dist[f] == -1)
    {
        cout << -1;
        return 0;
    }
    int uk = f;
    stack<int>sta;
    sta.push(f);
    while (way[uk] != -1)
    {
        sta.push(way[uk]);
        uk = way[uk];
    }
    while (sta.size())
    {
        cout << sta.top() << ' ';
        sta.pop();
    }
}
/*
4 4 3
0 -1 1 -1
4 0 1 1
1 -1 0 -1
2 1 0 0

*/