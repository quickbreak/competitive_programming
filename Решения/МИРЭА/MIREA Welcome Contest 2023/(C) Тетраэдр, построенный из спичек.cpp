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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << 6 * n * n; cn;
    }
}