#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>

#define fori(it,a,b) for(int it=a;it<b;it++)
#define all(x) (x).begin(),(x).end()
#define cn cout << '\n'

using namespace std;

using ll = long long;
using str = string;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;


ll mod = 1000000007;


ll convert(str s, int b, int n)
{
    str alf = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    ll res = 0;
    ll pb = 1;
    fori(i, 0, n)
    {
        res = (res + (alf.find(s[n - i - 1]) * pb) % mod) % mod;
        pb = (pb * b) % mod;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t, n, b;
    str x, y;
    cin >> t;
    ll ans;
    while (t--)
    {
        ans = 0;
        cin >> n >> b;
        cin >> x >> y;
        ll l, r;
        l = convert(x, b, n);
        r = convert(y, b, n);
        //ans = (((l + r) * (r - l + 1 + mod)) % mod * (1 + mod) / 2) % mod;
        ans = (l + r);
        ans *= (r - l + 1 + mod);
        ans %= mod;
        ans *= (1 + mod) / 2;
        ans %= mod;
        cout << ans; cn;
    }
}
/*
1
10 62
1000000000
zzzzzzzzzz
*/