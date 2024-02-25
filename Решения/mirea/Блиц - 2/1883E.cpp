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


    int t; cin >> t; 
    int n;
    vector<unsigned long long>d;
    d.push_back(1);
    fori(i, 1, 64)
    {
        d.push_back(d[i - 1] * 2);
    }
    while (t--)
    {
        cin >> n;
        unsigned long long x, last = 1;
        ll ans = 0;
        unsigned long long p;
        fori(i, 0, n)
        {
            cin >> x;
            if (x < last)
            {
                p = last / x + (last % x != 0);
                int uk = lower_bound(d.begin(), d.end(), p) - d.begin();
                ans += uk;
                last = x * d[uk];
            }
            else 
                last = x;
        }
        cout << ans; cn;
    }
}