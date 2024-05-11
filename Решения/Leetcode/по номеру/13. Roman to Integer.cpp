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


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m(7);

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ans += ((m[s[i]] < m[s[i + 1]]) ? -m[s[i]] : m[s[i]]);
        }
        return ans;
    }
};

int main()
{
    useless;

    Solution ans;
    str s; cin >> s;
    cout << ans.romanToInt(s);
}