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
#include<fstream>

#define fori(it, a, b) for(int it = a; it < b; ++it)
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

const ll mod = ll(1e9 + 7);

//base ^ p
ll binpow(ll base, ll p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return base;
    if (p % 2 == 0)
    {
        ll polovina = binpow(base, p / 2);
        return polovina * polovina % mod;
    }
    else
    {
        ll pminus = binpow(base, (p - 1) / 2);
        ll res = pminus * pminus % mod;
        return res * base % mod;
    }
}


int main()
{
    useless;
    //cout << int('A');
    int t; cin >> t;
    str s;
    while (t-- > 0)
    {
        cin >> s;
        int n = s.size();
        vector<int>small(n+1);
        vector<int>big(n+1);
        int uks = -1, ukb = -1;
        fori(i, 0, n)
        {
            if (s[i] == 'B')
            {
                s[i] = '0';
                if (ukb > -1)
                {
                    s[big[ukb--]] = '0';
                    //ukb--;
                }
            }
            else if (s[i] == 'b')
            {
                s[i] = '0';
                if (uks > -1)
                {
                    s[small[uks--]] = '0';
                    //uks--;
                }
            }
            else {
                if (s[i] >= 97) //small
                    small[++uks] = i;
                else
                {
                    big[++ukb] = i;
                }
            }
        }
        fori(i, 0, n)
        {
            if (s[i] != '0')
                cout << s[i];
        }
        cn;

    }
}