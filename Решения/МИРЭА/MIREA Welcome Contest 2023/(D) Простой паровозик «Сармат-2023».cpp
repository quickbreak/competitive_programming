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


bool prime(int x)
{
    int res = 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            res++;
    }
    if (res == 0)
        return true;
    else return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (prime(n))
        {
            cout << n << ' ' << n; cn;
            continue;
        }
        int a, b;
        fori(i, n + 1, 1e9 + 8)
        {
            if (prime(i))
            {
                b = i;
                break;
            }
        }
        for (int i = n - 1; i >= 3; i--)
        {
            if (prime(i))
            {
                a = i;
                break;
            }
        }
        cout << a << ' ' << b; cn;
    }
}