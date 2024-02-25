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

    int k, n; cin >> k >> n;
    vector<int>a(n);
    fori(i, 0, n)
        cin >> a[i];

    int uk = n - 1;
    unsigned long long ans = 0;
    int ost = 0;
    while (uk >= 0 && uk < n)
    {
        if (ost > 0)
        {
            if (a[uk] >= ost)
            {
                a[uk] -= ost;
                ost = 0;
            }
            else {
                ost -= a[uk];
                a[uk] = 0;
                uk--;
            }
        }
        else {
            ans += 2LL * (uk + 1) * (a[uk] / k);
            ost = 1LL * (k - a[uk] % k) * (a[uk] % k != 0);
            if (ost > 0)
            {
                ans += 2 * (uk + 1);
            }
            uk--;
        }
    }
    cout << ans;
}