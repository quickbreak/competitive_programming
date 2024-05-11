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
    vector<int>a;
    int x;
    fori(i, 0, n)
    {
        cin >> x;
        a.push_back(x);
    }
    int l, r;
    fori(j, 0, m)
    {
        cin >> l >> r;
        int max_el = -1;
        int min_el = 1000000;
        fori(i, l, r+1)
        {
            max_el = max(max_el, a[i]);
            min_el = min(min_el, a[i]);
        }
        if (max_el != min_el)
            cout << max_el << '\n';
        else cout << "NOT FOUND\n";
    }
}