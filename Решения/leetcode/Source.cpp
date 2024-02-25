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


    ll mod = 1e9 + 7;
    ll x_ = 257;


    bool isEqual(const vector<long long>&h1, const vector<long long>& h2, const vector<long long>&x, int l1, int l2, int len)
    {
        //h[l1 + len - 1] - h[l1 - 1] * x[len] == h2[l2 + len - 1] - h2[l2 - 1] * x[len]
        return (h1[l1 + len - 1] + h2[l2 - 1] * x[len]) % mod ==
            (h2[l2 + len - 1] + h1[l1 - 1] * x[len]) % mod;
    }


    string longestPalindrome(string s) {
        int n = s.size();
        string s1 = s;
        s = s1[0];
        for (int i = 1; i < n; ++i)
        {
            s += "0";
            s += s1[i];
        }
        n = s.size();
        vector<long long>x(n + 1);
        x[0] = 1;
        vector<long long>h1(n + 1);
        vector<long long>h2(n + 1);
        for (int i = 0; i < n; ++i)
        {
            h1[i + 1] = (h1[i] * x_ + int(s[i])) % mod;
            h2[i + 1] = (h2[i] * x_ + int(s[n - i - 1])) % mod;
            x[i + 1] = x[i] * x_ % mod;
        }
        
        vector<int>num;
        for (int i = 1; i < 2e5 + 4; i += 2)
        {
            num.push_back(i);
        }
        int l = -1, r = n / 2 + 1, m;
        int res = 0, mid;
        while (r - l > 1)
        {
            mid = (r + l) / 2;
            m = num[mid];
            for (int i = 0; i <= n - m; ++i)
            {
                int l1 = i;
                int len = m / 2;
                if (isEqual(h1, h2, x, l1 + 1, n - (l1+m) + 1, len))
                {
                    l = mid;
                    if (s[i] != '0')
                        continue;
                    res = i;
                    break;
                }
            }
            if (l != mid)
                r = mid;
        }
        assert(l != -1);
        //return l;
        string ans = "";
        /*if (s[res] == '0')
        {
            res++;
            l--;
        }*/
        for (int i = res; i < res + num[l]; i+=2)
        {
            ans += s[i];
        }
        return ans;
    }
};

int main()
{
    useless;

    /*cout << int('A');
    return 0;*/
    Solution ans;
    str s; cin >> s;
    cout << ans.longestPalindrome(s);
}