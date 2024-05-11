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


void f(vector<int>& a, int x)
{
    x = 0;
    a[0] = 0;
    cout << x; cn;
    cout << a[0]; cn;
}

class Solution {
public:
    int romanToInt(string s) {
        string alf = " IVXLCDM";
        map<string, int>mp = {
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
            {"CM", 900},
            {"XC", 90},
            {"XL", 40},
            {"CD", 400}
        };
        int n = s.size();
        s += " ";
        int i = 0;
        int res = 0;
        string key;
        while (i < n)
        {
            if (alf.find(s[i]) < alf.find(s[i + 1])) //IX
            {
                key = "";
                key += s[i];
                key += s[i + 1];
                res += mp[key];
                i++;
            }
            else
            {
                key = "";
                key += s[i];
                res += mp[key];
            }
            i++;
        }
        return res;
    }
};

int main()
{
    useless;

    Solution ans;
    str s; cin >> s;
    cout << ans.romanToInt(s);
}