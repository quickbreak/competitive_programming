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
    ////freopen("INPUT.TXT", "r", stdin);
    ////freopen("OUTPUT.TXT", "w", stdout);


    int n; cin >> n;
    int u, v, t;
    ll w;
    vector<pair<ld, ld>>speed(n + 1);
    int vv;
    fori(i, 1, n + 1)
    {
        cin >> t >> vv;
        speed[i] = { t,vv };
    }
    speed[1].first = 0;
    vector<vector<pair<ld, int>>>a(n + 1); //расстояние, куда
    fori(i, 0, n - 1)
    {
        cin >> u >> v >> w;
        a[u].push_back({ w, v });
        a[v].push_back({ w, u });
    }


    vector<int>used(n + 1);
    queue<pair<ld, int>>q;
    q.push({ 0, 1 });
    vector<ld>straight(n + 1);


    set<pair<ld, pair<int, int>>>st;
    while (q.size())
    {
        pair<ld, int>p = q.front();
        w = p.first;
        v = p.second;
        q.pop();
        if (used[v])
            continue;
        used[v] = 1;
        straight[v] = w / speed[v].second + speed[v].first;
        if (v != 1)
        {
            st.insert({ straight[v], {v,1} });
        }
        fori(i, 0, a[v].size())
        {
            q.push({ w + a[v][i].first, a[v][i].second });
        }
    }
    //found lucky one
    vector<ld>dist(n + 1);
    int cnt = n - 1;
    vector<int>way(n + 1);
    way[1] = -1;
    while (cnt)
    {
        int lucky = st.begin()->second.first;
        if (way[lucky] == 0)
        {
            cnt--;
            dist[lucky] = st.begin()->first;
            way[lucky] = st.begin()->second.second;
        }
        else
        {
            st.erase(st.begin());
            continue;
        }
        st.erase(st.begin());

        fori(j, 0, n + 1)
            straight[j] = 0;

        while (q.size())
            q.pop();

        q.push({ 0, lucky }); //{0,lucky?}
        fori(j, 0, n + 1)
            used[j] = 0;
        //used[i] = 1;
        while (q.size()) //собираем все прямые пути в вершину lucky
        {
            pair<ld, int>p = q.front();
            w = p.first;
            v = p.second;
            q.pop();
            if (used[v])
                continue;
            used[v] = 1;
            straight[v] = w / speed[v].second + speed[v].first;
            if (v != lucky && way[v] == 0)
            {
                st.insert({ straight[v] + dist[lucky], {v, lucky} });
            }
            fori(i, 0, a[v].size())
            {
                if (!used[a[v][i].second])
                    q.push({ w + a[v][i].first, a[v][i].second });
            }
        }
    }
    
    ld ans = -1;
    int uk = -1;
    fori(i, 1, n + 1)
    {
        if (dist[i] > ans)
        {
            ans = dist[i];
            uk = i;
        }
    }
    //printf("%.10lf", ans);
    cout.precision(10);
    cout << ans;
    cn;
    cout << uk << ' ';
    while (way[uk] != -1)
    {
        cout << way[uk] << ' ';
        uk = way[uk];
    }

    //наверное, это реально дейкстра
    //после первого запуска bfs все расстояния закинем в сет
    //на каждом шаге: 
    //1) достаём кратчайшего
    //2) запускаем такой же необычный bfs от него, все расстояния закидываем в сет
    //пока сет не пуст или cnt
}