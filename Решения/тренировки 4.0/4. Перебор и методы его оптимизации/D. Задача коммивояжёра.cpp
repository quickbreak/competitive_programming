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


int n;
vector<int>used(11);
vector<vector<int>>a(11, vector<int>(11));
vector<int>p(11);
ll ans = 1e18;
ll res = 0;


void gen(int pos)
{
    if (pos == n)
    {
        res = 0;
        fori(i, 1, n)
        {
            if (a[p[i]][p[i - 1]] != 0)
                res += a[p[i]][p[i - 1]];
            else return;
        }
        if (a[p[n - 1]][p[0]] != 0)
            res += a[p[n - 1]][p[0]];
        else return;
        ans = min(ans, res);
        return;
    }

    fori(x, 1, n)
    {
        if (used[x] == 0)
        {
            p[pos] = x;
            used[x] = 1;
            gen(pos + 1);
            used[x] = 0;

        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);


    cin >> n;

    fori(i, 0, n)
    {
        fori(j, 0, n)
        {
            cin >> a[i][j];
        }
    }
    if (n == 0)
    {
        cout << -1;
        return 0;
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    gen(1);
    cout << (ans != 0 && ans!=1e18 ? ans : -1);
}

