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


    vector<ll>a;
    vector<ll>b;
    for (ll i = 2; i < 1e7; i++)
    {
        a.push_back(i * i);
    }
    for (ll i = 2; i < 1e5; i++)
    {
        b.push_back(i * i * i);
    }
    vector<ll>res(1e7 + 1);
    int l = 0, r = 0, uk = 2;
    res[1] = 1;
    int n = a.size();
    int m = b.size();
    while (uk < 1e7 + 1)
    {
        if (l < n)
        {
            if (r < m)
            {
                if (a[l] < b[r])
                {
                    if (a[l] > res[uk - 1])
                    {
                        res[uk] = a[l];
                        uk++;
                    }
                    l++;
                }
                else
                {
                    if (b[r] > res[uk - 1])
                    {
                        res[uk] = b[r];
                        uk++;
                    }
                    r++;
                }
            }
            else {
                while (uk < 1e7 + 1 && l < n)
                {
                    if (a[l] > res[uk])
                    {
                        res[uk] = a[l];
                        uk++;
                    }
                    l++;
                }
            }
        }
        else {
            while (uk < 1e7 + 1 && r < m)
            {
                if (b[r] > res[uk])
                {
                    res[uk] = b[r];
                    uk++;
                }
                r++;
            }
        }
    }
    int x;
    cin >> x;
    cout << res[x];
}

