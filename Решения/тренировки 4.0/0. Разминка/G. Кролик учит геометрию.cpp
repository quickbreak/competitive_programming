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
    vector<vector<int>>a(n+1, vector<int>(m+1));
    fori(i, 1, n+1)
    {
        fori(j, 1, m+1)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>>d(n + 1, vector<int>(m + 1));
    d[1][1] = a[1][1];
    int ans = d[1][1];
    fori(i, 1, n + 1)
    {
        fori(j, 1, m + 1)
        {
            d[i][j] = (a[i][j]) * (min({ d[i - 1][j - 1], d[i - 1][j], d[i][j - 1] }) + 1);
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans;
}