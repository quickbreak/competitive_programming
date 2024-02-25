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

    int t, n, k;
    cin >> t;
    bool f = false;
    while (t--)
    {
        cin >> n;
        f = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                cout << n / i; cn;
                f = true;
                break;
            }
        }
        if (!f)
        {
            cout << 1; cn;
        }
    }
}