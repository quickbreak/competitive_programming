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

    int n, m; cin >> n >> m;
    ll u, v, w = 1;
    vector<vector<pair<ll, int>>>a(n + 1);
    fori(i, 0, m)
    {
        cin >> u >> v;
        a[u].push_back({ w, v });
        a[v].push_back({ w, u });
    }
    int ans = -1;
    vector<vector<ll>>b(n + 1, vector<ll>(n + 1));
    fori(i, 1, n + 1)
    {
        int s = i;
        ll res = 0;

        vector<int>used(n + 1);
        used[s] = 1;
        vector<ll>dist(n + 1, -1);
        dist[s] = 0;
        multiset<pair<ll, pair<int, int>>>st; //вес, откуда, куда
        fori(i, 0, a[s].size())
        {
            st.insert({ dist[s] + a[s][i].first, {s, a[s][i].second} });
        }
        int cnt = n; cnt--;
        while (st.size())
        {
            w = st.begin()->first;
            u = st.begin()->second.first;
            v = st.begin()->second.second;
            st.erase(st.begin());
            if (used[v])
                continue;
            dist[v] = w;
            b[s][v] = w;
            cnt--;
            if (cnt == 0)
                break;
            fori(i, 0, a[v].size())
            {
                if (!used[a[v][i].second])
                    st.insert({ dist[v] + a[v][i].first, {v, a[v][i].second} });
            }
            used[v] = 1;
        }
    }
    ll ans_sum = 0;
    fori(i, 1, n + 1)
    {
        fori(j, 1, n + 1)
        {
            ans_sum += b[i][j];
        }
    }
    cout << ans_sum/2;
}
/*
5 7
1 2 3
2 3 4
1 3 1
2 4 8
3 4 2
1 5 7
5 3 1
*/