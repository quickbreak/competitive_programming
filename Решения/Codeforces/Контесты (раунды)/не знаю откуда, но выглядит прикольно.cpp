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
    int x;
    vector<pair<ll, int>>a;
    fori(i, 0, n)
    {
        cin >> x;
        a.push_back({ x, i });
    }
    sort(a.begin(), a.end());
    ll res = 0;
    set<int>index;
    fori(i, 0, m)
    {
        res += a[i].first;
        index.insert(a[i].second);
    }
    ll cur = res;
    int ans = *index.rbegin() - *index.begin();
    int i = 1;
    while (cur == res && i + m < n)
    {
        //assert(cur + a[i + m].first < 2e18);
        cur = cur + a[i + m - 1].first - a[i - 1].first;
        if (cur == res)
        {
            index.erase(a[i-1].second);
            index.insert(a[i + m-1].second);
            ans = min(ans, *index.rbegin() - *index.begin());
        }
        i++;
    }
    assert(ans > 0);
    cout << ans + 1;
}