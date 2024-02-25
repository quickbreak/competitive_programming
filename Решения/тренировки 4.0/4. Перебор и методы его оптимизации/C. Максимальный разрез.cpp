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
    int u, v, w;
    vector<pair<int, pair<int, int>>>a;
    vector<int>cost;
    fori(i, 0, n)
    {
        fori(j, 0, n)
        {
            cin >> w;
            if (j > i && w > 0)
            {
                a.push_back({ w, {i, j} });
                cost.push_back(w);
            }
        }
    }
    sort(cost.begin(), cost.end(), greater<>());
    vector<int>pref;
    pref.push_back(0);
    fori(i, 0, cost.size())
    {
        pref.push_back(cost[i] + pref[i]);
    }

    int b = (1 << n);
    int m = a.size();
    int p;
    str mask;
    ll ans = 0, res = 0;
    str anss = "";
    for (int i = 0; i < b / 2 + 2; i++)
    {
        p = i;
        mask = "";
        while (p > 0)
        {
            mask = to_string(p % 2) + mask;
            p /= 2;
        }
        while (mask.size() < n)
            mask = '0' + mask;
        
        res = 0;
        for (int i = 0; i < m; i++)
        {
            u = a[i].second.first;
            v = a[i].second.second;
            if (mask[u] != mask[v])
            {
                res += a[i].first;
            }
            if (res + pref[m - i - 1] < ans)
                break;
        }
        if (res > ans)
        {
            anss = mask;
            ans = res;
        }
    }
    cout << ans; cn;
    fori(i, 0, n)
    {
        if (anss.size()<=i || anss[i] == '0')
            cout << 2 << ' ';
        else cout << 1 << ' ';
    }
}